/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSReturnCode.h"
#import "PHSObject.h"

@class PHSHeartbeatManager;
@class PHSBridgeConnectionOptions;
@class PHSBridge;
@class PHSBridgeConnection;
@class PHSHttpResponse;
@class PHSHttpRequest;
@class PHSError;

typedef NS_ENUM(NSInteger, PHSBridgeConnectionEvent) {
    PHSBridgeConnectionEventNone                         = 0,
    PHSBridgeConnectionEventCouldNotConnect              = 1,
    PHSBridgeConnectionEventConnected                    = 2,
    PHSBridgeConnectionEventNotAuthenticated             = 3,
    PHSBridgeConnectionEventConnectionLost               = 4,
    PHSBridgeConnectionEventConnectionRestored           = 5,
    PHSBridgeConnectionEventDisconnected                 = 6,
    PHSBridgeConnectionEventAuthenticated                = 7,
    PHSBridgeConnectionEventLinkButtonNotPressed         = 8,
    PHSBridgeConnectionEventLoginRequired                = 9,
    PHSBridgeConnectionEventTokenExpired                 = 10,
    PHSBridgeConnectionEventNoBridgeForPortalAccount     = 11,
    PHSBridgeConnectionEventBridgeIdMismatch             = 12,
    PHSBridgeConnectionEventRateLimitQuotaViolation      = 13,
    PHSBridgeConnectionEventTokenUnknown                 = 14,
    PHSBridgeConnectionEventTokenBridgeMismatch          = 15,
};

typedef NS_ENUM(NSInteger, PHSBridgeConnectionState) {
    PHSBridgeConnectionStateDisconnected                = 0,
    PHSBridgeConnectionStateConnecting                  = 1,
    PHSBridgeConnectionStateDisconnecting               = 2,
    PHSBridgeConnectionStateAuthenticating              = 3,
    PHSBridgeConnectionStateAuthenticated               = 4,
    PHSBridgeConnectionStateWaitingForAuthentication    = 5,
    PHSBridgeConnectionStateRestoringConnection         = 6
};


/**
 Bridge connection observer protocol
 This protocol should be implemented by any class that wants to receive bridge connection events and errors
 @see setBridgeConnectionObserver
 */
@protocol PHSBridgeConnectionObserver <NSObject>

/**
 Handle the connection event
 */
- (void)bridgeConnection:(PHSBridgeConnection*)bridgeConnection handleEvent:(PHSBridgeConnectionEvent)connectionEvent;

/**
 Handle the connection errors
 */
- (void)bridgeConnection:(PHSBridgeConnection *)bridgeConnection handleErrors:(NSArray<PHSError*> *)connectionErrors;

@end

/**
 HttpRequest response completion handler block
 The block is used to handle response and errors of an HTTP request
 @param response The HTTP response
 @param errors The errors that are return by the bridge
 */
typedef void (^PHSHttpRequestCompletionHandler)(PHSHttpResponse *response, NSArray<PHSError*> *errors);


@interface PHSBridgeConnection : PHSObject

- (instancetype) init __attribute__((unavailable("init not available")));

/**
 The bridge it connects to
 */
@property (weak, nonatomic, readonly) PHSBridge *bridge;

/**
 The heartbeat manager, will be set after connection is estabilished
 */
@property (strong, nonatomic, readonly) PHSHeartbeatManager *heartbeatManager;

/**
 The connection options
 */
@property (strong, nonatomic) PHSBridgeConnectionOptions *bridgeConnectionOptions;

/**
 @return the current state of the connection
 */
- (PHSBridgeConnectionState)getState;

/**
 @return whether this connection is actually connected
 */
- (BOOL)isConnected;

/**
 @return whether this connection has been authenticated
 */
- (BOOL)isAuthenticated;

/**
 Disconnect this connection
 */
- (void)disconnect;

/**
 Connect to the bridge
 */
- (PHSReturnCode)connect;

/**
 Register for connection events and errors
 @param observer Observer that registers for connection events and errors
 */
- (void)setBridgeConnectionObserver:(id<PHSBridgeConnectionObserver>)observer;

/**
 @param resourcePath      Path that is requested from the bridge
 @param completionHandler Lambda function that is called when the http request has finished
 @return http request object (to be deleted by caller)
 */
- (PHSHttpRequest*)doGet:(NSString*)resourcePath completionHandler:(PHSHttpRequestCompletionHandler)completionHandler;

/**
 Perform http post request
 @param resourcePath      Path that is requested from the bridg)
 @param completionHandler Lambda function hat is called when the http request has finished
 @return http request object (to be deleted by caller)
 */
- (PHSHttpRequest*)doPost:(NSString*)resourcePath withBody:(NSString*)body completionHandler:(PHSHttpRequestCompletionHandler)completionHandler;

/**
 Perform http put request
 @param resourcePath      Path that is requested from the bridge
 @param completionHandler Lambda function that is called when the http request has finished
 @return http request object (to be deleted by caller)
 */
- (PHSHttpRequest*)doPut:(NSString*)resourcePath withBody:(NSString*)body completionHandler:(PHSHttpRequestCompletionHandler)completionHandler;

/**
 Perform http delete request
 @param resourcePath      Path that is requested from the bridge
 @param completionHandler Lambda function that is called when the http request has finished
 @return http request object (to be deleted by caller)
 */
- (PHSHttpRequest*)doDelete:(NSString*)resourcePath completionHandler:(PHSHttpRequestCompletionHandler)completionHandler;

@end
