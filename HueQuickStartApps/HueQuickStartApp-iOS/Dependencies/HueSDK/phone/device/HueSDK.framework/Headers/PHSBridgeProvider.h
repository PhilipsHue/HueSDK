/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"

@class PHSBridge;

@interface PHSBridgeProvider : PHSObject

/**
 Provides a Bridge object
 @return a new instance of the PHSBridge
 */
+ (PHSBridge *)getBridge;

/**
 Provides a Bridge object filled with a persisted bridge state
 @param bridgeId The unique identifier of the bridge
 @return a new instance of the PHSBridge, filles with data from persistence for the specified bridge id
 */
+ (PHSBridge *)getBridgeWithBridgeID:(NSString *)bridgeId;

@end
