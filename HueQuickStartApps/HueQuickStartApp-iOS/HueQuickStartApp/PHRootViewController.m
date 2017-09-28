/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHRootViewController.h"
#import "PHLightControlViewController.h"

@interface PHRootViewController ()

@property (nonatomic, weak) IBOutlet UIView* childNavigationControllerContainerView;
@property (nonatomic, weak) IBOutlet UIView* activityIndicatorContainerView;

@property (nonatomic, weak) IBOutlet UILabel* messageLabel;

@property (nonatomic, weak) UINavigationController* navigationController;

@end

@implementation PHRootViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.messageLabel.numberOfLines = 0;
    
    [self setupChildController];
}

- (void)setupChildController {
    PHLightControlViewController* lightViewController = [[PHLightControlViewController alloc] initWithRootViewController:self];
    
    UINavigationController* navigationController = [[UINavigationController alloc] initWithRootViewController:lightViewController];
    
    [self addChildViewController:navigationController];
    
    self.navigationController = navigationController;
    self.navigationController.view.frame = self.childNavigationControllerContainerView.frame;
    
    [self.childNavigationControllerContainerView addSubview:self.navigationController.view];
    
    [self.navigationController didMoveToParentViewController:self];
}

- (void)pushViewController:(UIViewController *)viewController {
    __weak typeof(self) weakSelf = self;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [weakSelf.navigationController pushViewController:viewController animated:NO];
    });
}

- (void)popViewController {
    __weak typeof(self) weakSelf = self;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [weakSelf.navigationController popViewControllerAnimated:NO];
    });
}

- (void)presentViewController:(UIViewController *)viewController {
    __weak typeof(self) weakSelf = self;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [weakSelf presentViewController:viewController animated:NO completion:nil];
    });
}

- (void)dismissViewController {
    __weak typeof(self) weakSelf = self;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [weakSelf dismissViewControllerAnimated:NO completion:nil];
    });
}

- (void)showLoadingWheelWithText:(NSString *)text {
    self.messageLabel.text = text;
    
    self.activityIndicatorContainerView.hidden = NO;
}

- (void)hideLoadingWheel {
    self.activityIndicatorContainerView.hidden = YES;
}

@end
