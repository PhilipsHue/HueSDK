/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"
#import "PHSDomainType.h"

@interface PHSDeviceSearchDeviceInfo : PHSObject

/**
 The device indentifier
 */
@property (strong, nonatomic, readonly) NSString *identifier;

/**
 The device name
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 The domain type
 */
@property (assign, nonatomic, readonly) PHSDomainType domainType;

@end
