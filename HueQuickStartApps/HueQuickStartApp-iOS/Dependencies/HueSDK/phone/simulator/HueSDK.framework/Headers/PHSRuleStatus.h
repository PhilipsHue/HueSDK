/*******************************************************************************
 Copyright (c) 2013-2014 Koninklijke Philips N.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSRuleStatus) {
    PHSRuleStatusUnknown = -1,
    PHSRuleStatusNone = 0,
    PHSRuleStatusEnable = 1,             // Settable to bridge
    PHSRuleStatusDisable = 2,            // Settable to bridge
    PHSRuleStatusLoopError = 3,
    PHSRuleStatusResourceDeleted = 4,
    PHSRuleStatusErrors = 5
};
