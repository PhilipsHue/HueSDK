/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"

@interface PHSDeviceConfiguration : PHSDomainObject

/**
 The device name
 */
@property (strong, nonatomic) NSString *name;

/**
 The software version
 */
@property (strong, nonatomic) NSString *swVersion;

/**
 The model identifier
 */
@property (strong, nonatomic) NSString *modelId;

/**
 The unique identifier
 */
@property (strong, nonatomic) NSString *uniqueId;

/**
 The manufacturer name
 */
@property (strong, nonatomic) NSString *manufacturerName;

@end
