/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

@interface PHSColorHSV : PHSObject

/**
 The hue of a color
 Range: 0 - 1
 */
@property (assign) double hue;

/**
 The saturation of a color
 Range: 0 - 1
 */
@property (assign) double saturation;

/**
 The value of a color
 Range: 0 - 1
 */
@property (assign) double value;

/**
 Initializer of this class, init all values with 0
 */
- (instancetype)init;

/**
 Initializer of this class
 @param hue value of a color, range 0 - 1
 @param sat value of a color, range 0 - 1
 @param val value of a color, range 0 - 1
 */
- (instancetype)initWithHue:(double)hue saturation:(double)sat value:(double)val;

@end
