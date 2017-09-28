/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"
#import "PHSDevice.h"
#import "PHSDomainType.h"

@protocol PHSCompoundDevice <NSObject>

/**
 Get devices by the given device type and identifier
 @param type        The type of the device to retrieve
 @param identifier  The identifier of the device
 @return The device, nullptr if device does not exist
 */
- (PHSDevice *)getDeviceOfType:(PHSDomainType)type withIdentifier:(NSString *)identifier;

/**
 Get devices by the given device type
 @param type The device type to retrieve
 */
- (NSArray*)getDevicesOfType:(PHSDomainType)type;

/**
 Get all devices
 */
- (NSArray*)getDevices;

/**
 Update the device state according to the provided state
 @param state                  The state to update
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to be called after update
 */
- (void)updateState:(PHSDeviceState *)state allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Update the device state according to the provided state
 @param state                  The state to update
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to be called after update
 @param sendDeltasOnly         Whether to send only the differences with the cache to the bridge
 */
- (void)updateState:(PHSDeviceState *)state allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler sendDeltasOnly:(BOOL)sendDeltasOnly;

/**
 Update the device state according to the provided state
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param state             The state to update
 @param completionHandler Block to be called after update
 */
- (void)updateState:(PHSDeviceState *)state completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Update the device configuration according to the provided configuration
 @param configuration          The configuration to update
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to be called after update
 */
- (void)updateConfiguration:(PHSDeviceConfiguration *)configuration allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Update the device configuration according to the provided configuration
 @param configuration          The configuration to update
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to be called after update
 @param sendDeltasOnly         Whether to send only the differences with the cache to the bridge
 */
- (void)updateConfiguration:(PHSDeviceConfiguration *)configuration allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler sendDeltasOnly:(BOOL)sendDeltasOnly;

/**
 Update the device Configuration according to the provided configuration
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param configuration     The configuration to update
 @param completionHandler Block to be called after update
 */
- (void)updateConfiguration:(PHSDeviceConfiguration *)configuration completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Whether the compound device is complete 
 @return true if complete, false otherwise
 */
- (BOOL)isComplete;

/**
 Domain type of the compound device
 */
- (PHSDomainType)domainType;

@end
