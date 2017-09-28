/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSDeviceConfiguration.h"
#import "PHSPortalConnectionState.h"
#import "PHSBridgeHomekitAttributes.h"

@class PHSBridgeVersion;
@class PHSBridgeNetworkConfiguration;
@class PHSBridgePortalConfiguration;
@class PHSBridgeTimeConfiguration;
@class PHSBridgePortalState;
@class PHSSystemSoftwareUpdate;
@class PHSBridgeInternetServicesConfiguration;

@class PHSBridgeBackup;

@interface PHSBridgeConfiguration : PHSDeviceConfiguration

/**
 Network configuration of this bridge
 */
@property (nonatomic, strong) PHSBridgeNetworkConfiguration *networkConfiguration;

/**
 Portal configuration of this bridge
 */
@property (nonatomic, strong) PHSBridgePortalConfiguration *portalConfiguration;

/**
 Time configuration of this bridge
 */
@property (nonatomic, strong) PHSBridgeTimeConfiguration *timeConfiguration;

@property (nonatomic, strong) PHSSystemSoftwareUpdate *systemSoftwareUpdate;

/**
 The backup status of this bridge
 */
@property (nonatomic, strong, readonly) PHSBridgeVersion *bridgeVersion;

/**
 The homekit attributes of this bridge
 */
@property (strong, nonatomic) PHSBridgeHomekitAttributes *homekitAttributes;

/**
 The internet services configuration of this bridge
 */
@property (nonatomic, strong, readonly) PHSBridgeInternetServicesConfiguration *internetServicesConfiguration;

/**
 The reboot flag, soft reboots the bridge if set to true
 */
@property (strong, nonatomic) NSNumber *reboot;

/**
 The link button flag, to push the bridge's link button programmatically
 */
@property (strong, nonatomic) NSNumber *linkButton;

/**
 The clip touchlink flag
 */
@property (strong, nonatomic) NSNumber *touchlink;

/**
 Whether the bridge is factory new
 */
@property (strong, nonatomic, readonly) NSNumber *factoryNew;

/**
 Bridge id of the bridge which is being replaced by the current bridge.
 */
@property (strong, nonatomic) NSString *replacesBridgeId;

/**
 The backup status of this bridge
 */
@property (nonatomic, strong) PHSBridgeBackup *backup;

/**
 Name of the starter kit initially shipped
 */
@property (strong, nonatomic) NSString *starterKitId;

@end
