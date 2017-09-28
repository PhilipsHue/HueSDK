/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"

@interface PHSBridgeDiscoveryResult : PHSObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The IP address of the discovered bridge
 */
@property (strong, nonatomic, readonly) NSString *ipAddress;

/**
 The unique id of the discovered bridge
 */
@property (strong, nonatomic, readonly) NSString *uniqueId;

@end
