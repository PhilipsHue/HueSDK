/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <UIKit/UIKit.h>

#import "PHRootViewController.h"

@protocol PHBridgePushLinkViewControllerDelegate <NSObject, UIAlertViewDelegate>

@required

- (void)pushlinkCancelled;

@end

@interface PHBridgePushLinkViewController : UIViewController

- (instancetype)initWithRootViewController:(PHRootViewController *)rootViewController andDelegate:(id<PHBridgePushLinkViewControllerDelegate>)delegate;

@end
