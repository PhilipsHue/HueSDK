/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDeviceInfo.h"

@class PHSGamut;

@interface PHSLightInfo : PHSDeviceInfo

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The friendly name of the light
 */
@property (strong, nonatomic, readonly) PHSGamut *gamut;

/**
 The model id of the light
 */
@property (strong, nonatomic, readonly) NSString *modelId;

/**
 The sw version
 */
@property (strong, nonatomic, readonly) NSString *swVersion;

/**
 The light type
 */
@property (strong, nonatomic, readonly) NSString *lightType;

/**
 The param ranges of attributes which are settable on the light
 */
@property (strong, nonatomic, readonly) NSDictionary *parameterRanges;

/**
 The images
 */
@property (strong, nonatomic, readonly) NSDictionary *images;

@end
