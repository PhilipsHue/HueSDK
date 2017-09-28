/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import UIKit
import Foundation

struct PHConstants {
    static let PHMaxHue = 65535
    static let PHMaxBri = 254
}

protocol PHLightControlViewControllerSegueCoordinator : SegueCoordinator {
    func lightControlViewController(_ controller:PHLightControlViewController, didGetBridgeDiscoveryResults results:[PHBridgeInfo])
    func lightControlViewControllerNeedsPushLinkScreen(_ controller:PHLightControlViewController, withCompletionBlock completion:@escaping PushLinkPresentingCompletionBlock)
}

class PHLightControlViewController: UIViewController, NavigationHelping {
    @IBOutlet weak var ipAddressLabel:UILabel?
    @IBOutlet weak var uniqueIdLabel:UILabel?
    
    lazy var segueCoordinator: PHLightControlViewControllerSegueCoordinator = HueQuickStartAppSegueCoordinator()
    var selectedBridge:PHBridgeInfo?
    var isStartingUp:Bool = true
    
    var activityIndicator:ActivityDisplaying? {
        get {
            return self.navigationController as? ActivityDisplaying ?? nil
        }
    }
    var alertHandler:AlertPresenting? {
        get {
            return self.navigationController as? AlertPresenting ?? nil
        }
    }
    lazy var bridgeDiscoveryController = {
        return BridgeDiscoveryController(activityIndicator:self.activityIndicator, alertHandler:self.alertHandler, delegate:self)
    }()
    
    var bridgeController:PHBridgeController?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        configureNavigation()
        
        bridgeController = PHBridgeController(bridgeInfo: self.lastConnectedBridge,
                                              activityIndicator: activityIndicator,
                                              alertHandler: alertHandler,
                                              pushLinkHandler: self,
                                              delegate: self)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if let bridgeController = self.bridgeController {
            if self.isStartingUp {
                bridgeController.connect()
            }
        } else {
            self.discoverBridges()
        }
        
        self.isStartingUp = false
    }
    
    func discoverBridges() {
        self.bridgeDiscoveryController.discoverBridges()
    }
    
    var lastConnectedBridge:PHBridgeInfo? {
        get {
            if let lastConnectedBridge:PHSKnownBridge = PHSKnownBridge.lastConnectedBridge {
                let bridge = PHBridgeInfo(ipAddress: lastConnectedBridge.ipAddress, uniqueId: lastConnectedBridge.uniqueId)
                
                return bridge
            }
            
            return nil;
        }
    }
    
    @IBAction func randomizeLightButtonAction() {
        self.randomizeColors()
    }
    
    @IBAction func findNewBridgeButtonAction() {
        self.discoverBridges()
    }
    
    func showBridgeDiscoveryResults(results:[PHBridgeInfo]) {
        self.segueCoordinator.lightControlViewController(self, didGetBridgeDiscoveryResults: results)
    }
}

private typealias PHLightControlViewControllerSegueHandling = PHLightControlViewController
extension PHLightControlViewControllerSegueHandling {
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        self.segueCoordinator.coordinate(segue:segue, sender:sender)
    }
    
    @IBAction func unwindToCancelPushLink(segue:UIStoryboardSegue) {
        self.bridgeController?.disconnect()
    }
    
    @IBAction func unwindToReloadBridges(segue:UIStoryboardSegue) {
        self.discoverBridges()
    }
    
    @IBAction func unwindToSelectBridge(segue:UIStoryboardSegue) {
        guard let selectedBridge = self.selectedBridge else {
            return
        }
        
        self.bridgeController?.delegate = nil
        self.bridgeController?.disconnect()
        
        self.bridgeController = PHBridgeController(bridgeInfo: selectedBridge,
                                                   activityIndicator: activityIndicator,
                                                   alertHandler: alertHandler,
                                                   pushLinkHandler: self,
                                                   delegate: self)
        self.bridgeController?.connect()
    }
}

private typealias PHLightControlViewControllerPushLinkPresenting = PHLightControlViewController
extension PHLightControlViewControllerPushLinkPresenting : PushLinkPresenting {
    func presentPushLinkScreen(completion: @escaping (Bool) -> ()) {
        self.segueCoordinator.lightControlViewControllerNeedsPushLinkScreen(self, withCompletionBlock:completion)
    }
    
    func dismissPushLinkScreen() {
        self.dismiss(animated: true, completion: nil)
    }
}

private typealias PHLightControlViewControllerLightControls = PHLightControlViewController
extension PHLightControlViewControllerLightControls {
    func randomizeColors() {
        if let devices:[PHSDevice] = self.bridgeController?.bridge.bridgeState.getDevicesOf(.light) as? [PHSDevice] {
            for device in devices {
                if let lightPoint:PHSLightPoint = device as? PHSLightPoint {
                    let lightState:PHSLightState = self.lightStateWithRandomColors()
                    
                    lightPoint.update(lightState, allowedConnectionTypes: .local, completionHandler: { (responses, errors, returnCode) in
                        // ...
                    })
                }
            }
        }
    }
    
    func lightStateWithRandomColors() -> PHSLightState {
        let lightState:PHSLightState = PHSLightState()
        
        lightState.on = true
        lightState.hue = Int(arc4random_uniform(UInt32(PHConstants.PHMaxHue))) as NSNumber
        lightState.brightness = Int(arc4random_uniform(UInt32(PHConstants.PHMaxBri))) as NSNumber
        
        return lightState
    }
}

private typealias PHLightControlViewControllerNavigable = PHLightControlViewController
extension PHLightControlViewControllerNavigable : NavigableController {
    var screenTitle: String {
        return NSLocalizedString("HueQuickStartApp", comment:"Title navigation light control screen")
    }
    
    var backButtonHidden: Bool {
        return false
    }
    
    var navigationBarHidden: Bool {
        return false
    }
    
    var rightNavigationButton: UIBarButtonItem {
        return UIBarButtonItem(title: NSLocalizedString("Find bridge", comment:"Find bridge button in bar on light control screen"),
                               style: .plain,
                               target: self,
                               action: #selector(findNewBridgeButtonAction))
    }
}

typealias PHLightControlViewControllerBridgeControllerDelegate = PHLightControlViewController
extension PHLightControlViewControllerBridgeControllerDelegate : PHBridgeControllerDelegate {
    func connected() {
        self.ipAddressLabel!.text = self.bridgeController?.bridge.bridgeConfiguration.networkConfiguration.ipAddress
        self.uniqueIdLabel!.text = self.bridgeController?.bridge.identifier
    }
    
    func disconnected() {
        self.ipAddressLabel?.text = NSLocalizedString("Not connected", comment:"Not Connected");
        self.uniqueIdLabel?.text = NSLocalizedString("Not connected", comment:"Not Connected");
        
        self.bridgeController?.delegate = nil
        self.discoverBridges()
    }
}

typealias PHLightControlViewControllerBridgeDiscoveryControllerDelegate = PHLightControlViewController
extension PHLightControlViewControllerBridgeDiscoveryControllerDelegate : PHBridgeDiscoveryControllerDelegate {
    func discoveryController(_ discoveryController: BridgeDiscoveryController, didFindBridges bridges: [PHBridgeInfo]) {
        self.showBridgeDiscoveryResults(results: bridges)
    }
}
