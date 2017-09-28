/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeConnectionOptions.h"

@interface PHSRemoteBridgeConnectionOptions : PHSBridgeConnectionOptions

/**
 Initializer of this class
 @param uniqueId     ID of the bridge to connect with remotely
 @param accountGuid  Global Unique portal account ID
 @param callbackUrl  URL to which www.meethue.com should redirect after login
 @param appId        ID of the application
 @param deviceId     ID of the device
 @param deviceName   name of the device
 @param clientId     developer username for remote API login (basic authentication)
 @param clientSecret developer password for remote API login (basic authentication)
 */
- (instancetype)initWithUniqueId:(NSString *)uniqueId accountGuid:(NSString *)accountGuid callbackUrl:(NSString *)callbackUrl appId:(NSString *)appId appName:(NSString *)appName deviceId:(NSString *)deviceId deviceName:(NSString *)deviceName clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;

/**
 Shorthand factory method to create an instance of PHSRemoteBridgeConnectionOptions
 @param uniqueId     ID of the bridge to connect with remotely
 @param accountGuid  Global Unique portal account ID
 @param callbackUrl  URL to which www.meethue.com should redirect after login
 @param appId        ID of the application
 @param deviceId     ID of the device
 @param deviceName   name of the device
 @param clientId     developer username for remote API login (basic authentication)
 @param clientSecret developer password for remote API login (basic authentication)
 */
+ (instancetype)optionsWithUniqueId:(NSString *)uniqueId accountGuid:(NSString *)accountGuid callbackUrl:(NSString *)callbackUrl appId:(NSString *)appId appName:(NSString *)appName deviceId:(NSString *)deviceId deviceName:(NSString *)deviceName clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;

/**
 Check if unique bridge ID has been set
 @returns whether a unique bridge id has been set
 */
- (BOOL)hasUniqueId;

/**
 Unique ID of the bridge to connect with remotely
 */
@property (strong, nonatomic) NSString *uniqueId;

/**
 Global Unique portal account ID
 */
@property (strong, nonatomic) NSString *accountGuid;

/**
 URL to which www.meethue.com should redirect after login
 */
@property (strong, nonatomic) NSString *callbackUrl;

/**
 ID of the application
 */
@property (strong, nonatomic) NSString *appId;

/**
 Name of the app
 */
@property (strong, nonatomic) NSString *appName;

/**
 ID of the device
 */
@property (strong, nonatomic) NSString *deviceId;

/**
 Name of the device
 */
@property (strong, nonatomic) NSString *deviceName;

/**
 Client ID (developer username) for remote API login (basic authentication)
 */
@property (strong, nonatomic) NSString *clientId;

/**
 Client secret (developer password) for remote API login (basic authentication)
 */
@property (strong, nonatomic) NSString *clientSecret;

@end
