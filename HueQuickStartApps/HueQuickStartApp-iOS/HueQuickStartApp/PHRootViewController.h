/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <UIKit/UIKit.h>

@interface PHRootViewController : UIViewController

- (void)pushViewController:(UIViewController *)viewController;
- (void)popViewController;

- (void)presentViewController:(UIViewController *)viewController;
- (void)dismissViewController;

- (void)showLoadingWheelWithText:(NSString *)text;
- (void)hideLoadingWheel;

@end
