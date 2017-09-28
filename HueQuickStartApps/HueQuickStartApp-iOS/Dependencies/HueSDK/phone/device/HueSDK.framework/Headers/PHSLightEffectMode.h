/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSLightEffectMode) {
    PHSLightEffectModeUnknown, // It is unknown what the current effect value is
    PHSLightEffectModeNone, // No effect active
    PHSLightEffectModeColorLoop // Colorloop effect (loop through colors whith current saturation and brightness)
};

