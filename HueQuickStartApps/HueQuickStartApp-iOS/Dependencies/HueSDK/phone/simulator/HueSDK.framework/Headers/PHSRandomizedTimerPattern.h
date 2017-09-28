/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimerPattern.h"

@interface PHSRandomizedTimerPattern : PHSTimerPattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The random element which is added to the start date time
 Only hour, minute and second components are used
 */
@property (strong, nonatomic) NSDateComponents *randomElement;

/**
 Initializer of this class
 @param startTime     the start time (only hour, minute and second components will be used)
 @param randomElement the random element which is added to the start date time (only hour, minute and second components are used)
 @return an instance of PHSRandomizedTimePattern with the given start date set and random element set
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime randomElement:(NSDateComponents *)randomElement;

/**
 Shorthand factory method to create an instance of this class
 @param startTime     the start time (only hour, minute and second components will be used)
 @param randomElement the random element which is added to the start date time (only hour, minute and second components are used)
 @return an instance of PHSRandomizedTimePattern with the given start date and random element set
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime randomElement:(NSDateComponents *)randomElement;

@end
