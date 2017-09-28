/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

class PHNavigationController : UINavigationController, ActivityDisplaying, AlertPresenting {    
    var activityIndicatorView: (UIView & ActivityStatusIndicator)?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        configureActivityIndicatorView()
    }
    
    func configureActivityIndicatorView() {
        activityIndicatorView = ActivityIndicatorOverlayView.loadFromNib()
        
        guard let activityIndicatorView = activityIndicatorView else {
            return
        }
        
        self.view.addSubview(activityIndicatorView)
        activityIndicatorView.translatesAutoresizingMaskIntoConstraints = false
        
        let leadingConstraint:NSLayoutConstraint = NSLayoutConstraint(item:self.view,
                                                                      attribute:.leading,
                                                                      relatedBy:.equal,
                                                                      toItem:activityIndicatorView,
                                                                      attribute:.leading,
                                                                      multiplier: 1,
                                                                      constant: 0)
        
        let trailingConstraint:NSLayoutConstraint = NSLayoutConstraint(item:self.view,
                                                                       attribute:.trailing,
                                                                       relatedBy:.equal,
                                                                       toItem:activityIndicatorView,
                                                                       attribute:.trailing,
                                                                       multiplier: 1,
                                                                       constant: 0)
        
        let widthConstraint:NSLayoutConstraint = NSLayoutConstraint(item:self.view,
                                                                    attribute:.width,
                                                                    relatedBy:.equal,
                                                                    toItem:activityIndicatorView,
                                                                    attribute:.width,
                                                                    multiplier: 1,
                                                                    constant: 0)
        
        let heightConstraint:NSLayoutConstraint = NSLayoutConstraint(item:self.view,
                                                                    attribute:.height,
                                                                    relatedBy:.equal,
                                                                    toItem:activityIndicatorView,
                                                                    attribute:.height,
                                                                    multiplier: 1,
                                                                    constant: 0)
        
        heightConstraint.isActive = true
        widthConstraint.isActive = true
        leadingConstraint.isActive = true
        trailingConstraint.isActive = true
        
        activityIndicatorView.isHidden = true
    }
}
