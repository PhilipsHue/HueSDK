/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSResourceLinkType) {
    PHSResourceLinkTypeUnknown = -1,
    PHSResourceLinkTypeNone = 0, // It is unkown what the current link type value is
    PHSResourceLinkTypeLink, // Generic resource link
};
