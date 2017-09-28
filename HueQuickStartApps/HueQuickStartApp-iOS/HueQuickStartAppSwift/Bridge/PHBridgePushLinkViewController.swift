/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

fileprivate struct PHPushLinkTimeConstants {
    static let TimeoutSec = 30.0
    static let TimerInterval = 1.0
}

protocol PHBridgePushLinkViewControllerSegueCoordinator : SegueCoordinator {
    func bridgePushLinkViewControllerDidCancelPushlink(_ controller:PHBridgePushLinkViewController)
}

class PHBridgePushLinkViewController : UIViewController, NavigationHelping {
    lazy var segueCoordinator: PHBridgePushLinkViewControllerSegueCoordinator = HueQuickStartAppSegueCoordinator()
    var completion:PushLinkPresentingCompletionBlock?
    var timeoutTimer:Timer?
    var remainingTime:TimeInterval?
    var timeoutAlertActive:Bool = false
    @IBOutlet var progressView:UIProgressView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        configureNavigation()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.startTimer()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        self.stopTimer()
        
        // dismiss alert
    }
}

private typealias PHBridgePushLinkViewControllerAlerts = PHBridgePushLinkViewController
extension PHBridgePushLinkViewControllerAlerts {
    func showTimeoutAlert() {
        self.present(timeoutAlert(), animated: true, completion: nil)
    }
    
    func timeoutAlert() -> UIAlertController {
        let couldNotConnectAlert:UIAlertController = UIAlertController(title: NSLocalizedString("Pushlink failed", comment:"Title alert when pushlink times out"),
                                                                       message: nil,
                                                                       preferredStyle:.alert)
        couldNotConnectAlert.addAction(alertActionForRetry())
        couldNotConnectAlert.addAction(alertActionForCancel())
        
        return couldNotConnectAlert
    }
    
    func alertActionForRetry() -> UIAlertAction {
        return UIAlertAction(title: NSLocalizedString("Retry", comment:"Retry button on pushlink timeout"),
                             style:.default,
                             handler: { [weak self] (action) in
                                if let strongSelf = self {
                                    strongSelf.timeoutAlertActive = false
                                    strongSelf.startTimer()
                                }
        })
    }
    
    func alertActionForCancel() -> UIAlertAction {
        return UIAlertAction(title: NSLocalizedString("Cancel", comment:"Cancel button on pushlink timeout"),
                             style:.default,
                             handler: { [weak self] (action) in
                                if let strongSelf = self {
                                    strongSelf.timeoutAlertActive = false
                                    strongSelf.stopTimer()
                                    strongSelf.segueCoordinator.bridgePushLinkViewControllerDidCancelPushlink(strongSelf)
                                }
        })
    }
}

private typealias PHBridgePushLinkViewControllerTimer = PHBridgePushLinkViewController
extension PHBridgePushLinkViewControllerTimer {
    func startTimer() {
        self.progressView?.progress = 1.0
        self.remainingTime = PHPushLinkTimeConstants.TimeoutSec
        self.timeoutTimer = Timer.scheduledTimer(timeInterval:PHPushLinkTimeConstants.TimerInterval,
                                                 target:self,
                                                 selector:#selector(updateProgress),
                                                 userInfo:nil,
                                                 repeats:true)
    }
    
    func stopTimer() {
        self.timeoutTimer?.invalidate()
    }
    
    @objc func updateProgress() {
        guard var remainingTime = self.remainingTime else {
            return
        }
        
        if remainingTime >= PHPushLinkTimeConstants.TimerInterval {
            remainingTime -= PHPushLinkTimeConstants.TimerInterval
        }
        
        self.progressView?.progress = Float(remainingTime/PHPushLinkTimeConstants.TimeoutSec)
        self.remainingTime = remainingTime
        
        if self.remainingTime == 0 {
            self.stopTimer()
            self.showTimeoutAlert()
        }
    }
}

private typealias PHBridgePushLinkViewControllerNavigable = PHBridgePushLinkViewController
extension PHBridgePushLinkViewControllerNavigable : NavigableController {
    var screenTitle: String {
        return ""
    }
    
    var backButtonHidden: Bool {
        return true
    }
    
    var navigationBarHidden: Bool {
        return true
    }
    
    var rightNavigationButton: UIBarButtonItem {
        return UIBarButtonItem()
    }
}
