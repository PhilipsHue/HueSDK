/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSButtonEvent) {
    PHSButtonEventUnknown                              = -1,
    PHSButtonEventNone                                 = 0,
    PHSButtonEventCodeScene1                           = 16,
    PHSButtonEventCodeScene2                           = 17,
    PHSButtonEventCodeScene3                           = 18,
    PHSButtonEventCodeScene4                           = 19,
    PHSButtonEventCodeScene5                           = 20,
    PHSButtonEventCodeScene6                           = 21,
    PHSButtonEventCodeScene7                           = 22,
    PHSButtonEventCodeScene8                           = 23,
    PHSButtonEventCodeToggle                           = 34,
    PHSButtonEventCodePressButton1                     = 98,
    PHSButtonEventCodeReleaseButton1                   = 99,
    PHSButtonEventCodePressButton2                     = 100,
    PHSButtonEventCodeReleaseButton2                   = 101,
    PHSButtonEventCodeDimmerOnInitialPress             = 1000,
    PHSButtonEventCodeDimmerOnStillPressed             = 1001,
    PHSButtonEventCodeDimmerOnRelease                  = 1002,
    PHSButtonEventCodeDimmerOnReleaseLong              = 1003,
    PHSButtonEventCodeDimmerBrightnessUpInitialPress   = 2000,
    PHSButtonEventCodeDimmerBrightnessUpStillPressed   = 2001,
    PHSButtonEventCodeDimmerBrightnessUpRelease        = 2002,
    PHSButtonEventCodeDimmerBrightnessUpReleaseLong    = 2003,
    PHSButtonEventCodeDimmerBrightnessDownInitialPress = 3000,
    PHSButtonEventCodeDimmerBrightnessDownStillPressed = 3001,
    PHSButtonEventCodeDimmerBrightnessDownRelease      = 3002,
    PHSButtonEventCodeDimmerBrightnessDownReleaseLong  = 3003,
    PHSButtonEventCodeDimmerOffInitialPress            = 4000,
    PHSButtonEventCodeDimmerOffStillPressed            = 4001,
    PHSButtonEventCodeDimmerOffRelease                 = 4002,
    PHSButtonEventCodeDimmerOffReleaseLong             = 4003
};
