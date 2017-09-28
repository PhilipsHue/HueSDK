/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

@interface PHSKnownBridge : NSObject

@property (strong, nonatomic, readonly) NSString *uniqueId;
@property (strong, nonatomic, readonly) NSString *ipAddress;
@property (strong, nonatomic, readonly) NSString *name;
@property (strong, nonatomic, readonly) NSDate   *firstConnected;
@property (strong, nonatomic, readonly) NSDate   *lastConnected;

@end
