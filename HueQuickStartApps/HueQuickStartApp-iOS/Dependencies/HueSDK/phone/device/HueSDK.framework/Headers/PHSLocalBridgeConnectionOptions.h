/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSBridgeConnectionOptions.h"

@interface PHSLocalBridgeConnectionOptions : PHSBridgeConnectionOptions

/**
 Initializer of this class
 @param ipAddress  IP address of connection
 @param appName    Application name to be used for authentication
 @param deviceName Device name to be used for authentication
 */
- (instancetype)initWithIpAddress:(NSString *)ipAddress appName:(NSString *)appName deviceName:(NSString *)deviceName;

/**
 Shorthand factory method to create an instance of PHSLocalBridgeConnectionOptions
 @param ipAddress  IP address of connection
 @param appName    Application name to be used for authentication
 @param deviceName Device name to be used for authentication
 */
+ (instancetype)optionsWithIpAddress:(NSString *)ipAddress appName:(NSString *)appName deviceName:(NSString *)deviceName;

/**
 IP address string required for connecting
 */
@property (strong, nonatomic) NSString *ipAddress;

/**
 Application name to be used for authentication
 */
@property (strong, nonatomic) NSString *appName;

/**
 Device name to be used for authentication
 */
@property (strong, nonatomic) NSString *deviceName;

@end
