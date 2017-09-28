/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSDevice.h"

typedef NS_ENUM(NSInteger, PHSLightType) {
    PHSLightTypeOnOff = 1,
    PHSLightTypeDimmable = 2,
    PHSLightTypeColor = 3,
    PHSLightTypeColorTemperature = 4,
    PHSLightTypeExtendedColor = 5
};

@class PHSLightInfo;
@class PHSLightState;
@class PHSLightConfiguration;

@interface PHSLightPoint : PHSDevice

/**
 Light state of the light
 */
@property (strong, nonatomic, readonly) PHSLightState *lightState;

/**
 The light information
 */
@property (strong, nonatomic, readonly) PHSLightInfo *lightInfo;

/**
 Light configuration of the light
 */
@property (strong, nonatomic, readonly) PHSLightConfiguration *lightConfiguration;

/**
 Light type
 */
@property (assign, nonatomic, readonly) PHSLightType lightType;

/*
 set the light state
 @param lightState state to set
 @return PHSSuccess or PHSUnsupportedParameterType
 */
- (PHSReturnCode)setLightState:(PHSLightState *)lightState;

@end
