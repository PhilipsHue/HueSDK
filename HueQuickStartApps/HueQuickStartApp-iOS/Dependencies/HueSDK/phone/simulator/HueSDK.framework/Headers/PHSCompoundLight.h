/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSCompoundDevice.h"
#import "PHSLightPoint.h"
#import "PHSGroup.h"

typedef NS_ENUM(NSInteger, PHSCompoundLightUpdateMode) {
    PHSCompoundLightUpdateModeStreaming = 0,  // Default -> group cast
    PHSCompoundLightUpdateModeUnicast = 1     // Updating each light individually
};

@interface PHSCompoundLight : PHSLightPoint<PHSCompoundDevice>

/**
 The mode for updating the compound light
 */
@property (nonatomic,assign) PHSCompoundLightUpdateMode updateMode;


/**
 The group that belongs to this compound light
 */
@property (strong, nonatomic, readonly) PHSGroup *group;

/**
 Update the device state according to the provided state
 @param state                  The state to update
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param updateMode             steraming vs unicast (see enum for description)
 @param completionHandler      Block to be called after update
 */
- (void)updateState:(PHSDeviceState *)state allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes updateMode:(PHSCompoundLightUpdateMode)updateMode completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Update the device state according to the provided state
 @param state                  The state to update
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param updateMode             steraming vs unicast (see enum for description)
 @param completionHandler      Block to be called after update
 @param sendDeltasOnly         Send only the differences with cached state
 */
- (void)updateState:(PHSDeviceState *)state allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes updateMode:(PHSCompoundLightUpdateMode)updateMode completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler sendDeltasOnly:(BOOL)sendDeltasOnly;

/**
 Update the device state according to the provided state
 @param state                  The state to update
 @param updateMode             steraming vs unicast (see enum for description)
 @param completionHandler      Block to be called after update
 */
- (void)updateState:(PHSDeviceState *)state updateMode:(PHSCompoundLightUpdateMode)updateMode completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

@end
