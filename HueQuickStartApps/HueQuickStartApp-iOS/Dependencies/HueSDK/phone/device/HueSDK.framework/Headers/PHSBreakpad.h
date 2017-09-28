/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSObject.h"
#import "PHSReturnCode.h"

@protocol PHSBreakpadCallback <NSObject>

/**
 Function that is called by Breakpad, notifying that a crash dump file was created.
 @param dumpFilePath path to the dump file
 */
- (void)dumpNotifcation:(NSString*)dumpFilePath;

@end

@interface PHSBreakpad : PHSObject

/**
 @return The SDK version string
 */
+ (PHSReturnCode)setupWithDumpPath:(NSString*)dumpFolderPath callback:(id<PHSBreakpadCallback>)callback;

/**
 @return path to latest crash dump file
 */
+ (NSString*)getLatestDumpFilePath;

+ (BOOL)isDebuggerActive;

@end;
