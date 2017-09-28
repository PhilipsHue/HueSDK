/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSTimePattern.h"

@interface PHSTruncatedTimePattern : PHSTimePattern

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The start time
 Only hour, minute and second components will be used
 */
@property (strong, nonatomic) NSDateComponents *startTime;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @return an instance of PHSTruncatedTimePattern with the given start time
 */
- (instancetype)initWithStartTime:(NSDateComponents *)startTime;

/**
 Initializer of this class
 @param startTime the start time (only hour, minute and second components will be used)
 @return an instance of PHSTruncatedTimePattern with the given start time
 */
+ (instancetype)patternWithStartTime:(NSDateComponents *)startTime;

@end
