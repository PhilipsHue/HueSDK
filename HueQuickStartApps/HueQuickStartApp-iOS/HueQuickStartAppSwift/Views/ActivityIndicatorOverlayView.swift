/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

fileprivate let defaultOverlayBackgroundColor:UIColor = UIColor(displayP3Red: 0.3, green: 0.3, blue: 0.3, alpha: 0.6)

@IBDesignable class ActivityIndicatorOverlayView : UIView, AutomaticNibLoading, ActivityStatusIndicator {
    @IBOutlet var activityIndicatorView:UIActivityIndicatorView?
    @IBOutlet var activityStatusLabel:UILabel?
    var activityStatusMessage:String? {
        didSet {
            activityStatusLabel?.text = activityStatusMessage
        }
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        backgroundColor = defaultOverlayBackgroundColor
    }
    
    func startActivityIndicator() {
        activityIndicatorView?.startAnimating()
    }
    
    func stopActivityIndicator() {
        activityIndicatorView?.stopAnimating()
    }
}
