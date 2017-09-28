/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation
import UIKit

protocol NavigationHelping {}
extension NavigationHelping where Self : UIViewController & NavigableController {
    func configureNavigation() {
        self.navigationController?.isNavigationBarHidden = self.navigationBarHidden
        self.navigationItem.hidesBackButton = self.backButtonHidden
        self.navigationItem.title = self.screenTitle
        self.navigationItem.rightBarButtonItem = rightNavigationButton
    }
}
