/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSAbsoluteTimePattern.h"

@interface PHSRandomizedTimePattern : PHSAbsoluteTimePattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The random element which is added to the start date time 
 Only hour, minute and second components are used
 */
@property (strong, nonatomic) NSDateComponents *randomElement;

/**
 Initializer of this class
 @param startDateTime the start date (only day, month, year, hour, minute and second components will be used)
 @param randomElement the random element which is added to the start date time (only hour, minute and second components are used)
 @return an instance of PHSRandomizedTimePattern with the given start date set and random element set
 */
- (instancetype)initWithStartDateTime:(NSDateComponents *)startDateTime randomElement:(NSDateComponents *)randomElement;

/**
 Shorthand factory method to create an instance of this class
 @param startDateTime the start date (only day, month, year, hour, minute and second components will be used)
 @param randomElement the random element which is added to the start date time (only hour, minute and second components are used)
 @return an instance of PHSRandomizedTimePattern with the given start date and random element set
 */
+ (instancetype)patternWithStartDateTime:(NSDateComponents *)startDateTime randomElement:(NSDateComponents *)randomElement;

@end
