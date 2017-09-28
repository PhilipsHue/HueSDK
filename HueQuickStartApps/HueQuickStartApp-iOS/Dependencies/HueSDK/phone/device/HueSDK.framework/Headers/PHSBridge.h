/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import <Foundation/Foundation.h>
#import "PHSDevice.h"
#import "PHSBridgeResponseCompletionHandler.h"
#import "PHSFindNewDevicesCallback.h"
#import "PHSBridgeConnectionType.h"
#import "PHSBridgeState.h"
#import "PHSBridgeConnection.h"
#import "PHSQueueType.h"

@class PHSBridgeConfiguration;
@class PHSBridgeResource;
@class PHSDevice;
@class PHSQueueOptions;

@interface PHSBridge : PHSDevice

@property (strong, nonatomic, readonly) PHSBridgeState *bridgeState;

@property (strong, nonatomic, readonly) PHSBridgeConfiguration *bridgeConfiguration;

/**
 Connect each configured connection
 @return PHSReturnCodeSuccess when it has successfully started connecting, otherwise PHSReturnCodeError, PHSReturnCodeErrorLocal or PHSReturnCodeErrorRemote
 */
- (PHSReturnCode)connect;

/**
 Connect connection(s) of specified type(s)
 @param  connectionTypes types of connections to connect
 @return PHSReturnCodeSuccess when it has successfully started connecting, otherwise PHSReturnCodeError, PHSReturnCodeErrorLocal or PHSReturnCodeErrorRemote
 */
- (PHSReturnCode)connectWithConnectionTypes:(PHSBridgeConnectionType)connectionTypes;

/**
 Disconnect from each configured connection
 */
- (void)disconnect;

/**
 Disconnect connection(s) of specified type(s)
 @param  connectionTypes types of connections to disconnect
 */
- (void)disconnectWithConnectionTypes:(PHSBridgeConnectionType)connectionTypes;

/**
 Create a device
 @param device                 Device to create
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when device creation has finished
 */
- (void)createDevice:(PHSDevice *)device allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Create a device
 @param device            Device to create
 @param completionHandler Block to call when device creation has finished
 */
- (void)createDevice:(PHSDevice *)device completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Delete a device
 @param device                 Device to create
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when device deletion has finished
 */
- (void)deleteDevice:(PHSDevice *)device allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Delete a device
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param device            Device to create
 @param completionHandler Block to call when device deletion has finished
 */
- (void)deleteDevice:(PHSDevice *)device completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Create a bridge resource
 @param resource               Resource to create
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when resource creation has finished
 */
- (void)createResource:(PHSBridgeResource *)resource allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Create a bridge resource
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param  resource          Resource to create
 @param  completionHandler Block to call when resource creation has finished
 */
- (void)createResource:(PHSBridgeResource *)resource completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;


/**
 Update a bridge resource
 @param resource               Resource with new values
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when resource creation has finished
 */
- (void)updateResource:(PHSBridgeResource *)resource allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Update a bridge resource
 @param resource               Resource with new values
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when resource creation has finished
 @param sendDeltasOnly         Whether to send only the differences with the cache to the bridge
 */
- (void)updateResource:(PHSBridgeResource *)resource allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler sendDeltasOnly:(BOOL)sendDeltasOnly;

/**
 Update a bridge resource
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param resource          Resource with new values
 @param completionHandler Block to call when resource creation has finished
 */
- (void)updateResource:(PHSBridgeResource *)resource completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Delete a bridge resource
 @param resource               Resource to delete
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when resource deletion has finished
 */
- (void)deleteResource:(PHSBridgeResource *)resource allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Delete a bridge resource
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param  resource          Resource to delete
 @param  completionHandler Block to call when resource deletion has finished
 */
- (void)deleteResource:(PHSBridgeResource *)resource completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Find specific devices
 @param hexDevices             Specific device to search for
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param callback               Callback called during the search, with results, and when the search is finished
 */
- (void)findNewDevices:(NSArray*)hexDevices allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes callback:(id<PHSFindNewDevicesCallback>)callback;

/**
 Find specific devices
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param hexDevices Specific device to search for
 @param callback               Callback called during the search, with results, and when the search is finished
 */
- (void)findNewDevices:(NSArray*)hexDevices callback:(id<PHSFindNewDevicesCallback>)callback;

/**
 Find new devices of certain type(s)
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param callback               Callback called during the search, with results, and when the search is finished
 */
- (void)findNewDevicesWithAllowedConnections:(PHSBridgeConnectionType)allowedConnectionTypes callback:(id<PHSFindNewDevicesCallback>)callback;

/**
 Extend the search for specific devices
 @param hexDevices  Specific device to search for
 @return PHSReturnCodeSuccess or PHSReturnCodeBusy
 */
- (PHSReturnCode)extendFindNewDevices:(NSArray*)hexDevices;

/**
 Extend the search for devices
 @return PHSReturnCodeSuccess or PHSReturnCodeBusy
 */
- (PHSReturnCode)extendFindNewDevices;

/**
 Upload and install the given bridge firmware
 @note Works only on local connections !
 @param file              The file which contains the data of the firmware
 @param completionHandler Block to call when bridge recieved the uploaded firmware file and is triggered to start installation
 */
- (void)updateFirmwareFile:(NSData*)file completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Start installation of the bridge firmware which is already downloaded
 to the bridge (from the portal).
 @note calling this constitutes acceptance by the app of notification of the firmware update
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when bridge is triggered to start installation
 */
- (void)updateFirmwareWithAllowedConnections:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Start the backup on the bridge. The bridge will reboot and create a backup file
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param completionHandler Block to call when the migration has been started
 */
- (void)startBackup:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Start the backup on the bridge. The bridge will reboot and create a backup file
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when the migration has been started
 */
- (void)startBackupWithAllowedConnections:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Download the backup and store it in persistence
 @note Before calling backup() to start downloaded the created file, wait until the backup status in the bridge config
       states that the file is ready for download
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param completionHandler Block to call when the backup has been downloaded and persisted
 */
- (void)backup:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Download the backup and store it in persistence
 @note Before calling backup() to start downloaded the created file, wait until the backup status in the bridge config
 states that the file is ready for download
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler      Block to call when the backup has been downloaded and persisted
 */
- (void)backupWithAllowedConnections:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Restore a backup from a certain bridge. The backup will be loaded from the persistence
 by the given bridge id and uploaded to this bridge
 @note uses default connection type PHSBridgeConnectionTypeLocalRemote (local has priority over remote)
 @param bridgeId          The unique id of the bridge
 @param completionHandler Block to call when the backup has been restored
 */
- (void)restore:(NSString*)bridgeId completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Restore a backup from a certain bridge. The backup will be loaded from the persistence
 by the given bridge id and uploaded to this bridge
 @param bridgeId               The unique id of the bridge
 @param allowedConnectionTypes Allowed connections to use for the operation
 @param completionHandler Block to call when the backup has been restored
 */
- (void)restore:(NSString*)bridgeId allowedConnectionTypes:(PHSBridgeConnectionType)allowedConnectionTypes completionHandler:(PHSBridgeResponseCompletionHandler)completionHandler;

/**
 Set queue type
 @note By default the smart queue is used
 */
- (PHSReturnCode)setQueueType:(PHSQueueType)queueType;

/**
 Set queue options for all connection types
 */
- (PHSReturnCode)setQueueOptions:(PHSQueueOptions *)options;

/**
 Set queue options for the given connection type
 @param connectionType connection type to set the queue items for
        supported: PHSBridgeConnectionTypeLocal, PHSBridgeConnectionTypeRemote
 @param options queue options
 */
- (PHSReturnCode)setQueueOptions:(PHSBridgeConnectionType)connectionType options:(PHSQueueOptions *)options;

/**
 Get all bridge connections
 @return a list of brigde connections
 */
- (NSArray<PHSBridgeConnection *> *)bridgeConnections;

/**
 Remove a bridge connection
 @param bridgeConnection Bridge connection
 */
- (void)removeBridgeConnection:(PHSBridgeConnection **)bridgeConnection;

/**
 Get a specific bridge connection
 @param  connectionType Connection type
 @return the bridge connection of the specified type
 */
- (PHSBridgeConnection *)getBridgeConnection:(PHSBridgeConnectionType)connectionType;

/**
 Check wether bridge is connected to atleast one of its connections
 @return whether a brigde is connected
 */
- (BOOL)isConnected;

/**
 Add observer that will be called when the bridge state object gets updated
 */
- (void)addStateUpdateObserver:(id<PHSBridgeStateUpdateObserver>)observer;

/**
 Remove observer that will be called when the bridge state object gets updated
 */
- (void)removeStateUpdateObserver:(id<PHSBridgeStateUpdateObserver>)observer;

/**
 Register observer for connection events and errors
 */
- (void)setBridgeConnectionObserver:(id<PHSBridgeConnectionObserver>)observer;

@end
