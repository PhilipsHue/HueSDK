/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSLightColorMode) {
    PHSLightColorModeUnknown = -1, // It is unknown what the current colormode is
    PHSLightColorModeNone = 0, // No colormode (for lights which do not support color)
    PHSLightColorModeHueSaturation = 1, // Color is set by hue + saturation
    PHSLightColorModeXY = 2,// Color is set by xy
    PHSLightColorModeCT = 3 // Color is set by ct
};

