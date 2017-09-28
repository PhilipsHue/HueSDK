/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSReturnCode.h"

typedef NS_OPTIONS(NSInteger, PHSBridgeDiscoveryOption) {
    PHSDiscoveryOptionUPNP   = 1,
    PHSDiscoveryOptionIPScan = 1 << 1,
    PHSDiscoveryOptionNUPNP  = 1 << 2,
};

@class PHSBridgeDiscoveryResult;

/**
 Bridge discovery results completion handler block
 The block is used to handle the results when doing a search
 @param results    dictionary with PHSBridgeDiscoveryResult object for each bridge that is discovered (unique id as key)
 @param returnCode will return PHSReturnCodeStopped when the search is stopped by the user, and PHSReturnCodeSuccess otherwise
 */
typedef void (^PHSBridgeDiscoveryResultsCompletionHandler)(NSDictionary<NSString*, PHSBridgeDiscoveryResult*>* results, PHSReturnCode returnCode);

@interface PHSBridgeDiscovery : NSObject

/**
 Start searching for bridge
 @param options For all options use (PHSDiscoveryOptionUPNP | PHSDiscoveryOptionIPScan | PHSDiscoveryOptionNUPNP)
 @param completionHandler Block that is called when the search is done
 */
- (void)search:(PHSBridgeDiscoveryOption)options withCompletionHandler:(PHSBridgeDiscoveryResultsCompletionHandler)completionHandler;

- (BOOL)isSearching;
    
- (void)stop;

@end
