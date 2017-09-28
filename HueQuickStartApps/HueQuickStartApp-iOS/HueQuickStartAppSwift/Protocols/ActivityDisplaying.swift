/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol ActivityDisplaying {
    var activityIndicatorView:(UIView & ActivityStatusIndicator)? { get }
    func showLoadingWheel(show:Bool, message:String)
}

extension ActivityDisplaying {
    func showLoadingWheel(show:Bool, message:String) {
        activityIndicatorView?.isHidden = !show
        activityIndicatorView?.activityStatusMessage = message
        show ? activityIndicatorView?.startActivityIndicator() : activityIndicatorView?.stopActivityIndicator()
    }
}
