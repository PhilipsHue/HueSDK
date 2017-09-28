/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

private let showPushLinkScreenSegueIdentifier = "showPushLinkScreenSegue"
private let bridgeDiscoverySegueIdentifier = "showDiscoveryResultsSegue"
private let unwindToCancelPushLinkIdentifier = "unwindToCancelPushLink"
private let unwindToReloadBridgesIdentifier = "unwindToReloadBridges"
private let unwindToSelectBridgeIdentifier = "unwindToSelectBridge"

protocol SegueCoordinator {
    func coordinate(segue:UIStoryboardSegue, sender:Any?)
}

class HueQuickStartAppSegueCoordinator : SegueCoordinator, PHLightControlViewControllerSegueCoordinator, PHBridgeSelectionViewControllerSegueCoordinator, PHBridgePushLinkViewControllerSegueCoordinator {
    
    var lightControlViewControllerResults: [PHBridgeInfo]?
    var selectedBridge:PHBridgeInfo?
    var pushLinkCompletionBlock:PushLinkPresentingCompletionBlock?
    
    // MARK: LightControlViewController
    
    func lightControlViewController(_ controller: PHLightControlViewController, didGetBridgeDiscoveryResults results: [PHBridgeInfo]) {
        lightControlViewControllerResults = results
        controller.performSegue(withIdentifier: bridgeDiscoverySegueIdentifier, sender: controller)
    }
    
    func lightControlViewControllerNeedsPushLinkScreen(_ controller: PHLightControlViewController, withCompletionBlock completion: @escaping (Bool) -> ()) {
        pushLinkCompletionBlock = completion
        controller.performSegue(withIdentifier: showPushLinkScreenSegueIdentifier, sender: controller)
    }
    
    // MARK: BridgeSelectionViewController
    
    func bridgeSelectionController(_ controller: PHBridgeSelectionViewController, didSelectBridge bridge: PHBridgeInfo) {
        self.selectedBridge = bridge
        controller.performSegue(withIdentifier: unwindToSelectBridgeIdentifier, sender: controller)
    }
    
    func bridgeSelectionControllerDidRefreshBridges(_ controller: PHBridgeSelectionViewController) {
        controller.performSegue(withIdentifier: unwindToReloadBridgesIdentifier, sender: controller)
    }
    
    // MARK: PHBridgePushLinkViewControllerSegueCoordinator
    
    func bridgePushLinkViewControllerDidCancelPushlink(_ controller: PHBridgePushLinkViewController) {
        controller.performSegue(withIdentifier: unwindToCancelPushLinkIdentifier, sender: controller)
    }
    
    func coordinate(segue:UIStoryboardSegue, sender:Any?) {
        guard let segueIdentifier = segue.identifier else {
            return
        }
        
        switch segueIdentifier {
            case bridgeDiscoverySegueIdentifier:
                let destination:PHBridgeSelectionViewController = segue.destination as! PHBridgeSelectionViewController
                destination.bridgeList = lightControlViewControllerResults ?? []
                lightControlViewControllerResults = nil
            case showPushLinkScreenSegueIdentifier:         //Automatically handled, no params needed
                break
            case unwindToReloadBridgesIdentifier:           //Automatically handled, no params needed
                break
            case unwindToSelectBridgeIdentifier:
                let destination:PHLightControlViewController = segue.destination as! PHLightControlViewController
                destination.selectedBridge = selectedBridge ?? nil
                selectedBridge = nil
                break
            default: break
        }
    }
}


