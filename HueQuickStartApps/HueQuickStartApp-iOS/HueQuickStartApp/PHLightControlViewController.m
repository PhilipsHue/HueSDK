/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHLightControlViewController.h"
#import "PHSKnownBridges+LastConnectedBridge.h"
#import "PHBridgeInfo.h"

static const int PHMaxHue = 65535;
static const int PHMaxBri = 254;

@interface PHLightControlViewController()

@property (nonatomic, strong) PHBridgeController* bridgeController;
@property (nonatomic, strong) PHBridgeDiscoveryController* bridgeDiscoveryController;

@property (nonatomic, weak) PHRootViewController* rootViewController;

@property (nonatomic, weak) IBOutlet UILabel* bridgeIpLabel;
@property (nonatomic, weak) IBOutlet UILabel* uniqueIdLabel;
@property (nonatomic, weak) IBOutlet UIButton* randomLightsButton;

@end

@implementation PHLightControlViewController

- (instancetype)initWithRootViewController:(PHRootViewController *)rootViewController {
    self = [super init];
    
    if (self) {
        self.rootViewController = rootViewController;
        
        self.bridgeController = [self createBridgeController:[self lastConnectedBridge]];
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setupNavigationBar];
}

- (void)viewDidAppear:(BOOL)animated {
    self.randomLightsButton.enabled = YES;
    
    if (self.isBeingPresented || self.isMovingToParentViewController) {
        if (self.bridgeController == nil) {
            [self discoverBridges];
            
            return;
        }
        
        [self.bridgeController connect];
    }
}

- (PHBridgeDiscoveryController *)bridgeDiscoveryController {
    if (!_bridgeDiscoveryController) {
        _bridgeDiscoveryController = [[PHBridgeDiscoveryController alloc] initWithRootViewController:self.rootViewController andDelegate:self];
    }
    
    return _bridgeDiscoveryController;
}

- (void)discoverBridges {
    [self.bridgeDiscoveryController discoverBridges];
}

- (PHBridgeInfo *)lastConnectedBridge{
    PHSKnownBridge* lastConnectedBridge = [PHSKnownBridges lastConnectedBridge];
    
    if (!lastConnectedBridge) {
        return nil;
    }
    
    return [PHBridgeInfo createWithIpAddress:lastConnectedBridge.ipAddress andUniqueId:lastConnectedBridge.uniqueId];
}

- (PHBridgeController *)createBridgeController:(PHBridgeInfo *)bridgeInfo {
    if (bridgeInfo == nil) {
        return nil;
    }
    
    return [[PHBridgeController alloc] initWithBridgeInfo:bridgeInfo andRootViewController:self.rootViewController andDelegate:self];
}

#pragma mark - UI

- (IBAction)randomizeColors:(id)sender {
    [self randomizeColors];
}

- (void)findNewBridgeButtonAction {
    [self.bridgeDiscoveryController discoverBridges];
}

- (void)setupNavigationBar {
    self.navigationController.navigationBarHidden = NO;
    
    self.navigationItem.hidesBackButton = YES;
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"Find bridge", @"Find bridge button in bar on light control screen")
                                                                              style:UIBarButtonItemStylePlain
                                                                             target:self
                                                                             action:@selector(findNewBridgeButtonAction)];
    
    self.navigationItem.title = NSLocalizedString(@"HueQuickStartApp", @"Title navigation light control screen");
    
    self.edgesForExtendedLayout = UIRectEdgeLeft | UIRectEdgeBottom | UIRectEdgeRight;
}

#pragma mark - Light control

- (void)randomizeColors {
    NSArray<PHSDevice*>* devices = [self.bridgeController.bridge.bridgeState getDevicesOfType:PHSDomainTypeLight];
    
    for (PHSDevice* device in devices) {
        PHSLightPoint* lightPoint = (PHSLightPoint*)device;
        
        PHSLightState* lightState = [self lightStateWithRandomColors];
        
        [lightPoint updateState:lightState allowedConnectionTypes:PHSBridgeConnectionTypeLocal completionHandler:^(NSArray<PHSClipResponse *> *responses, NSArray<PHSError *> *errors, PHSReturnCode returnCode) {
            // ...
        }];
    }
}

- (PHSLightState *)lightStateWithRandomColors {
    PHSLightState* lightState = [PHSLightState new];
    
    lightState.on = @YES;
    lightState.hue = [NSNumber numberWithInt:arc4random() % PHMaxHue];
    lightState.brightness = [NSNumber numberWithInt:PHMaxBri];
    
    return lightState;
}

#pragma mark - PHBridgeControllerDelegate

- (void)connected {
    self.bridgeIpLabel.text = self.bridgeController.bridge.bridgeConfiguration.networkConfiguration.ipAddress;
    
    self.uniqueIdLabel.text = self.bridgeController.bridge.identifier;
}

- (void)disconnected {
    [self discoverBridges];
}

#pragma mark - PHBridgeDiscoveryControllerDelegate

- (void)bridgeSelectedWithIpAddress:(NSString *)ipAddress andUniqueId:(NSString *)uniqueId {
    [self disconnectAndRemoveDelegateFromBridge];
     
    self.bridgeController = [self createBridgeController:[PHBridgeInfo createWithIpAddress:ipAddress andUniqueId:uniqueId]];
    
    [self.bridgeController connect];
}

- (void)disconnectAndRemoveDelegateFromBridge {
    self.bridgeController.delegate = nil;
    
    [self.bridgeController disconnect];
}

@end
