/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

typedef NS_ENUM(NSInteger, PHSReturnCode) {
    PHSReturnCodeSuccess                         =  0,
    PHSReturnCodeError                           = -1,
    PHSReturnCodeUnknown                         = -2,
    PHSReturnCodeInternal                        = -3,
    PHSReturnCodeNotSupported                    = -4,
    PHSReturnCodeBusy                            = -5,
    PHSReturnCodeErrorLocal                      = -6,
    PHSReturnCodeErrorRemote                     = -7,
    
    PHSReturnCodeNullParameter                   = -101,
    PHSReturnCodeWrongParameter                  = -102,
    PHSReturnCodeUnsupportedParameterType        = -103,
    PHSReturnCodeItemNotFound                    = -104,
    PHSReturnCodeNoParentSet                     = -105,
    PHSReturnCodeNotAllowed                      = -106,
    PHSReturnCodeBridgeNotSet                    = -107,
    
    PHSReturnCodeConnectionFailed                = -201,
    PHSReturnCodeConnectionNotAvailable          = -202,
    PHSReturnCodeConnectionTypeNotAllowed        = -203,
    PHSReturnCodeConnectionNotAuthenticated      = -204,
    PHSReturnCodeAlreadyConnected                = -205,
    PHSReturnCodeInvalidConnectionOptions        = -206,
    PHSReturnCodeConnectionNotLinkedToBridge     = -207,
    PHSReturnCodeResponseCorrupt                 = -208,
    
    PHSReturnCodeDoesNotExist                    = -250,
    
    PHSReturnCodeRequestTimedOut                 = -301,

    PHSReturnCodeCanceled                        = -302,
    PHSReturnCodeStopped                         = -303,
    
    PHSReturnCodeMissingDiscoveryMethods         = -401,
    PHSReturnCodeMissingCallback                 = -402,

    PHSReturnCodeBridgeQueueFull                 = -501,
    
    PHSReturnCodeNotExecuted                     = -502,
    PHSReturnCodeRequestCanceled                 = -503,
    PHSReturnCodeRequestDiscardedByQueue         = -504,
    PHSReturnCodeRetry                           = -505,
    PHSReturnCodeNoResponse                      = -506,
    
    PHSReturnCodeInvalidRequest                  = -602,
    PHSReturnCodeInvalidClient                   = -603,
    PHSReturnCodeAuthorizationCodeExpired        = -604,
    PHSReturnCodeStateMismatch                   = -605,
    PHSReturnCodeParserNotFound                  = -606,
    PHSReturnCodeCouldNotParseResponse           = -607,
    PHSReturnCodeSerializerNotFound              = -608,
    PHSReturnCodeCouldNotSerializeDomainObject   = -609,
    PHSReturnCodeNothingSerialized               = -610,
    PHSReturnCodeInvalidResponse                 = -611,
    PHSReturnCodeAccessTokenMissing              = -612,
    PHSReturnCodeAccessTokenBad                  = -613,
    PHSReturnCodeAccessTokenExpired              = -614,
    PHSReturnCodeLoginRequired                   = -615,
    PHSReturnCodeAuthorizationFailed             = -616,
    PHSReturnCodeAccessTokenBridgeMismatch       = -617,
    PHSReturnCodeRateLimitQuotaViolation         = -618,
    PHSReturnCodeAccessTokenRefreshAttempted     = -619,
    PHSReturnCodeUnknownToken                    = -620,
    
    PHSReturnCodeFirmwareUploadFailed            = -701,
    
    PHSReturnCodeStartMigrationFailed            = -801,
    PHSReturnCodeBackupFailed                    = -802,
    PHSReturnCodeNoBackupDataFound               = -803,
    PHSReturnCodeRestoreFailed                   = -804,
    
    PHSReturnCodeDebuggerActive                  = -998,
    PHSReturnCodeNotImplemented                  = -999
};


