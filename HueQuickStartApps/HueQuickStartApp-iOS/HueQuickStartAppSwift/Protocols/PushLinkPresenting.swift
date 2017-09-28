/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

import Foundation

typealias PushLinkPresentingCompletionBlock = (_ success:Bool) -> ()

protocol PushLinkPresenting {
    func presentPushLinkScreen(completion:@escaping PushLinkPresentingCompletionBlock)
    func dismissPushLinkScreen()
}
