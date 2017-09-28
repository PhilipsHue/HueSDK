/*******************************************************************************
 Copyright (C) 2017 Philips Lighting Holding B.V.
 All Rights Reserved.
 ********************************************************************************/

#import "PHBridgeSelectionViewController.h"
#import "PHAppDelegate.h"

static NSString* PHBridgeSelectionCellIdentifier = @"DiscoveredBridgeCell";

@interface PHBridgeSelectionViewController ()

@property (nonatomic, strong) NSArray<PHSBridgeDiscoveryResult *>* discoveredBridges;

@property (nonatomic, weak) id<PHBridgeSelectionViewControllerDelegate> delegate;

@end

@implementation PHBridgeSelectionViewController

- (instancetype)initWithDiscoveredBridges:(NSDictionary<NSString *, PHSBridgeDiscoveryResult *> *)bridges andDelegate:(id<PHBridgeSelectionViewControllerDelegate>)delegate {
    self = [super init];

    if (self) {
        self.discoveredBridges = [self bridgesDictionaryToArray:bridges];
        
        self.delegate = delegate;
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setupNavigationBar];
    
    [self.tableView reloadData];
}

- (IBAction)refreshButtonClicked:(id)sender {
    [self.delegate refreshBridges];
}

- (NSArray *)bridgesDictionaryToArray:(NSDictionary<NSString *, PHSBridgeDiscoveryResult *> *)bridgesDictionary {
    // Add sorting here...
    
    return [bridgesDictionary allValues];
}

#pragma mark - UI

- (void)setupNavigationBar {
    self.navigationItem.hidesBackButton = YES;
    
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemRefresh
                                                                                           target:self
                                                                                           action:@selector(refreshButtonClicked:)];
    
    self.navigationItem.title = NSLocalizedString(@"Bridges", @"Title navigation found bridges screen");
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.discoveredBridges.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:PHBridgeSelectionCellIdentifier];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle
                                      reuseIdentifier:PHBridgeSelectionCellIdentifier];
    }
    
    PHSBridgeDiscoveryResult* discoveredBridge = self.discoveredBridges[indexPath.row];
    
    cell.textLabel.text = discoveredBridge.ipAddress;
    cell.detailTextLabel.text = discoveredBridge.uniqueId;
    
    return cell;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return NSLocalizedString(@"Please select a bridge to connect to", @"Header bridge selection view");
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    PHSBridgeDiscoveryResult* discoveredBridge = self.discoveredBridges[indexPath.row];
    
    [self.delegate bridgeSelectedWithIpAddress:discoveredBridge.ipAddress andUniqueId:discoveredBridge.uniqueId];
}

@end
