/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeResource.h"

@interface PHSWhitelistEntry : PHSBridgeResource

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The username
 */
@property (strong, nonatomic, readonly) NSString *userName;

/**
 The appname
 */
@property (strong, nonatomic, readonly) NSString *appName;

/**
 The device type
 */
@property (strong, nonatomic, readonly) NSString *deviceName;

/**
 The creation date
 */
@property (strong, nonatomic, readonly) NSDate *creationDate;

/**
 The date the entry was last used
 */
@property (strong, nonatomic, readonly) NSDate *lastUsedDate;

@end
