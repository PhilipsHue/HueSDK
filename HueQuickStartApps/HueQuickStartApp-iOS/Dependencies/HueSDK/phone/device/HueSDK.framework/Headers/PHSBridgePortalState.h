/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDomainObject.h"
#import "PHSPortalConnectionState.h"

@interface PHSBridgePortalState : PHSDomainObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The signed on flag to indicate if your are signed on to the portal.
 */
@property (strong, nonatomic, readonly) NSNumber *signedOn;

/**
 The incoming flag to indicate if the bridge is able to recieve messages from the portal.
 */
@property (strong, nonatomic, readonly) NSNumber *incoming;

/**
 The outgoing flag to indicate if the bridge is able to send messages to the portal.
 */
@property (strong, nonatomic, readonly) NSNumber *outgoing;

/**
 The portal connection state of the bridge
 */
@property (assign, nonatomic, readonly) PHSPortalConnectionState communicationState;

@end
