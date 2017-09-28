/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHBridgePushLinkViewController.h"

static const NSTimeInterval PHPushlinkTimeoutSec = 30.0;
static const NSTimeInterval PHPushlinkTimerInterval = 1.0;

@interface PHBridgePushLinkViewController ()

@property (nonatomic, weak) PHRootViewController* rootViewController;

@property (nonatomic, strong) NSTimer* timeoutTimer;
@property (nonatomic, assign) NSTimeInterval remainingTime;
@property (nonatomic, weak) IBOutlet UIProgressView* progressView;

@property (nonatomic, assign) BOOL timeoutAlertActive;

@property (nonatomic, weak) id<PHBridgePushLinkViewControllerDelegate> delegate;

@end

@implementation PHBridgePushLinkViewController

- (instancetype)initWithRootViewController:(PHRootViewController *)rootViewController andDelegate:(id<PHBridgePushLinkViewControllerDelegate>)delegate {
    self = [super init];
    
    if (self) {
        self.rootViewController = rootViewController;
        
        self.timeoutAlertActive = NO;
        
        self.delegate = delegate;
    }

    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.navigationController.navigationBarHidden = YES;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self startTimer];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [self stopTimer];
    
    [self dismissTimeoutAlert];
}


- (UIAlertController *)createTimeoutAlert {
    UIAlertController* timeoutAlert = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"Pushlink failed", @"Title alert when pushlink times out")
                                                        message:@""
                                                 preferredStyle:UIAlertControllerStyleAlert];

    [timeoutAlert addAction:[self createAlertActionForRetry:timeoutAlert]];
    [timeoutAlert addAction:[self createAlertActionForCancel:timeoutAlert]];
    
    
    return timeoutAlert;
}

- (UIAlertAction*)createAlertActionForRetry:(UIAlertController *)alert {
    __weak typeof(self) weakSelf = self;
    
    return [UIAlertAction actionWithTitle:NSLocalizedString(@"Retry", @"Retry button on pushlink timeout")
                                    style:UIAlertActionStyleDefault
                                  handler:^(UIAlertAction* action) {
                                      weakSelf.timeoutAlertActive = NO;
                                      
                                      [weakSelf startTimer];
                                  }];
}

- (UIAlertAction*)createAlertActionForCancel:(UIAlertController *)alert {
    __weak typeof(self) weakSelf = self;
    __weak typeof(self.delegate) weakDelegate = self.delegate;
    
    return [UIAlertAction actionWithTitle:NSLocalizedString(@"Cancel", @"Cancel button on pushlink timeout")
                                    style:UIAlertActionStyleDefault
                                  handler:^(UIAlertAction* action) {
                                      weakSelf.timeoutAlertActive = NO;
                                      
                                      [weakDelegate pushlinkCancelled];
                                  }];
}

- (void)showTimeoutAlert {
    self.timeoutAlertActive = YES;
    
    [self.rootViewController presentViewController:[self createTimeoutAlert]];
}

- (void)dismissTimeoutAlert {
    if (self.timeoutAlertActive) {
        [self.rootViewController dismissViewController];
        
        self.timeoutAlertActive = NO;
    }
}

- (void)startTimer {
    self.progressView.progress = 1.0f;
    self.remainingTime = PHPushlinkTimeoutSec;
    
    self.timeoutTimer = [NSTimer scheduledTimerWithTimeInterval:PHPushlinkTimerInterval
                                                         target:self
                                                       selector:@selector(updateProgress)
                                                       userInfo:nil
                                                        repeats:YES];
}

- (void)stopTimer {
    [self.timeoutTimer invalidate];
}

- (void)updateProgress {
    if (self.remainingTime >= PHPushlinkTimerInterval) {
        self.remainingTime -= PHPushlinkTimerInterval;
    }
    
    self.progressView.progress = self.remainingTime / PHPushlinkTimeoutSec;
    
    if (self.remainingTime == 0) {
        [self stopTimer];
        
        [self showTimeoutAlert];
    }
}

@end
