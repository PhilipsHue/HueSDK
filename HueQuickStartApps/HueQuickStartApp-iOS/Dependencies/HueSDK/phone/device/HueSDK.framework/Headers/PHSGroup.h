/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeResource.h"
#import "PHSReturnCode.h"
#import "PHSBridgeResponseCompletionHandler.h"
#import "PHSBridgeConnectionType.h"
#import "PHSGroupType.h"
#import "PHSGroupClass.h"
#import "PHSGroupState.h"
#import "PHSGroupStream.h"
#import "PHSGroupLightLocation.h"
#import "PHSLightPoint.h"

@class PHSBridge;

@interface PHSGroup : PHSBridgeResource 

/**
 The identifiers of the lights controlled by this group
 No MSL support for setter
 */
@property (strong, nonatomic) NSArray<NSString*> *lightIdentifiers;

/**
 The type of this group
 */
@property (nonatomic, assign) PHSGroupType type;

/**
 The group class, which is only set when the type == PHSGroupTypeGroup or type == PHSGroupTypeEntertainment
 */
@property (nonatomic, assign) PHSGroupClass groupClass;

/**
 The model ID that uniquely identifies the hardware model of the luminaire for the given manufacturer. Only present for automatically created Luminaires,
 */
@property (nonatomic, strong, readonly) NSString *modelId;

/**
 Whether the sensor can be recycled by the bridge
 Can only be set on creation
 */
@property (strong, nonatomic) NSNumber *recycle;

/**
 State of the group
 */
@property (strong, nonatomic, readonly) PHSGroupState *groupState;

/**
 Stream object for entertainment groups
 */
@property (strong, nonatomic) PHSGroupStream *stream;

/**
 Map with light locations
 */
@property (strong, nonatomic, readonly) NSDictionary<NSString*, PHSGroupLightLocation*> *lightLocations;

/**
 Apply "action" to a group of lights
 @note  In case of applying a light state, a PHSLightState should be passed as action
 @note  In case of recalling a scene, a PHSScene should be passed as action
 @param action                  The action to preform (e.g. set state, or recall scene)
 @param allowedConnectionTypes  Allowed connections to use for the operation
 @param completionHandler Block to be called after apply
 */
- (void)apply:(PHSDomainObject*)action allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Set the lights for this group
 @note MSL supported
 */
- (void)setLights:(NSArray*)lights;

/**
 Add light
 @note MSL supported
 */
- (void)addLight:(PHSLightPoint*)light;

/**
 Remove light
 @note MSL supported
 @return true if the light was in group and deleted
 */
- (BOOL)removeLight:(PHSLightPoint*)light;

/**
 Set light locations for the given lights
 @note MSL supported
 */
- (void)setLightLocationsWithMap:(NSMapTable<PHSLightPoint*, PHSGroupLightLocation *> *)lightLocations;

/**
 Add light location. If a location already exists for the given light, it will be overwritten
 @note MSL supported
 */
- (void)addLightLocation:(PHSGroupLightLocation *)lightLocation forLight:(PHSLightPoint *)light;

/**
 Remove light location from the list
 @note MSL supported
 */
- (BOOL)removeLightLocation:(PHSLightPoint *)light;

@end
