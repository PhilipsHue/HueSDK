/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSReturnCode.h"
#import "PHSBridgeStateCacheType.h"

@interface PHSHeartbeatManager : NSObject

/**
 Start a heartbeat of a type with a given interval
 @param type     The type of heartbeat you want to start
 @param interval The interval of the heartbeat in seconds
 @return Always returns PHSSucces
 */
- (PHSReturnCode)startHeartbeatWithType:(PHSBridgeStateCacheType)type interval:(NSTimeInterval)interval;

/**
 Stop a heartbeat of a given type
 @param type The type of heartbeat you want to stop
 @return the result code
         PHSReturnCodeSuccess: heartbeat has been stopped successfully
         PHSReturnCodeNotAllowed: it can also be that the heartbeat has been started from internal and then
         it's not allowed to stop the heartbeat
 */
- (PHSReturnCode)stopHeartbeatWithType:(PHSBridgeStateCacheType)type;

/**
 Stops all running heartbeats
 @return the result code
 */
- (PHSReturnCode)stopAllHeartbeats;

/**
 Perform one heartbeat of a type. When called heartbeat will be performed as soon as possible.
 @param type     The type of heartbeat you want to start
 @return Always returns PHSSuccess
 */
- (PHSReturnCode)performOneHeartbeatOfType:(PHSBridgeStateCacheType)type;

/**
 Set whether the bridge state should be updated after performing heartbeat
 This allows you to use heartbeat manager for only checking you connectivity status
 */
- (void)setShouldUpdateBridgeState:(BOOL)shouldUpdateBridgeState;

@end
