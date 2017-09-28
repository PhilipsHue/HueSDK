/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSPortalConnection.h"

@class PHSBridge;
@class PHSBridgeConnection;
@class PHSBridgeConnectionOptions;

@interface PHSBridgeConnectionProvider : NSObject

/**
 Returns the requested bridge connection, defined by the connection options parameter
 @return the requested bridge connection
 */
+ (PHSBridgeConnection *)getBridgeConnection:(PHSBridgeConnectionOptions *)bridgeConnectionOptions forBridge:(PHSBridge *)bridge;

/**
 Returns a remote bridge connection, using portal connection options and authentication
 @return a remote bridge connection
 */
+ (PHSBridgeConnection *)getBridgeConnectionFromPortalConnection:(id<PHSPortalConnection>)portalConnection forBridge:(PHSBridge *)bridge;

@end
