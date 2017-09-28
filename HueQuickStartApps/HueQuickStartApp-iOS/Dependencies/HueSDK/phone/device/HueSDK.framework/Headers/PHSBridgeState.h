/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/
#import <Foundation/Foundation.h>

#import "PHSBridgeCapabilities.h"
#import "PHSBridgeConfiguration.h"
#import "PHSBridgeConnectionType.h"
#import "PHSBridgeResource.h"
#import "PHSBridgeStateCacheType.h"
#import "PHSDeviceState.h"
#import "PHSDomainType.h"
#import "PHSReturnCode.h"

@class PHSDevice;
@class PHSBridge;
@class PHSDeviceSearchStatus;

static const NSTimeInterval PHSBridgeStateAgeUnknown = -1;

typedef NS_ENUM(NSInteger, PHSBridgeStateUpdatedEvent) {
    PHSBridgeStateUpdatedEventNone                    = -1,
    PHSBridgeStateUpdatedEventInitialized             = 0,
    PHSBridgeStateUpdatedEventFullConfig              = 1,
    PHSBridgeStateUpdatedEventBridgeConfig            = 2,
    PHSBridgeStateUpdatedEventLightsAndGroups         = 3,
    PHSBridgeStateUpdatedEventScenes                  = 4,
    PHSBridgeStateUpdatedEventSensorsAndSwitches      = 5,
    PHSBridgeStateUpdatedEventRules                   = 6,
    PHSBridgeStateUpdatedEventSchedulesAndTimers      = 7,
    PHSBridgeStateUpdatedEventResourceLinks           = 8,
    PHSBridgeStateUpdatedEventDeviceSearchStatus      = 9,
};

@protocol PHSBridgeStateUpdateObserver <NSObject>

- (void)bridge:(PHSBridge *)bridge handleEvent:(PHSBridgeStateUpdatedEvent)updateEvent;

@end


@interface PHSBridgeState : PHSDeviceState

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The bridge configuration
 */
@property (strong, nonatomic, readonly) PHSBridgeConfiguration *bridgeConfiguration;

/**
 Get device by type and identifier
 @param type        Type of the requested device
 @param identifier  ID id of the requested device
 @return requested devices
 */
- (PHSDevice *)getDeviceOfType:(PHSDomainType)type withIdentifier:(NSString *)identifier;

/**
 Get all the devices by type
 @param type Type of device to filter on
 @return array of devices of the requested type
 */
- (NSArray*)getDevicesOfType:(PHSDomainType)type;

/**
 Get all the devices for a certain feature
 @param feature feature that should be supported
        see PHSSupportedFeature.h
 @return array of devices with required feature
 */
- (NSArray*)getDevicesWithFeature:(NSString*) feature;

/**
 Get all the devices with certain features
 @param features list of features which should be supported
        see PHSSupportedFeature.h
 @return array of devices with required features
 */
- (NSArray*)getDevicesWithFeatures:(NSArray*) features;

/**
 Get all the devices
 @return array of all devices
 */
- (NSArray*)getDevices;

/**
 Get resource by type and identifier
 @param type        Type of the requested device
 @param identifier  ID id of the requested device
 @return requested devices
 */
- (PHSBridgeResource *)getBridgeResourceOfType:(PHSDomainType)type withIdentifier:(NSString *)identifier;

/**
 Get all the resources by type
 @param type Type of resource to filter on
 @return array of resources of the requested type
 */
- (NSArray*)getBridgeResourcesOfType:(PHSDomainType)type;

/**
 Get all the resources
 @return array of all resources
 */
- (NSArray*)getBridgeResources;

/**
 Check that resource actually exists.
 @param type        Type of the requested resource
 @param identifier  ID id of the requested resource
 @return true if the resource is here.
 */
- (BOOL)hasResourceOfType:(PHSDomainType)type withIdentifier:(NSString *)identifier;

/**
 Add observer that will be called when the bridge state object gets updated
 */
- (void)addStateUpdateObserver:(id<PHSBridgeStateUpdateObserver>)observer;

/**
 Remove observer that will be called when the bridge state object gets updated
 */
- (void)removeStateUpdateObserver:(id<PHSBridgeStateUpdateObserver>)observer;

/**
 Refresh resource(s) based on cache type
 The bridge state will perform a heartbeat and events on changes will be received through the
 bridge state observer
 @param cacheType      Resource(s) to be refreshed
 @param connectionType Which connections can be used for refreshing the particular resource(s)
 @return PHSReturnCodeSuccess on 
 */
- (PHSReturnCode)refresh:(PHSBridgeStateCacheType)cacheType withConnectionType:(PHSBridgeConnectionType)connectionType;

/**
 Get whether the bridge is searching for devices. The object
 contains a flag whether a search is in progress and if not when
 the last scan date has been set.
 @return Object with info regarding device searching status
 */
- (PHSDeviceSearchStatus *)getDeviceSearchStatus;

/**
  Returns the bridge's capabilities
  Note that the caller gets ownership of the returned object
  @return a list of bridge capabilities
   */
- (PHSBridgeCapabilities*)getCapabilities;

/**
 Serializes the bridge state to a json string
 @return The serialized json string, nil on error
 */
- (NSString *)jsonString;

@end
