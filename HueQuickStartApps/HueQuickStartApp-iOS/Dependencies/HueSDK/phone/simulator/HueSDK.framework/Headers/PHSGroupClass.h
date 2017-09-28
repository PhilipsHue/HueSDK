/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSGroupClass) {
    PHSGroupClassUnknown = -1,
    PHSGroupClassNone    = 0,
    
    // Rooms
    PHSGroupClassLivingGroup,
    PHSGroupClassKitchen,
    PHSGroupClassDining,
    PHSGroupClassBedGroup,
    PHSGroupClassKidsBedGroup,
    PHSGroupClassBathGroup,
    PHSGroupClassNursery,
    PHSGroupClassRecreation,
    PHSGroupClassOffice,
    PHSGroupClassGym,
    PHSGroupClassHallway,
    PHSGroupClassToilet,
    PHSGroupClassFrontDoor,
    PHSGroupClassGarage,
    PHSGroupClassTerrace,
    PHSGroupClassGarden,
    PHSGroupClassDriveway,
    PHSGroupClassCarport,
    
    // Entertainment
    PHSGroupClassTV,
    PHSGroupClassFree,
    
    PHSGroupClassOther
};
