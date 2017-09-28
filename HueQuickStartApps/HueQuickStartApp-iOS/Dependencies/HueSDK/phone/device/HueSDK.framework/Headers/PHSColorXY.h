/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

@interface PHSColorXY : PHSObject

/**
 The x of a color
 Range: 0 - 1
 */
@property (assign) double x;

/**
 The y of a color
 Range: 0 - 1
 */
@property (assign) double y;

/**
 Initializer of this class, init all values with 0
 */
- (instancetype)init;

/**
 Initializer of this class
 @param x value of a color, range 0 - 1
 @param y value of a color, range 0 - 1
 */
- (instancetype)initWithX:(double)x Y:(double)y;

@end
