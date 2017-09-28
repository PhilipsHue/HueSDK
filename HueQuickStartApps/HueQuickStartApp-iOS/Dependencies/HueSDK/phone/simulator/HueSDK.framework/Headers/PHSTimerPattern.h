/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimePattern.h"

@interface PHSTimerPattern : PHSTimePattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The start time
 Only minute, hour and second components will be used
 */
@property (strong, nonatomic) NSDateComponents *startTime;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @return an instance of PHSTimerPattern with the given start time set
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime;

/**
 Shorthand factory method to create an instance of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @return an instance of PHSTimerPattern with the given start time set
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime;

@end
