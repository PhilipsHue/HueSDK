/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PHSClipErrorType) {
    PHSClipErrorTypeUnknown                                  = -1,   // -1
    
    PHSClipErrorTypeNone                                     = 0,    // 0
    PHSClipErrorTypeUnauthorizedUser                         = 1,    // 1
    PHSClipErrorTypeInvalidJson,                                     // 2
    PHSClipErrorTypeResourceNotAvailable,                            // 3
    PHSClipErrorTypeMethodNotAvailable,                              // 4
    PHSClipErrorTypeMissingParameter,                                // 5
    PHSClipErrorTypeParameterNotAvailable,                           // 6
    PHSClipErrorTypeInvalidParameter,                                // 7
    PHSClipErrorTypeParameterReadOnly,                               // 8
    PHSClipErrorTypeBusyChangingChannel,                             // 9
    PHSClipErrorTypeParameterChangeAlreadyInProgress,                // 10
    PHSClipErrorTypeTooManyItemsInList,                              // 11
    PHSClipErrorTypePortalConnectionRequired,                        // 12
    
    PHSClipErrorTypeLinkButtonNotPressed                     = 101,  // 101
    
    PHSClipErrorTypeCanNotDisableDHCP                        = 110,  // 110
    PHSClipErrorTypeInvalidUpdateState,                              // 111
    
    PHSClipErrorTypeChangeParameterFailedDeviceIsOff         = 201,  // 201
    
    PHSClipErrorTypeTooManyGroups                            = 301,  // 301
    PHSClipErrorTypeTooManyDeviceGroups,                             // 302
    PHSClipErrorTypeDeviceToAddToGroupIsUnreachable,                 // 303
    PHSClipErrorTypeDeviceToAddToSceneIsUnreachable,                 // 304
    PHSClipErrorTypeGroupReadOnly,                                   // 305
    PHSClipErrorTypeLightCanOnlyBeInOneRoom,                         // 306
    PHSClipErrorTypeCannotClaimStreamOwnership,                      // 307
    
    PHSClipErrorTypeSceneCreationBusy                        = 401,  // 401
    PHSClipErrorTypeTooManyScenes,                                   // 402
    
    PHSClipErrorTypeCreateSensorTypeNotAllowed               = 501,  // 501
    PHSClipErrorTypeTooManySensors,                                  // 502
    
    PHSClipErrorTypeTooManyRules                             = 601,  // 601
    PHSClipErrorTypeNotAResource                             = 603,  // 603
    PHSClipErrorTypeOperatorNotSupported,                            // 604
    PHSClipErrorTypeHttpMethodNotSupported,                          // 605
    PHSClipErrorTypeBoydNotSupported,                                // 606
    PHSClipErrorTypeInvalidRuleCondition,                            // 607
    PHSClipErrorTypeInvalidRuleAction,                               // 608
    PHSClipErrorTypeCanNotActivateRule,                              // 609
    
    PHSClipErrorTypeTooManySchedules                         = 701,  // 701
    PHSClipErrorTypeInvalidTimezone,                                 // 702
    PHSClipErrorTypeTimeLocalTimeConflict,                           // 703
    PHSClipErrorTypeInvalidTag,                                      // 704
    PHSClipErrorTypeScheduleHasExpired,                              // 705
    PHSClipErrorTypeCommandOnUnsupportedResource,                    // 706
    
    PHSClipErrorTypeSceneCreatedOnUpdate                     = 801,  // 801
    
    PHSClipErrorTypeInternal                                 = 901,  // 901
};
