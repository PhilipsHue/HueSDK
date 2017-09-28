/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <UIKit/UIKit.h>

#import <HueSDK/HueSDK.h>

#import "PHRootViewController.h"

@protocol PHBridgeSelectionViewControllerDelegate <NSObject>

- (void)bridgeSelectedWithIpAddress:(NSString *)ipAddress andUniqueId:(NSString *)andUniqueId;

- (void)refreshBridges;

@end

@interface PHBridgeSelectionViewController : UITableViewController

- (instancetype)initWithDiscoveredBridges:(NSDictionary<NSString *, PHSBridgeDiscoveryResult *> *)bridges andDelegate:(id<PHBridgeSelectionViewControllerDelegate>)delegate;


@end
