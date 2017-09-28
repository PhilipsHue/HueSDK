/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol NavigableController : class {
    var screenTitle:String { get }
    var backButtonHidden:Bool { get }
    var navigationBarHidden:Bool { get }
    var rightNavigationButton:UIBarButtonItem { get }
}
