/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "PHRootViewController.h"
#import "PHBridgeSelectionViewController.h"

@protocol PHBridgeDiscoveryControllerDelegate

@required

- (void)bridgeSelectedWithIpAddress:(NSString *)ipAddress andUniqueId:(NSString *)uniqueId;

@end

@interface PHBridgeDiscoveryController : NSObject<PHBridgeSelectionViewControllerDelegate>

- (instancetype)initWithRootViewController:(PHRootViewController *)rootViewController andDelegate:(id<PHBridgeDiscoveryControllerDelegate>)delegate;

- (void)discoverBridges;

@end
