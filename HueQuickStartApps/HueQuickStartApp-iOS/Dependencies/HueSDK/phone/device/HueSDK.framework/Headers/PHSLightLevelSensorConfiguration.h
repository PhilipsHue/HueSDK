/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSSensorConfiguration.h"

@interface PHSLightLevelSensorConfiguration : PHSSensorConfiguration

/**
 The dark offset
 */
@property (strong, nonatomic) NSNumber *thresholdDark;

/**
 The threshold offset for daylight
 The relative offset of the daylight threshold to the dark threshold
 */
@property (strong, nonatomic) NSNumber *thresholdOffset;

@end
