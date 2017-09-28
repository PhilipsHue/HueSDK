/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorConfiguration.h"

@interface PHSDaylightSensorConfiguration : PHSSensorConfiguration

/**
 Set the longitude, in decimal degrees DDD.DDDD{W|E}
 */
- (void)setLongitude:(NSString *)longitude;

/**
 Set the latitude, in decimal degrees DDD.DDDD{N|S}
 */
- (void)setLatitude:(NSString *)latitude;

/**
 Timeoffset in minutes to sunrise
 Range: -120 min..120 min
 */
@property (strong, nonatomic) NSNumber *sunriseOffset;

/**
 Timeoffset in minutes to sunset
 Range: -120 min..120 min
 */
@property (strong, nonatomic) NSNumber *sunsetOffset;

/**
 Configured flag. True if the valid GPS coordinates have been set
 */
@property (assign, nonatomic, readonly) NSNumber *configured;

@end
