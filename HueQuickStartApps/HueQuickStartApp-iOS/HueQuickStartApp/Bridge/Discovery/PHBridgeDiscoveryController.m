/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHBridgeDiscoveryController.h"

#import <HueSDK/HueSDK.h>
#import <HueSDK/PHSCrashTest.h>

@interface PHBridgeDiscoveryController ()

@property (nonatomic, weak) PHRootViewController *rootViewController;

@property (nonatomic, strong) PHSBridgeDiscovery* bridgeDiscovery;
@property (nonatomic, assign) BOOL inProgress;

@property (nonatomic, weak) id<PHBridgeDiscoveryControllerDelegate> delegate;

@end

@implementation PHBridgeDiscoveryController

- (instancetype)initWithRootViewController:(PHRootViewController *)rootViewController andDelegate:(id<PHBridgeDiscoveryControllerDelegate>)delegate {
    self = [super init];
    
    if (self) {
        self.rootViewController = rootViewController;
        
        self.bridgeDiscovery = [PHSBridgeDiscovery new];
        self.inProgress = NO;
        
        self.delegate = delegate;
    }
    
    return self;
}

- (void)discoverBridges {
    if (self.inProgress) {
        return;
    }
    
    self.inProgress = YES;
    
    PHSBridgeDiscoveryOption options = PHSDiscoveryOptionUPNP | PHSDiscoveryOptionNUPNP | PHSDiscoveryOptionIPScan ;
    
    __weak typeof(self) weakSelf = self;

    [self.bridgeDiscovery search:options withCompletionHandler:^(NSDictionary<NSString *,PHSBridgeDiscoveryResult *> *results, PHSReturnCode returnCode) {
        [weakSelf.rootViewController hideLoadingWheel];
        
        weakSelf.inProgress = NO;
        
        if (results.count == 0) {
            [weakSelf showNoBridgesFound];
            return;
        }
        
        [weakSelf showBridgeSelection:results];
    }];
    
    [self showSearchInProgress];
}

#pragma mark - UI

- (void)showNoBridgesFound {
    [self.rootViewController presentViewController:[self createNoBridgesFoundAlert]];
}

- (UIAlertController *)createNoBridgesFoundAlert {
    UIAlertController* noBridgesFoundAlert = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"No bridges found", @"Title alert when no bridges found")
                                                                   message:@""
                                                            preferredStyle:UIAlertControllerStyleAlert];
        
    [noBridgesFoundAlert addAction:[self createAlertActionForRetry:noBridgesFoundAlert]];

    return noBridgesFoundAlert;
}

- (UIAlertAction*)createAlertActionForRetry:(UIAlertController *)alert {
    __weak typeof(self) weakSelf = self;
    
    return [UIAlertAction actionWithTitle:NSLocalizedString(@"Retry", @"Retry button on pushlink timeout")
                                    style:UIAlertActionStyleDefault
                                  handler:^(UIAlertAction* action) {
                                      [weakSelf discoverBridges];
                                  }];
}

- (void)showSearchInProgress {
    [self.rootViewController showLoadingWheelWithText:NSLocalizedString(@"Searching for bridges", @"Discovery loading text")];
}

- (void)showBridgeSelection:(NSDictionary<NSString *,PHSBridgeDiscoveryResult *> *)results {
    PHBridgeSelectionViewController *selectionViewController = [[PHBridgeSelectionViewController alloc] initWithDiscoveredBridges:results
                                                                                                                      andDelegate:self];
    
    [self.rootViewController pushViewController:selectionViewController];
}
#pragma mark - PHBridgeSelectionViewControllerDelegate delegate

- (void)bridgeSelectedWithIpAddress:(NSString *)ipAddress andUniqueId:(NSString *)uniqueId {
    [self.rootViewController popViewController];
    
    [self.delegate bridgeSelectedWithIpAddress:ipAddress andUniqueId:uniqueId];
}

- (void)refreshBridges {
    [self.rootViewController popViewController];
    
    [self discoverBridges];
}

@end
