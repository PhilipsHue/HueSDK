/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSReturnCode.h"
#import "PHSDomainObject.h"
#import "PHSBridgeConnectionType.h"
#import "PHSBridgeResponseCompletionHandler.h"

@class PHSDeviceInfo;
@class PHSDeviceState;
@class PHSDeviceConfiguration;
@class PHSDeviceSoftwareUpdate;

@interface PHSDevice : PHSDomainObject

@property (strong, nonatomic, readonly) NSString *name;

@property (strong, nonatomic, readonly) PHSDeviceInfo *deviceInfo;

@property (strong, nonatomic, readonly) PHSDeviceState *deviceState;

@property (strong, nonatomic)           PHSDeviceConfiguration *deviceConfiguration;

@property (strong, nonatomic, readonly) PHSDeviceSoftwareUpdate *deviceSoftwareUpdate;

/**
 Set the device state according to the provided state
 @param deviceState The state to set
 @return PHSSuccess or PHSUnsupportedParameterType
 */
- (PHSReturnCode)setDeviceState:(PHSDeviceState *)deviceState;

/**
 Update the device state according to the provided state
 @param state                  The state to update
 @param allowedConnectionTypes How to connect to the bridge
 @param completionHandler      Block to be called after update
 */
- (void)updateState:(PHSDeviceState *)state allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Update the device state according to the provided state
 @param state                  The state to update
 @param allowedConnectionTypes Which connection types should be used
 @param completionHandler      Block to be called after update
 @param sendDeltasOnly         Whether to send only the differences with the cache to the bridge.
 */
- (void)updateState:(PHSDeviceState *)state allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler sendDeltasOnly:(BOOL)sendDeltasOnly;

/**
 Update the device configuration according to the provided configuration
 @param configuration          The configuration to update
 @param allowedConnectionTypes Which connection types should be used
 @param completionHandler      Block to be called after update
 */
- (void)updateConfiguration:(PHSDeviceConfiguration *)configuration allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Update the device configuration according to the provided configuration
 @param configuration          The configuration to update
 @param allowedConnectionTypes Which connection types should be used
 @param completionHandler      Block to be called after update
 @param sendDeltasOnly         Whether to send only the differences with the cache to the bridge.
 */
- (void)updateConfiguration:(PHSDeviceConfiguration *)configuration allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler sendDeltasOnly:(BOOL)sendDeltasOnly;

@end

