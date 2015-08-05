//
//  ViewController.h
//  Deals
//
//  Created by sharanya on 8/3/15.
//  Copyright (c) 2015 sharanya. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ApiCalls.h"

@interface ViewController : UIViewController<RemoteApiProtocol> {
    ApiCalls * service;
}
@property (nonatomic, strong) ApiCalls * service;

- (IBAction)buttonSelected:(id)sender;
- (IBAction)button1Selected:(id)sender;

@end

