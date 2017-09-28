/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimePattern.h"

@interface PHSTimeIntervalPattern : PHSTimePattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The start time
 Only hour, minute and second components will be used
 */
@property (strong, nonatomic) NSDateComponents *startTime;

/**
 The end time
 Only hour, minute and second components will be used
 */
@property (strong, nonatomic) NSDateComponents *endTime;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param endTime the end time (only hour, minute and second components will be used)
 @return an instance of PHSTimeIntervalPattern with the given start time and end time set
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime endTime:(NSDateComponents *)endTime;

/**
 Shorthand factory method to create an instance of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @param endTime the end time (only hour, minute and second components will be used)
 @return an instance of PHSTimeIntervalPattern with the given start time and end time set
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime endTime:(NSDateComponents *)endTime;

@end
