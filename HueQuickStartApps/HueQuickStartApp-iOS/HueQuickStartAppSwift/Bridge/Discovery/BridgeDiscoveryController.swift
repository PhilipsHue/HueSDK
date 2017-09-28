/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol PHBridgeDiscoveryControllerDelegate {
    func discoveryController(_ discoveryController:BridgeDiscoveryController, didFindBridges bridges:[PHBridgeInfo])
}

class BridgeDiscoveryController {
    let alertHandler:AlertPresenting?
    let activityIndicator:ActivityDisplaying?
    var inProgress:Bool
    var delegate:PHBridgeDiscoveryControllerDelegate?
    lazy var bridgeDiscovery:PHSBridgeDiscovery = PHSBridgeDiscovery()
    
    init(activityIndicator:ActivityDisplaying?, alertHandler:AlertPresenting?, delegate:PHBridgeDiscoveryControllerDelegate) {
        self.alertHandler = alertHandler
        self.activityIndicator = activityIndicator
        self.delegate = delegate
        
        self.inProgress = false
    }
    
    func discoverBridges() {
        if inProgress {
            return;
        }
        
        inProgress = true;
        
        let options:PHSBridgeDiscoveryOption = PHSBridgeDiscoveryOption.discoveryOptionUPNP;
        bridgeDiscovery.search(options) { [weak self] (results, returnCode) in
            guard let strongSelf = self else {
                return
            }
            
            strongSelf.activityIndicator?.showLoadingWheel(show: false, message: "")
            strongSelf.inProgress = false
            
            if let results = results {
                if results.count > 0 {
                    let foundBridges:[PHBridgeInfo] = results.map({ (key, value) in PHBridgeInfo(withDiscoveryResult: value) })
                    strongSelf.delegate?.discoveryController(strongSelf, didFindBridges:foundBridges)
                    return
                }
            }
            
            strongSelf.showNoBridgesFoundAlert()
        }
        
        showSearchInProgress()
    }
}

private typealias BridgeDiscoveryControllerAlerts = BridgeDiscoveryController
extension BridgeDiscoveryControllerAlerts {
    func showNoBridgesFoundAlert() {
        if let alertHandler = alertHandler {
            alertHandler.presentAlert(alert:noBridgesFoundAlert())
        }
    }
    
    func noBridgesFoundAlert() -> UIAlertController {
        let couldNotConnectAlert:UIAlertController = UIAlertController(title: NSLocalizedString("No bridges found", comment:"Title alert when no bridges found"),
                                                                       message: nil,
                                                                       preferredStyle:.alert)
        couldNotConnectAlert.addAction(alertActionForRetry())
        
        return couldNotConnectAlert
    }
    
    func alertActionForRetry() -> UIAlertAction {
        return UIAlertAction(title: NSLocalizedString("Retry", comment:"ry button on pushlink timeout"),
                             style:.default,
                             handler: { [weak self] (action) in
                                if let strongSelf = self {
                                    strongSelf.discoverBridges()
                                }
        })
    }
}

private typealias BridgeDiscoveryControllerActivityIndicator = BridgeDiscoveryController
extension BridgeDiscoveryControllerActivityIndicator {
    func showSearchInProgress() {
        if let activityIndicator = activityIndicator {
            activityIndicator.showLoadingWheel(show: true, message:NSLocalizedString("Searching for bridges", comment:"Discovery loading text"))
        }
    }
}
