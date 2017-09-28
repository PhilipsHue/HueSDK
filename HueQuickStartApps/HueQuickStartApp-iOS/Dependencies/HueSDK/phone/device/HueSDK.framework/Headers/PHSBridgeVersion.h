/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"
#import "PHSDomainObject.h"

@interface PHSBridgeVersion : PHSDomainObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The firmware version of this bridge
 */
@property (strong, nonatomic, readonly) NSString *firmwareVersion;

/**
 The CLIP version of this bridge
 */
@property (strong, nonatomic, readonly) NSString *clipVersion;

/**
 The data store version of this bridge
 */
@property (strong, nonatomic, readonly) NSString *datastoreVersion;

@end
