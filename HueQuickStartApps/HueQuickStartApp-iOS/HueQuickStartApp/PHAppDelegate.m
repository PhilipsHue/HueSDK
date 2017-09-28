/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <HueSDK/HueSDK.h>
#import <HueSDK/PHSCrashTest.h>
#import <HueSDK/PHSBreakpad.h>

#import "PHAppDelegate.h"
#import "PHRootViewController.h"

@interface PHBreakpadCallback : NSObject<PHSBreakpadCallback>

@end

@implementation PHBreakpadCallback

- (void)dumpNotifcation:(NSString*)dumpFilePath{
    // ...
}

@end


@interface PHAppDelegate ()

@property (nonatomic, strong) PHBreakpadCallback* breakpadCallback;

@property (nonatomic, strong) UINavigationController* navigationController;

@end

@implementation PHAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [self configureSDK];
    
    PHRootViewController* rootViewController = [PHRootViewController new];
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.rootViewController = rootViewController;
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (NSURL *)storageDirectoryWithFileManager:(NSFileManager *)fileManager {
    // Create the persistent store
    NSURL *appGroupContainerURL = [fileManager containerURLForSecurityApplicationGroupIdentifier:@"com.philips.lighting.hue.demo"];
    
    return appGroupContainerURL;
}


- (void)configureSDK {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
 
    self.breakpadCallback = [PHBreakpadCallback new];
    
    [PHSBreakpad setupWithDumpPath:documentsDirectory callback:self.breakpadCallback];
    
    // Replace device id
    [PHSPersistence setStorageLocation:documentsDirectory andDeviceId:@"DeviceId"];
    
    [PHSLog setConsoleLogLevel:PHSLogLevelDebug];
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
