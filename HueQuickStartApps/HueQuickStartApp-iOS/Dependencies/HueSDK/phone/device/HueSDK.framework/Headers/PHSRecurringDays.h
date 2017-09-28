/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

typedef NS_OPTIONS(NSInteger, PHSRecurringDays) {
    PHSRecurringDayNone      = 0,
    PHSRecurringDayMonday    = 1 << 6,
    PHSRecurringDayTuesday   = 1 << 5,
    PHSRecurringDayWednesday = 1 << 4,
    PHSRecurringDayThursday  = 1 << 3,
    PHSRecurringDayFriday    = 1 << 2,
    PHSRecurringDaySaturday  = 1 << 1,
    PHSRecurringDaySunday    = 1 << 0,
    PHSRecurringDayWeekdays  = 124,
    PHSRecurringDayWeekend   = 3,
    PHSRecurringDayAllDays   = 127,
};
