/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSGroupType) {
    PHSGroupTypeUnknown    = -1,
    PHSGroupTypeLightGroup = 0,
    PHSGroupTypeLightSource,
    PHSGroupTypeLuminaire,
    PHSGroupTypeRoom,
    PHSGroupTypeEntertainment
};
