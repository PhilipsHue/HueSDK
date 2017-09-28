/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <UIKit/UIKit.h>

#import "PHBridgeController.h"
#import "PHBridgeDiscoveryController.h"
#import "PHRootViewController.h"

@interface PHLightControlViewController : UIViewController<PHBridgeControllerDelegate, PHBridgeDiscoveryControllerDelegate>

- (instancetype)initWithRootViewController:(PHRootViewController *)rootViewController;

@end
