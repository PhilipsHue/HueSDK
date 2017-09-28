/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"
#import "PHSHttpMonitorObserver.h"

@interface PHSHttpMonitor : PHSObject

+(void) addObserver:(id<PHSHttpMonitorObserver>) observer;
+(void) removeObserver:(id<PHSHttpMonitorObserver>) observer;

@end
