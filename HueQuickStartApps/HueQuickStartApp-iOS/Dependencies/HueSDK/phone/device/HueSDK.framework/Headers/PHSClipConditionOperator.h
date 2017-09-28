/*******************************************************************************
 Copyright (c) 2013-2014 Koninklijke Philips N.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSClipConditionOperator) {
    PHSClipConditionOperatorUnknown = -1,
    PHSClipConditionOperatorNone = 0,
    PHSClipConditionOperatorEq = 1,
    PHSClipConditionOperatorGt = 2,
    PHSClipConditionOperatorLt = 3,
    PHSClipConditionOperatorDx = 4,
    PHSClipConditionOperatorDdx = 5,
    PHSClipConditionOperatorStable = 6,
    PHSClipConditionOperatorNotStable = 7,
    PHSClipConditionOperatorIn = 8,
    PHSClipConditionOperatorNotIn = 9
};
