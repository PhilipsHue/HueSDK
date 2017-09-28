/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSBridgeConnectionType.h"
#import "PHSObject.h"

@interface PHSBridgeConnectionOptions : PHSObject

/**
 The receiver’s timeout interval, in seconds
 If during a connection attempt the request remains idle for longer than the timeout interval, the request is considered to have timed out.
 */
@property (assign, nonatomic) NSInteger receiveTimeout;

/**
 The request timeout in seconds (not supported yet)
 How long a request may take in total
 */
@property (assign, nonatomic) NSInteger requestTimeout;

/**
 The number of maximum retries
 */
@property (assign, nonatomic) NSInteger maximumRetryCount;

/**
 Enable or disable the queue
 */
@property (assign, nonatomic) BOOL enableQueue;

/**
 Type of connection (e.g. local or portal)
 */
@property (assign, nonatomic, readonly) PHSBridgeConnectionType connectionType;

/**
 Base URI string required for connecting
 */
@property (strong, nonatomic, readonly) NSString *connectionString;

/**
 User name to be used for authentication
 */
@property (strong, nonatomic) NSString *userName;

/**
 Whether fast connection mode is enabled
 */
@property (assign, nonatomic, readonly) BOOL fastConnectionModeEnabled;

/**
 The unique id of the bridge used for the  fast connection connection mode
 */
@property (strong, nonatomic, readonly) NSString* fastConnectionUniqueId;

/**
 Enable fast connection mode
 @note This mode will try to load the bridge state from the persistence by the given
       unique id. If the bridge state is not persisted, it will fall back to the normal
       connection mode.
 @param uniqueId The unique id of the bridge to connect to
                 The unique id is case insensitive
 */
- (void)enableFastConnectionMode:(NSString *)uniqueId;

/**
 Disable fast connection mode (default)
 */
- (void)disableFastConnectionMode;

@end
