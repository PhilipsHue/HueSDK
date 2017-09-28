/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHSObject.h"
#import "PHSCacheType.h"

@interface PHSQueueOptions : PHSObject

/**
 Whether the optimizer should be enabled. The optimizer can decide to filter queue items on certain conditions.
 - Update light states optimzer:
   Filters all old update light state queue items for the same light id, only the last added will be executed.
 
 - Apply light states on group optimizer:
   Filters all appy group queue items for the same group id, only the last added will be executed.
 */
@property (assign, nonatomic) BOOL optimizerEnabled;

/**
 When the queue on the bridge is full, it will report an error back. By default the queue in the SDK will wait a bit before
 executing the next queue item.
 */
@property (assign, nonatomic) BOOL ignoreSendingTooFast;

/**
 Whether there should be waiting time between between requests.
 If false, the sdk will not wait for response and adds the next queue item to thread pool.
 The thread pool can currently handle up to 8 request in parallel for each connection type (local and remote are supported)
 If true, all the queue items get executed synchronuously
 */
@property (assign, nonatomic) BOOL waitForResponse;

/**
 The type of cache to be used. Possible cache types:
 PHSCacheTypeNormal: Bridge state gets updated after getting a response from the bridge
 PHSCacheTypeDirect: Bridge state gets updated imediately after a command is sent to the bridge.
 PHSCacheTypeDisabled: Bridge state doesn't get updated
 **/
@property (assign, nonatomic) PHSCacheType cacheType;

/**
 Initializer of this class
 Default values:
 - optimizerEnabled:     false
 - ignoreSendingTooFast: false
 - waitForResponse:      false
 */
- (instancetype)init;

/**
 Initializer of this class
 @param optimizerEnabled     See property description
 @param ignoreSendingTooFast See property description
 @param waitForResponse      See property description
 @return instance of PHSQueueOptions with given settings
 */
- (instancetype)initWithOptimizerEnabled:(BOOL)optimizerEnabled ignoreSendingTooFast:(BOOL)ignoreSendingTooFast waitForResponse:(BOOL)waitForResponse;

@end
