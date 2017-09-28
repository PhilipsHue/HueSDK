/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"

@class PHSBridge;

@interface PHSBridgeResource : PHSDomainObject

/**
 The bridge resource indentifier
 */
@property (strong, nonatomic) NSString *identifier;

/**
 The bridge resource name
 */
@property (strong, nonatomic) NSString *name;

@end
