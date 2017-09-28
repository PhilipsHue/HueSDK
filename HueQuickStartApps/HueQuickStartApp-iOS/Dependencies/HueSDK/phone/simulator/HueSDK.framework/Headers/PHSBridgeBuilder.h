/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import "PHSBridge.h"
#import "PHSBridgeConnectionType.h"
#import "PHSBridgeState.h"
#import "PHSBridgeConnection.h"

@interface PHSBridgeBuilder : NSObject

/**
 IP address of the bridge
 */
@property (strong, nonatomic) NSString *ipAddress;

/**
 The bridge's ID (optional for remote connection)
 */
@property (strong, nonatomic) NSString *bridgeID;

/**
 the type of connections that will be requested: PHSBridgeConnectionTypeLocal, PHSBridgeConnectionTypeRemote, or PHSBridgeConnectionTypeLocalRemote
 */
@property (nonatomic) PHSBridgeConnectionType connectionTypes;

/**
 The bridge connection observer
 */
@property (strong, nonatomic) id<PHSBridgeConnectionObserver> bridgeConnectionObserver;

/**
 The device name
 */
- (instancetype)initWithAppName:(NSString *)appName withDeviceName:(NSString *)deviceName;

/**
 setup parameters for remote connection
 if any non-optional parameter is nullptr, all will be ignored
 @param appID        ID of the application
 @param deviceID     ID of the device
 @param accountGUID  Global Unique portal account ID
 @param callbackURL  URL to which www.meethue.com should redirect after login
 */
- (void)setupRemoteWithAppID:(NSString*)appID withDeviceID:(NSString*)deviceID withAccountGUID:(NSString*)accountGUID withcallbackURL:(NSString*)callbackURL;

/**
 Setup parameters for remote connection
 @param appID        ID of the application
 @param deviceID     ID of the device
 @param accountGUID  Global Unique portal account ID
 @param callbackURL  URL to which www.meethue.com should redirect after login
 @param clientID     developer username for remote API login (basic authentication)
 @param clientSecret developer password for remote API login (basic authentication)
 */
- (void)setupRemoteWithAppID:(NSString*)appID withDeviceID:(NSString*)deviceID withAccountGUID:(NSString*)accountGUID withcallbackURL:(NSString*)callbackURL withclientID:(NSString*)clientID withClientSecret:(NSString*)clientSecret;

/**
 Add observer that will be called when the bridge state object gets updated
 */
- (void)addStateUpdateObserver:(id<PHSBridgeStateUpdateObserver>)observer;

/**
 @return a newly built bridge with connections of all requested connection types
 */
- (PHSBridge*) build;

@end
