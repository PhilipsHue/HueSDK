/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHBridgeController.h"

@interface PHBridgeController ()

@property (nonatomic, weak) PHRootViewController* rootViewController;

@property (nonatomic, strong, readwrite) PHSBridge* bridge;
@property (nonatomic, assign) PHSBridgeConnectionEvent lastConnectionEvent;
@property (nonatomic, assign) BOOL canConnect;

@property (nonatomic, assign) BOOL loadingWheelActive;
@property (nonatomic, assign) BOOL alertActive;
@property (nonatomic, assign) BOOL pushlinkActive;

@end

@implementation PHBridgeController

- (instancetype)initWithBridgeInfo:(PHBridgeInfo *)bridgeInfo andRootViewController:(PHRootViewController *)rootViewController andDelegate:(id<PHBridgeControllerDelegate>)delegate {
    self = [super init];
    
    if (self) {
        self.rootViewController = rootViewController;
        
        self.bridge = [self buildBridgeWithInfo:bridgeInfo];
        self.lastConnectionEvent = PHSBridgeConnectionEventNone;
        self.canConnect = YES;
        
        self.loadingWheelActive = NO;
        self.alertActive = NO;
        self.pushlinkActive = NO;
        
        self.delegate = delegate;
    }
    
    return self;
}

- (void)connect {
    if (self.canConnect) {
        self.canConnect = NO;
        
        [self showConnecting];
    
        [self.bridge connect];
    }
}

- (void)disconnect {
    [self.bridge disconnect];
}

#pragma mark - UI

- (void)showConnecting {
    [self dismissAll];
    
    [self.rootViewController showLoadingWheelWithText:NSLocalizedString(@"Connecting", @"Connecting title on loading screen")];
    
    self.loadingWheelActive = YES;
}

- (void)showCouldNotConnect {
    [self dismissAll];
    
    [self.rootViewController presentViewController:[self createCouldNotConnectAlert]];
    
    self.alertActive = YES;
}

- (UIAlertController *)createCouldNotConnectAlert {
    UIAlertController* couldNotConnectAlert = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"Could not connect", @"Title alert when couldn't connect to bridge")
                                                                                 message:@""
                                                                          preferredStyle:UIAlertControllerStyleAlert];
    
    [couldNotConnectAlert addAction:[self createAlertActionForRetry]];
    [couldNotConnectAlert addAction:[self createAlertActionForCancel]];
    
    return couldNotConnectAlert;
}

- (UIAlertAction*)createAlertActionForRetry{
    __weak typeof(self) weakSelf = self;
    
    return [UIAlertAction actionWithTitle:NSLocalizedString(@"Retry", @"Retry button on could not connect alert")
                                    style:UIAlertActionStyleDefault
                                  handler:^(UIAlertAction* action) {
                                      weakSelf.alertActive = NO;
                                      
                                      [weakSelf connect];
                                  }];
}

- (UIAlertAction*)createAlertActionForCancel{
    __weak typeof(self) weakSelf = self;
    
    return [UIAlertAction actionWithTitle:NSLocalizedString(@"Cancel", @"Cancel button on could not connect alert")
                                    style:UIAlertActionStyleDefault
                                  handler:^(UIAlertAction* action) {
                                      weakSelf.alertActive = NO;
                                      
                                      [weakSelf.delegate disconnected];
                                  }];
}

- (void)showConnectionLost {
    [self dismissAll];
    
    [self.rootViewController showLoadingWheelWithText:NSLocalizedString(@"Reconnecting", @"Reconnecting title on loading screen")];
    
    self.loadingWheelActive = YES;
}

- (void)showPushlinkRequired {
    [self dismissAll];
    
    PHBridgePushLinkViewController* pushlinkViewController = [[PHBridgePushLinkViewController alloc] initWithRootViewController:self.rootViewController andDelegate:self];
    
    [self.rootViewController pushViewController:pushlinkViewController];
    
    self.pushlinkActive = YES;
}

- (void)dismissLoadingWheel {
    if (self.loadingWheelActive) {
        [self.rootViewController hideLoadingWheel];
        
        self.loadingWheelActive = NO;
    }
}

- (void)dismissAlert {
    if (self.alertActive) {
        [self.rootViewController dismissViewController];
        
        self.alertActive = NO;
    }
}

- (void)dismissPushlink {
    if (self.pushlinkActive) {
        [self.rootViewController popViewController];
        
        self.pushlinkActive = NO;
    }
}

- (void)dismissAll {
    [self dismissLoadingWheel];
    [self dismissAlert];
    [self dismissPushlink];
}

#pragma mark - PHSBridge

- (PHSBridge *)buildBridgeWithInfo:(PHBridgeInfo *)bridgeInfo {
    // Replace app name and device name
    return [PHSBridge bridgeWithBlock:^(PHSBridgeBuilder* builder) {
        builder.connectionTypes = PHSBridgeConnectionTypeLocal;
        builder.ipAddress = bridgeInfo.ipAddress;
        builder.bridgeID  = bridgeInfo.uniqueId;
        
        builder.bridgeConnectionObserver = self;
        
        [builder addStateUpdateObserver:self];
    } withAppName:@"MyApp" withDeviceName:@"MyDevice"];
}

#pragma mark - PHSBridgeConnectionObserver 

- (void)bridgeConnection:(PHSBridgeConnection *)bridgeConnection handleEvent:(PHSBridgeConnectionEvent)connectionEvent {
    switch (connectionEvent) {
        case PHSBridgeConnectionEventCouldNotConnect:
            [self handleCouldNotConnect];
            break;
        case PHSBridgeConnectionEventConnected:
            // Inform delegate only when also authenticated
            break;
        case PHSBridgeConnectionEventConnectionLost:
            [self handleConnectionLostEvent];
            break;
        case PHSBridgeConnectionEventConnectionRestored:
            [self handleConnectionRestoredEvent];
            break;
        case PHSBridgeConnectionEventDisconnected:
            [self handleDisconnectedEvent];
            break;
            
        case PHSBridgeConnectionEventNotAuthenticated:
        case PHSBridgeConnectionEventLinkButtonNotPressed:
            [self handlePushlinkEvent];
            break;
        case PHSBridgeConnectionEventAuthenticated:
            [self handleAuthenticatedEvent];
            break;
            
        default:
            break;
    }
    
    self.lastConnectionEvent = connectionEvent;
}

- (void)handleCouldNotConnect {
    self.canConnect = YES;
    
    [self showCouldNotConnect];
}

- (void)handleConnectionLostEvent {
    [self showConnectionLost];
}

- (void)handleConnectionRestoredEvent {
    [self dismissAll];
}

- (void)handleDisconnectedEvent {
    self.canConnect = YES;
    
    [self.delegate disconnected];
}

- (void)handlePushlinkEvent {
    if (self.lastConnectionEvent != PHSBridgeConnectionEventNotAuthenticated && self.lastConnectionEvent != PHSBridgeConnectionEventLinkButtonNotPressed) {
        [self showPushlinkRequired];
    }
}

- (void)handleAuthenticatedEvent {
    [self dismissAll];
}

- (void)bridgeConnection:(PHSBridgeConnection *)bridgeConnection handleErrors:(NSArray<PHSError *> *)connectionErrors { }

#pragma mark - PHSBridgeStateUpdateObserver

- (void)bridge:(PHSBridge *)bridge handleEvent:(PHSBridgeStateUpdatedEvent)updateEvent {
    if (updateEvent == PHSBridgeStateUpdatedEventInitialized) {
        [self.delegate connected];
        
        [self startHeartbeat];
    }
}

- (void)startHeartbeat {
    PHSBridgeConnection* connection = self.bridge.bridgeConnections.firstObject;
    
    [connection.heartbeatManager startHeartbeatWithType:PHSBridgeStateCacheTypeFullConfig interval:10];
}

#pragma mark - PHBridgePushLinkViewControllerDelegate

- (void)pushlinkCancelled {
    [self dismissAll];
    
    [self disconnect];
}

@end
