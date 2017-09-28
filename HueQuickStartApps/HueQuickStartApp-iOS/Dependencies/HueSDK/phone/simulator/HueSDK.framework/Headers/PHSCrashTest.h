/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"

@interface PHSCrashTest : PHSObject

/**
  Invoke SIGABRT signal
 */
+ (void)invokeSigabrt;

/**
  Invoke SIGABRT signal
 */
+ (void)invokeSigsegv;

@end;

