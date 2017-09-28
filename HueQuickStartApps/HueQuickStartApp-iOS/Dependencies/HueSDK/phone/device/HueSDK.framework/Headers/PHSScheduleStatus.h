/*******************************************************************************
 Copyright (c) 2013-2014 Koninklijke Philips N.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSScheduleStatus) {
    PHSScheduleStatusUnknown = -1,
    PHSScheduleStatusNone = 0,
    PHSScheduleStatusEnable = 1,             // Settable to bridge
    PHSScheduleStatusDisable = 2,            // Settable to bridge
    PHSScheduleStatusErrors = 3
};
