/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

@interface PHSColorRGB : PHSObject

/**
 The red value of a color
 Range: 0 - 255
 */
@property (assign) int red;

/**
 The green value of a color
 Range: 0 - 255
 */
@property (assign) int green;

/**
 The blue value of a color
 Range: 0 - 255
 */
@property (assign) int blue;

/**
 Initializer of this class, init all values with 0
 */
- (instancetype)init;

/**
 Initializer of this class
 @param red value of a color, range 0 - 255
 @param green value of a color, range 0 - 255
 @param blue value of a color, range 0 - 255
 */
- (instancetype)initWithRed:(int)red green:(int)green blue:(int)blue;

@end
