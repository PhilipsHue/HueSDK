/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeResource.h"
#import "PHSSceneAppData.h"
#import "PHSReturnCode.h"
#import "PHSBridgeResponseCompletionHandler.h"
#import "PHSBridgeConnectionType.h"

@class PHSBridge;
@class PHSLightState;
@class PHSLightPoint;

@interface PHSScene : PHSBridgeResource

/**
 The lights controlled by this scene.
 Since api 1.11.0 a light has also the set light state for the scene
 */
@property (strong, nonatomic) NSArray *lights;

/**
 The identifiers of the lights controlled by this scene
 No MSL support for setter
 */
@property (strong, nonatomic) NSArray *lightIdentifiers;

/**
 The active state of this scene (deprecated)
 */
@property (nonatomic, strong, readonly) NSNumber *active;

/**
 The owner (username of a whitelist entry) of the scene
 */
@property (nonatomic, strong) NSString *owner;

/**
 Whether the scene can be recycled by the bridge
 Can only be set on creation
 */
@property (nonatomic, strong) NSNumber *recycle;

/**
 The active state of this scene
 */
@property (nonatomic, strong, readonly) NSNumber *locked;

/**
 Date when the scene has been created or updated
 */
@property (nonatomic, strong, readonly) NSDate *lastUpdated;

/**
 App specific data linked to the scene. Application should only parse data if application is known through “owner”. 
 */
@property (nonatomic, strong) PHSSceneAppData *sceneAppData;

/**
 The picture of the scene
 */
@property (nonatomic, strong) NSString *picture;

/**
 The scene version
 */
@property (nonatomic, strong, readonly) NSNumber *version;

/**
 Set the transition time
 @param transitionTime Transition time in seconds
 */
- (void)setTransitionTime:(NSNumber *)transitionTime;

/**
 If set, the lightstates of the lights in scene will be overwritten by the current CLIP state of the lights. 
 Can be used in combination with transition time to update transition time of scene. Always true on creation.
 @param storeLightState The light state to store
 */
- (void)setStoreLightState:(NSNumber *)storeLightState;

/**
 Set the state of a light for this scene
 Note: The given light_state must exists as long as this scene exists.
 @param lightState      State of the light for that scene
 @param lightIdentifier Identifier of the light to add to a scene
 @return PHSReturnCodeSuccess, PHSReturnCodeWrongParameter or PHSReturnCodeItemNotFound
 */
- (PHSReturnCode)setLightState:(PHSLightState *)lightState forLightIdentifier:(NSString *)lightIdentifier;

/**
 Set the state of a light for this scene
 Note: The given light_state must exists as long as this scene exists.
 @param lightState State of the light for that scene
 @param light      The light to add to a scene
 @return PHSReturnCodeSuccess, PHSReturnCodeWrongParameter or PHSReturnCodeItemNotFound
 */
- (PHSReturnCode)setLightState:(PHSLightState *)lightState forLight:(PHSLightPoint *)light;

/**
 Recall a scene
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Completionhandler to be called after recalling the scene
 */
- (void)recallSceneWithAllowedConnections:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Add light
 @note MSL supported
 @param light The light to be added
 */
- (void)addLight:(PHSLightPoint*)light;

/**
 Remove light
 @note MSL supported
 @param light The light to be removed
 @return true if the light was in scene and deleted
 */
- (BOOL)removeLight:(PHSLightPoint*)light;

@end
