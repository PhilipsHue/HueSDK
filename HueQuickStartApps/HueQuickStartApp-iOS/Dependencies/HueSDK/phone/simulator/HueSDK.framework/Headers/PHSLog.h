/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSLogLevel) {
    PHSLogLevelOff = 0, // Disable logging
    PHSLogLevelError = 1,
    PHSLogLevelWarn = 2,
    PHSLogLevelInfo = 3,
    PHSLogLevelDebug = 4
};

typedef NS_ENUM(NSInteger, PHSLogComponent) {
    PHSLogComponentCore = 1,
    PHSLogComponentSupport = 2,
    PHSLogComponentNetwork = 4,
    PHSLogComponentWrapper = 8,
    PHSLogComponentClient = 16,
    PHSLogComponentColorConversion = 32,
    PHSLogComponentAll = 63,
};

@interface PHSLog : NSObject

/**
 Set log level for the console logger
 @param logLevel The logging level
 */
+ (void)setConsoleLogLevel:(PHSLogLevel)logLevel;

/**
 Set log level for the console logger
 @param logLevel   The logging level
 @param components The enabled components
 */
+ (void)setConsoleLogLevel:(PHSLogLevel)logLevel enabledComponents:(PHSLogComponent)components;

/**
 Set log level for the file logger
 Logs will be saved in the persistence storage folder in the format YYYY-MM-DDTHH-MM-SS.sss.log
 @param logLevel   The logging level
 @param components The enabled component
 */
+ (void)setFileLogLevel:(PHSLogLevel)logLevel enabledComponents:(PHSLogComponent)components;

@end
