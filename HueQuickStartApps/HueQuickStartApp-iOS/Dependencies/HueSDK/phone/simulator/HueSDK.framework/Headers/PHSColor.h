/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

#import "PHSColorRGB.h"
#import "PHSColorHSV.h"
#import "PHSColorHSL.h"
#import "PHSColorXY.h"

@class PHSColorRGB;
@class PHSColorHSV;
@class PHSColorHSL;
@class PHSColorXY;


@interface PHSColor : PHSObject

/**
 The RGB Color representation of this color
 */
@property (strong, nonatomic, readonly) PHSColorRGB *rgb;

/**
 The HSV Color representation of this color
 */
@property (strong, nonatomic, readonly) PHSColorHSV *hsv;

/**
 The HSL Color representation of this color
 */
@property (strong, nonatomic, readonly) PHSColorHSL *hsl;

/**
 The XY Color representation of this color
 */
@property (strong, nonatomic, readonly) PHSColorXY *xy;

/**
 The Brightness value for this color
 */
@property (nonatomic, readonly) double brightness;

/**
 The Color Temperature value of this color in Kelvin
 */
@property (nonatomic, readonly) double ctKelvin;

/**
 The Color Temperature value of this color in Mired
 */
@property (nonatomic, readonly) double ctMired;

/**
 Initializer of this class
 @param rgb The RGB color object
 @param model The model of the lightpoint to convert for
 @param swVersion The software version of the lightpoint to convert for
 */
- (instancetype)initWithRGB:(PHSColorRGB *)rgb model:(NSString *)model swVersion:(NSString *) swVersion;

/**
 @param red   range 0 - 255
 @param green range 0 - 255
 @param blue  range 0 - 255
 */
+ (instancetype)createWithRed:(int)red green:(int)green blue:(int)blue;

/**
 Initializer of this class
 @param hsv The HSV color object
 @param model The model of the lightpoint to convert for
 @param swVersion The software version of the lightpoint to convert for
 */
- (instancetype)initWithHSV:(PHSColorHSV *)hsv model:(NSString *)model swVersion:(NSString *) swVersion;

/**
 @param hue value of a color, range 0 - 1
 @param sat value of a color, range 0 - 1
 @param val value of a color, range 0 - 1
 */
+ (instancetype)createWithHue:(double)hue saturation:(double)sat value:(double)val;

/**
 Initializer of this class
 @param hsl The HSL color object
 @param model The model of the lightpoint to convert for
 @param swVersion The software version of the lightpoint to convert for
 */
- (instancetype)initWithHSL:(PHSColorHSL *)hsl model:(NSString *)model swVersion:(NSString *) swVersion;

/**
 @param hue   value of a color, range 0 - 1
 @param sat   value of a color, range 0 - 1
 @param light value of a color, range 0 - 1
 */
+ (instancetype)createWithHue:(double)hue saturation:(double)sat lightness:(double)light;

/**
 Initializer of this class
 @param xy The XY color object
 @param brightness The brightness component for the color
 @param model The model of the lightpoint to convert for
 @param swVersion The software version of the lightpoint to convert for
 */
- (instancetype)initWithXY:(PHSColorXY *)xy brightness:(double)brightness model:(NSString *)model swVersion:(NSString *) swVersion;

/**
 @param x value of a color, range 0 - 1
 @param y value of a color, range 0 - 1
 */
+ (instancetype)createWithX:(double)x Y:(double)y brightness:(double)brightness;

/**
 Initializer of this class
 @param ct The color temperature value in Kelvin
 @param brightness The brightness component for the color
 @param model The model of the lightpoint to convert for
 @param swVersion The software version of the lightpoint to convert for
 */
- (instancetype)initWithCTKelvin:(double)ct brightness:(double)brightness model:(NSString *)model swVersion:(NSString *) swVersion;

/**
 CT The color temperature value in Kelvin 0 - 1
 */
+ (instancetype)createWithCTKelvin:(double)ct brightness:(double)brightness;

/**
 Initializer of this class
 @param ct The color temperature value in Mired
 @param brightness The brightness component for the color
 @param model The model of the lightpoint to convert for
 @param swVersion The software version of the lightpoint to convert for
 */
- (instancetype)initWithCTMired:(int)ct brightness:(double)brightness model:(NSString *)model swVersion:(NSString *) swVersion;

/**
 CT The color temperature value in Mired 0 - 1
 */
+ (instancetype)createWithCTMired:(double)ct brightness:(double)brightness ;

@end
