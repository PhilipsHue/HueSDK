/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"
#import "PHSDomainType.h"
#import "PHSBridgeConnectionType.h"
#import "PHSReturnCode.h"
#import "PHSBridgeResponseCompletionHandler.h"

@class PHSBridge;

@interface PHSDomainObject : PHSObject

/**
 The domain object type
 */
@property (strong, nonatomic) NSString *identifier;

/**
 The domain object type
 */
@property (readonly, nonatomic) PHSDomainType domainType;

/**
 The parent object
 */
@property (weak, nonatomic, readonly) PHSDomainObject *parent;

/**
 The bridge related to this domain object
 */
@property (weak, nonatomic, readonly) PHSBridge *bridge;

/**
 Fetch the scene data from the bridge
 @note Make sure this object is alive when fetching the data. If the object gets out of scope for some reason
 the fetch will be cancelled.
 @note During the fetch this object should not be changed
 @param allowedConnectionTypes How to connect to the bridge
 @param completionHandler Completionhandler to be called after recalling the scene
 */
- (void)fetchWithAllowedConnections:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Fetch the domain object data from the given bridge
 @note Make sure this object is alive when fetching the data. If the object gets out of scope for some reason
 the fetch will be cancelled.
 @note During the fetch this object should not be changed
 @param bridge The bridge to get the scene data from
 @param allowedConnectionTypes How to connect to the bridge
 @param completionHandler Completionhandler to be called after recalling the scene
 */
- (void)fetchWithBridge:(PHSBridge *)bridge allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

@end
