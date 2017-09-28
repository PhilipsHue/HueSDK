/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"
#import "PHSPortalConnectionState.h"

@class PHSBridgePortalState;

@interface PHSBridgePortalConfiguration : PHSDomainObject

/**
 The portal state of this bridge
 */
@property (nonatomic, strong, readonly) PHSBridgePortalState *portalState;

/**
 The portal connection state of the bridge
 */
@property(nonatomic, assign, readonly) PHSPortalConnectionState portalConnectionState;

/**
 The portal services flag of the bridge, if yes the bridge connects with a portal
 */
@property(nonatomic, strong) NSNumber *portalServices;

@end
