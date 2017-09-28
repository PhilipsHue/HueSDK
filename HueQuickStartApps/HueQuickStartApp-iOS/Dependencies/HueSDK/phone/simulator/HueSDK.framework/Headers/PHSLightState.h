/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSDeviceState.h"
#import "PHSAlertMode.h"
#import "PHSLightEffectMode.h"
#import "PHSLightColorMode.h"
#import "PHSColor.h"
#import "PHSLightMode.h"

@class PHSNumberPair;
@class PHSColor;

@interface PHSLightState : PHSDeviceState

/**
 The brightness to set the light to.
 Range: 0 (lowest brightness, but not off) to 254 (highest brightness).
 */
@property (strong, nonatomic) NSNumber *brightness;

/**
 The light brightness increment value (negative means decrease)
 Range: [-254..254]
 */
@property (strong, nonatomic) NSNumber *brightnessIncrement;

/**
 The hue to set the light to, representing a color.
 Range: 0 - 65535 (which represents 0-360 degrees)
 Explanation: http://en.wikipedia.org/wiki/Hue
 */
@property (strong, nonatomic) NSNumber *hue;

/**
 The hue increment value (negative means decrease)
 Range: [-65534..65534]
 */
@property (strong, nonatomic) NSNumber *hueIncrement;

/**
 The saturation to set the light to.
 Range: 0 (least saturated, white) - 254 (most saturated, vivid).
 */
@property (strong, nonatomic) NSNumber *saturation;

/**
 The saturation increment value (negative means decrease)
 Range: [-254..254]
 */
@property (strong, nonatomic) NSNumber *saturationIncrement;

/**
 The color temperature to set the light to in Mirek
 Range of 2012 hue bulb: 153 (coldest white) - 500 (warmest white)
 Explanation: http://en.wikipedia.org/wiki/Mired
 */
@property (strong, nonatomic) NSNumber *ct;

/**
 The color temperature increment value (negative means decrease)
Range: [-65534..65534]
 */
@property (strong, nonatomic) NSNumber *ctIncrement;

/**
 The x and y value of a color represented by the CIE 1931 color space
 Range for each value: 0.0 - 1.0
 Explanation: http://en.wikipedia.org/wiki/CIE_1931_color_space
 */
@property (strong, nonatomic) PHSNumberPair *xyColor;

/**
 The x and y increment value
 Range for each value: [-1.0..1.0]
 */
@property (strong, nonatomic) PHSNumberPair *xyColorIncrement;

/**
 The alert to set the light to.
 Options: "none" (no alert), "select" (1 breath cycle), "lselect" (breathes for 30 seconds or until value none is set)
 */
@property (assign, nonatomic) PHSAlertMode alert;

/**
 The effect to set the light to
 Options: "none" (no effect), "colorloop" (starts a colorloop with the current saturation and brightness until value none is set)
 */
@property (assign, nonatomic) PHSLightEffectMode effect;

/**
 Get the color object, representing the current color of this lightstate
 */
@property (strong, nonatomic, readonly) PHSColor *color;

/**
 Colormode of this light.
 Readonly value.
 Values:
 - "HS": color is set by hue + saturation
 - "CT": color is set by ct value
 - "XY": color is set by xy values
 */
@property (assign, nonatomic, readonly) PHSLightColorMode colorMode;

/**
 PHSLightModeHomeAutomation: Device can be controlled by updating /state, light output is reflected in /state
 PHSLightModeStreaming: Device is in use by a streaming application and cannot be controlled by updating
 /state and light output is not reflected in /state
 */
@property (assign, nonatomic, readonly) PHSLightMode lightMode;

/**
 The transition to take to go to this state in 100ms
 So 1 means 100ms, 10 means 1 second.
 Range: 0 (instant) - 65535 (longest fade)
 */
@property (strong, nonatomic) NSNumber *transitionTime;

/**
 Property indicating if the bridge can reach this light
 Readonly value.
 */
@property (nonatomic, strong,readonly) NSNumber *reachable;

/**
 The on off status to set the light to.
 YES means on, NO means off.
 */
@property (strong, nonatomic) NSNumber *on;

/**
 Set XY with Color object
 */
- (void)setXYWithColor:(PHSColor*) color;

/**
 Set XY and Brightness with Color
 */
- (void)setXYBWithColor:(PHSColor*) color;

@end


