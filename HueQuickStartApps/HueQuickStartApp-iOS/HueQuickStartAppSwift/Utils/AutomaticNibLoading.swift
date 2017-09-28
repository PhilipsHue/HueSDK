/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol AutomaticNibLoading {}

extension AutomaticNibLoading where Self : UIView {
    static func loadFromNib() -> Self {
        let nibName = String(describing: type(of: self)).components(separatedBy: ".").first ?? ""
        let nib = UINib(nibName: nibName, bundle: nil)
        
        return nib.instantiate(withOwner: self, options: nil).first as! Self
    }
}
