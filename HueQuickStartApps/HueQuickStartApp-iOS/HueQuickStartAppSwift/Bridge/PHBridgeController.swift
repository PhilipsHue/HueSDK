/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol PHBridgeControllerDelegate {
    func connected()
    func disconnected()
}

class PHBridgeController : NSObject {
    let alertHandler:AlertPresenting?
    let pushLinkHandler:PushLinkPresenting?
    let activityIndicator:ActivityDisplaying?
    var delegate:PHBridgeControllerDelegate?
    
    var lastConnectionEvent:PHSBridgeConnectionEvent
    var canConnect:Bool
    
    let bridgeInfo:PHBridgeInfo
    lazy var bridge:PHSBridge = {
        return buildBridge(info:bridgeInfo)
    }()
    
    init?(bridgeInfo:PHBridgeInfo?, activityIndicator:ActivityDisplaying?, alertHandler:AlertPresenting?, pushLinkHandler:PushLinkPresenting?, delegate:PHBridgeControllerDelegate) {
        guard let bridgeInfo = bridgeInfo else {
            return nil
        }
        
        self.bridgeInfo = bridgeInfo
        self.alertHandler = alertHandler
        self.pushLinkHandler = pushLinkHandler
        self.activityIndicator = activityIndicator
        self.delegate = delegate
        
        self.canConnect = true
        self.lastConnectionEvent = .none
        
        super.init()
    }
    
    func buildBridge(info:PHBridgeInfo) -> PHSBridge {
        // Replace app name and device name
        return PHSBridge.init(block: { (builder) in
            builder?.connectionTypes = .local
            builder?.ipAddress = info.ipAddress
            builder?.bridgeID  = info.uniqueId
            
            builder?.bridgeConnectionObserver = self
            builder?.add(self)
        }, withAppName: "MyApp", withDeviceName: "MyDevice")
    }
    
    func connect () {
        if canConnect {
            showConnecting()
            bridge.connect()
        }
    }
    
    func disconnect() {
        bridge.disconnect()
    }
    
    func startHeartBeat() {
        if let connection:PHSBridgeConnection = self.bridge.bridgeConnections().first {
            connection.heartbeatManager.startHeartbeat(with:.fullConfig, interval: 10)
        }
    }
    
    func dismissAll() {
        alertHandler?.dismissAlerts()
        pushLinkHandler?.dismissPushLinkScreen()
        activityIndicator?.showLoadingWheel(show: false, message: "")
    }
}

private typealias PHBridgeControllerAlerts = PHBridgeController
extension PHBridgeControllerAlerts {
    func showCouldNotConnectAlert() {
        if let alertHandler = alertHandler {
            alertHandler.presentAlert(alert:couldNotConnectAlert())
        }
    }
    
    func couldNotConnectAlert() -> UIAlertController {
        let couldNotConnectAlert:UIAlertController = UIAlertController(title: NSLocalizedString("Could not connect", comment:"Title alert when couldn't connect to bridge"),
                                                                       message: nil,
                                                                       preferredStyle:.alert)
        couldNotConnectAlert.addAction(alertActionForRetry())
        couldNotConnectAlert.addAction(alertActionForCancel())
        
        return couldNotConnectAlert
    }
    
    func alertActionForRetry() -> UIAlertAction {
        return UIAlertAction(title: NSLocalizedString("Retry", comment:"Retry button on could not connect alert"),
                             style:.default,
                             handler: { [weak self] (action) in
                                if let strongSelf = self {
                                    strongSelf.connect()
                                }
        })
    }
    
    func alertActionForCancel() -> UIAlertAction {
        return UIAlertAction(title: NSLocalizedString("Cancel", comment:"Cancel button on could not connect alert"),
                             style:.default,
                             handler: { [weak self] (action) in
                                if let strongSelf = self {
                                    strongSelf.delegate?.disconnected()
                                }
        })
    }
}

private typealias PHBridgeControllerActivityIndicator = PHBridgeController
extension PHBridgeControllerActivityIndicator {
    func showConnecting() {
        if let activityIndicator = activityIndicator {
            activityIndicator.showLoadingWheel(show: true, message:NSLocalizedString("Connecting", comment:"Connecting title on loading screen"))
        }
    }
    
    func showConnectionLost() {
        if let activityIndicator = activityIndicator {
            activityIndicator.showLoadingWheel(show: true, message:NSLocalizedString("Reconnecting", comment:"Reconnecting title on loading screen"))
        }
    }
}

private typealias PHBridgeControllerEvents = PHBridgeController
extension PHBridgeControllerEvents {
    func handleConnectionLostEvent() {
        showConnectionLost()
    }
    
    func handleConnectionRestoredEvent() {
        dismissAll()
    }
    
    func handleDisconnectedEvent() {
        self.canConnect = true
        
        // Disconnected event is sent directly after PHSBridgeConnectionEventCouldNotConnect, but user should decide to retry before informing delegate
        if lastConnectionEvent != .couldNotConnect {
            delegate?.disconnected()
        }
    }
    
    func handlePushLinkEvent() {
        if lastConnectionEvent != .notAuthenticated && lastConnectionEvent != .linkButtonNotPressed {
            self.dismissAll()
            pushLinkHandler?.presentPushLinkScreen(completion: { [weak self] (success) in
                if !success {
                    if let strongSelf = self {
                        strongSelf.bridge.disconnect()
                    }
                }
            })
        }
    }
    
    func handleAuthenticationEvent() {
        dismissAll()
    }
}

private typealias PHBridgeConnectionObserverConformance = PHBridgeController
extension PHBridgeConnectionObserverConformance : PHSBridgeConnectionObserver {
    func bridgeConnection(_ bridgeConnection: PHSBridgeConnection!, handle connectionEvent: PHSBridgeConnectionEvent) {
        switch connectionEvent {
        case .couldNotConnect:
            showCouldNotConnectAlert()
        case .connected:
            // Inform delegate only when also authenticated
            break
        case .connectionLost:
            handleConnectionLostEvent()
        case .connectionRestored:
            handleConnectionRestoredEvent()
        case .disconnected:
            handleDisconnectedEvent()
        case .notAuthenticated:
            fallthrough
        case .linkButtonNotPressed:
            handlePushLinkEvent()
        case .authenticated:
            handleAuthenticationEvent()
        default:
            break
        }
        
        self.lastConnectionEvent = connectionEvent;
    }
    
    func bridgeConnection(_ bridgeConnection: PHSBridgeConnection!, handleErrors connectionErrors: [PHSError]!) {
        
    }
}

private typealias PHBridgeStateUpdateObserverConformance = PHBridgeController
extension PHBridgeStateUpdateObserverConformance : PHSBridgeStateUpdateObserver {
    func bridge(_ bridge: PHSBridge!, handle updateEvent: PHSBridgeStateUpdatedEvent) {
        if updateEvent == .initialized {
            self.delegate?.connected()
            startHeartBeat()
        }
    }
}
