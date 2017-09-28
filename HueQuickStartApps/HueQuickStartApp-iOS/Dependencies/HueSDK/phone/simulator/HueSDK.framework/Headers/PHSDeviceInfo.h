/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"

@class PHSManufacturer;

@interface PHSDeviceInfo : PHSObject

/**
 The product name
 */
@property (strong, nonatomic, readonly) NSString *productName;

/**
 The manufacturer of the light
 */
@property (strong, nonatomic, readonly) PHSManufacturer *manufacturer;

/**
 The supported features for the light
 */
@property (strong, nonatomic, readonly) NSArray *supportedFeatures;

/**
 The friendly name of the light
 */
@property (strong, nonatomic, readonly) NSString *friendlyName;

/**
 Check whether a feature is supported by the device
 @param feature requested feature
 @return whether the device supports a feature
 */
-(BOOL) doesSupport:(NSString*) feature;

@end

