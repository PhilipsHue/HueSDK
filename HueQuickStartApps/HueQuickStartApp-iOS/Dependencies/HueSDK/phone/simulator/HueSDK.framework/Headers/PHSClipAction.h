/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"
#import "PHSDomainObject.h"
#import "PHSClipActionType.h"

@class PHSDevice;
@class PHSDeviceState;
@class PHSDeviceConfiguration;
@class PHSBridgeVersion;
@class PHSBridgeResource;
@class PHSScene;
@class PHSGroup;
@class PHSLightState;

@interface PHSClipAction : PHSDomainObject

/**
 Initializer of this class
 @param state the state you want to update in an update state action
 @param device the device you want to update the state of in  an update state action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForUpdateState:(PHSDeviceState *)state onDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param state the state you want to update in an update state action
 @param device the device you want to update the state of in  an update state action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForUpdateState:(PHSDeviceState *)state onDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param state the state you want to update in an update state action
 @param device the device you want to update the state of in  an update state action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForUpdateState:(PHSDeviceState *)state onDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param state the state you want to update in an update state action
 @param device the device you want to update the state of in  an update state action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForUpdateState:(PHSDeviceState *)state onDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param configuration the configuration you want to update in an update configuration action
 @param device the device you want to update the state of in  an update state action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForUpdateConfiguration:(PHSDeviceConfiguration *)configuration onDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param configuration the configuration you want to update in an update configuration action
 @param device the device you want to update the state of in  an update state action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForUpdateConfiguration:(PHSDeviceConfiguration *)configuration onDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param configuration the configuration you want to update in an update configuration action
 @param device the device you want to update the state of in  an update state action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForUpdateConfiguration:(PHSDeviceConfiguration *)configuration onDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param configuration the configuration you want to update in an update configuration action
 @param device the device you want to update the state of in  an update state action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForUpdateConfiguration:(PHSDeviceConfiguration *)configuration onDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param device the delete you want to delete in an delete device action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForDeleteDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param device the delete you want to delete in an delete device action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForDeleteDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param device the delete you want to delete in an delete device action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForDeleteDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param device the delete you want to delete in an delete device action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForDeleteDevice:(PHSDevice *)device bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param resource the resource you want to create in an create resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForCreateResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param resource the resource you want to create in an create resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForCreateResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param resource the resource you want to create in an create resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForCreateResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param resource the resource you want to create in an create resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForCreateResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param resource the resource you want to update in an update resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForUpdateResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param resource the resource you want to update in an update resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForUpdateResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param resource the resource you want to update in an update resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForUpdateResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param resource the resource you want to update in an update resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForUpdateResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param resource the resource you want to delete in an delete resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForDeleteResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param resource the resource you want to delete in an delete resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForDeleteResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param resource the resource you want to delete in an delete resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForDeleteResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param resource the resource you want to delete in an delete resource action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForDeleteResource:(PHSBridgeResource *)resource bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param scene the scene you want to recall in an recall scene action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallScene:(PHSScene *)scene bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param scene the scene you want to recall in an recall scene action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallScene:(PHSScene *)scene bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param scene the scene you want to recall in an recall scene action
 @param group the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallScene:(PHSScene *)scene onGroup:(PHSGroup *)group bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param scene the scene you want to recall in an recall scene action
 @param group the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallScene:(PHSScene *)scene onGroup:(PHSGroup *)group bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param scene the scene you want to recall in an recall scene action
 @param groupIdentifier the identifier of the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallScene:(PHSScene *)scene onGroupWithId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param scene the scene you want to recall in an recall scene action
 @param groupIdentifier the identifier of the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallScene:(PHSScene *)scene onGroupWithId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param group the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallSceneWithId:(NSString *)sceneIdentifier onGroup:(PHSGroup *)group bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param group the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallSceneWithId:(NSString *)sceneIdentifier onGroup:(PHSGroup *)group bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param scene the scene you want to recall in an recall scene action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallScene:(PHSScene *)scene bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param scene the scene you want to recall in an recall scene action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallScene:(PHSScene *)scene bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param scene the scene you want to recall in an recall scene action
 @param group the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallScene:(PHSScene *)scene onGroup:(PHSGroup *)group bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param scene the scene you want to recall in an recall scene action
 @param group the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallScene:(PHSScene *)scene onGroup:(PHSGroup *)group bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param scene the scene you want to recall in an recall scene action
 @param groupIdentifier the identifier of the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallScene:(PHSScene *)scene onGroupWithId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param scene the scene you want to recall in an recall scene action
 @param groupIdentifier the identifier of the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallScene:(PHSScene *)scene onGroupWithId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param group the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallSceneWithId:(NSString *)sceneIdentifier onGroup:(PHSGroup *)group bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param group the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallSceneWithId:(NSString *)sceneIdentifier onGroup:(PHSGroup *)group bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallSceneWithId:(NSString *)sceneIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallSceneWithId:(NSString *)sceneIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param groupIdentifier the identifier of the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallSceneWithId:(NSString *)sceneIdentifier onGroupWithId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param groupIdentifier the identifier of the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallSceneWithId:(NSString *)sceneIdentifier onGroupWithId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallSceneWithId:(NSString *)sceneIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallSceneWithId:(NSString *)sceneIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param groupIdentifier the identifier of the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForRecallSceneWithId:(NSString *)sceneIdentifier onGroupWithId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param sceneIdentifier the identifier of the scene you want to recall in an recall scene action
 @param groupIdentifier the identifier of the group you want to recall the scene on
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForRecallSceneWithId:(NSString *)sceneIdentifier onGroupWithId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Initializer of this class
 @param lightState the lightstate do you want to apply to the group in an apply lightstate action
 @param groupIdentifier the identifier of the group you want to apply the lightstate on in an apply lightstate action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForApplyLightState:(PHSLightState *)lightState toGroupId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Shorthand factory method to create an instance of this class
 @param lightState the lightstate do you want to apply to the group in an apply lightstate action
 @param groupIdentifier the identifier of the group you want to apply the lightstate on in an apply lightstate action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForApplyLightState:(PHSLightState *)lightState toGroupId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion;

/**
 Initializer of this class
 @param lightState the lightstate do you want to apply to the group in an apply lightstate action
 @param groupIdentifier the identifier of the group you want to apply the lightstate on in an apply lightstate action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
- (instancetype)initForApplyLightState:(PHSLightState *)lightState toGroupId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 Shorthand factory method to create an instance of this class
 @param lightState the lightstate do you want to apply to the group in an apply lightstate action
 @param groupIdentifier the identifier of the group you want to apply the lightstate on in an apply lightstate action
 @param bridgeVersion the version of the bridge in which you want to create this action
 @param userName the username under which you want to perform this action (used for clip actions in schedules)
 @return an instance of PHSClipAction with clip adress, method and body set for your action
 */
+ (instancetype)actionForApplyLightState:(PHSLightState *)lightState toGroupId:(NSString *)groupIdentifier bridgeVersion:(PHSBridgeVersion*)bridgeVersion userName:(NSString*)userName;

/**
 The clip address
 */
@property (strong, nonatomic) NSString *address;

/**
 The action body
 */
@property (strong, nonatomic) NSString *body;

/**
 The method (PUT, POST, DELETE, GET)
 */
@property (strong, nonatomic) NSString *method;

/**
 The type of action to be performed
 */
@property (assign, nonatomic) PHSClipActionType actionType;

/**
 The device 
 @note either the device or resource is set, not both
 */
@property (strong, nonatomic) PHSDevice *device;

/**
 The resource
 @note either the device or resource is set, not both
 */
@property (strong, nonatomic) PHSBridgeResource *resource;

/**
 The resource
 @note either the device or resource is set, not both
 */
@property (strong, nonatomic) PHSDomainObject *bodyObject;

@end
