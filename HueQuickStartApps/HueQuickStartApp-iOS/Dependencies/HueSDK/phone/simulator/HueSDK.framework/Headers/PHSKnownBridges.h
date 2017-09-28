/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSKnownBridge.h"
#import "PHSBridgeState.h"
#import "PHSReturnCode.h"


@interface PHSKnownBridges : PHSObject

/**
 @returns the list of known bridges (i.e. bridges that the SDK has been connected to)
 */
+ (NSArray<PHSKnownBridge *> *)getAll;

/**
 Forgets a bridge: removes bridge from "known bridges", removes stored username (whitelist entry), and stored bridge state.
 @param bridgeId ID of the bridge which to forget
 @returns PHSReturnCodeSuccess on success, or else PHSReturnCodeWrongParameter or PHSReturnCodeDoesNotExist or PHSReturnCodeInternal
 */
+ (PHSReturnCode)forgetBridge:(NSString *)bridgeId;

/**
 Forget all bridges: removes bridges from "known bridges", removes stored username (whitelist entry), and stored bridge state.
 @returns PHSReturnCodeSuccess on success, or else PHSReturnCodeError
 */
+ (PHSReturnCode)forgetAllBridges;

/**
 Retrieve bridge state with the given mac from the storage
 @note Please note that the returned bridge state is not linked to any bridge and
 can only be used for retrieving devices and resources. The refresh method
 for example will not work, because the bridge state has no parent
 @param bridgeId The bridge id to retrieve the bridge state for (case sensitive)
 @return The bridge state, nil if not found
 */
+ (PHSBridgeState *)retrieveBridgeState:(NSString *)bridgeId;

/**
 Retrieve the stored whitelist entry for the specified bridge id
 @param bridgeId The bridge id to retrieve the whitelist entry for
 @return The whitelist entry, or nil if not found
 */
+ (NSString *)retrieveWhitelistEntry:(NSString *)bridgeId;

/**
 Removes the bridge state from persistence
 @param bridgeId The unique id of the bridge whose state will be removed from persistence
 @return ReturnCode.RETURN_CODE_SUCCESS if the bridge state was successfully removed from persistence, or if it was already not present.
 ReturnCode.RETURN_CODE_INTERNAL In case of failure
 */
+ (PHSReturnCode)removeBridgeState:(NSString *)bridgeId;

/**
 Removes the stored whilist entry from persistence for the specified bridge id
 @param bridgeId The unique id of the bridge whose whitelist will be removed from persistence
 @return ReturnCode.RETURN_CODE_SUCCESS if the bridge whitelist entry was successfully removed from persistence, or if it was already not present.
 ReturnCode.RETURN_CODE_INTERNAL In case of failure
 */
+ (PHSReturnCode)removeWhitelistEntry:(NSString *)bridgeId;

@end
