/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol ActivityStatusIndicator : class {
    var activityStatusMessage:String? { get set }
    
    func startActivityIndicator()
    func stopActivityIndicator()
}
