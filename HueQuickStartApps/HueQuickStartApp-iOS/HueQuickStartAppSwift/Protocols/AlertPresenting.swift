/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol AlertPresenting {
    func presentAlert(alert:UIAlertController)
    func dismissAlerts()
}

extension AlertPresenting where Self : UIViewController {
    func presentAlert(alert:UIAlertController) {
        dismissAlerts()
        self.present(alert, animated: true, completion: nil)
    }
    
    func dismissAlerts() {
        self.presentedViewController?.dismiss(animated: true, completion: nil)
    }
}
