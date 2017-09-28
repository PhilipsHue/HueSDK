/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 SDK Version: 1.21.0
 ********************************************************************************/

#import <Foundation/Foundation.h>

#import "PHSObject.h"
#import "PHSReturnCode.h"

@class PHSBridgeConfiguration;

@interface PHSSDK : PHSObject

/**
 @return The SDK version string
 */
+ (NSString *)version;

/**
 @return The URL for bridge discovery
 */
+ (NSString *)bridgeDiscoveryURL;

/**
 Set the bridge discovery URL
 @param url The base URL for bridge discovery (e.g. "https://www.meethue.com")
 */
+ (PHSReturnCode)setBridgeDiscoveryURL:(NSString *)url;

/**
 @return The API URL for remote connections
 */
+ (NSString *)remoteAPIURL;

/**
 Set the API URL used for remote connections
 @param url The base URL for the remote API (e.g. "https://api.meethue.com")
 */
+ (PHSReturnCode)setRemoteAPIURL:(NSString *)url;

/**
 @return The proxy address to use for http requests
 */
+ (NSString *)proxyAddress;

/**
 @return The proxy port to use for http requests
 */
+ (NSUInteger)proxyPort;

/**
 @return True when proxy settings are set
 */
+ (BOOL)proxyIsSet;

/**
 Enable proxy to use for http requests
 @param address The proxy address to use
 @param port The proxy port to use
 */
+ (PHSReturnCode)setProxyAddress:(NSString*)address port:(NSUInteger)port;

+ (void)clearProxySettings;

/**
 Retrieve bridge configuration by ip address
 @param ip the ip address.
 @return BridgeConfiguration if the ip is an actual hue bridge or null.
 */
+ (PHSBridgeConfiguration*)getBridgeInformation:(NSString *)ip;

@end
