/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"

@class PHSAbsoluteTimePattern;

@interface PHSBridgeTimeConfiguration : PHSDomainObject

/**
 The date/time setting of the bridge (UTC)
 */
@property (strong, nonatomic) PHSAbsoluteTimePattern *time;

/**
 The date/time setting of the bridge (Local time)
 */
@property (nonatomic, strong, readonly) PHSAbsoluteTimePattern *localTime;

/**
 The timezone setting of the bridge
 */
@property (strong, nonatomic) NSString *timeZone;

@end
