/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <HueSDK/HueSDK.h>

#import "PHBridgePushLinkViewController.h"
#import "PHBridgeInfo.h"
#import "PHRootViewController.h"

@protocol PHBridgeControllerDelegate

@required

- (void)connected;
- (void)disconnected;

@end

@interface PHBridgeController : NSObject<PHSBridgeConnectionObserver, PHSBridgeStateUpdateObserver, PHBridgePushLinkViewControllerDelegate>

@property (nonatomic, strong, readonly) PHSBridge* bridge;

@property (nonatomic, weak) id<PHBridgeControllerDelegate> delegate;

- (instancetype)initWithBridgeInfo:(PHBridgeInfo *)bridgeInfo andRootViewController:(PHRootViewController *)rootViewController andDelegate:(id<PHBridgeControllerDelegate>)delegate;

- (void)connect;
- (void)disconnect;

@end
