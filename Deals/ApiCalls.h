//
//  ApiCalls.h
//  Deals
//
//  Created by sharanya on 8/3/15.
//  Copyright (c) 2015 sharanya. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"
#import "DealsModal.h"

@protocol RemoteApiProtocol <NSObject>

@optional
- (void)dictDelegate:(NSDictionary *)dealsDict;
@end

@interface ApiCalls : NSObject{
    id <RemoteApiProtocol> delegate;
}
@property (nonatomic, retain) id<RemoteApiProtocol> delegate;

- (void) doSignUp:(id) deleGate;
- (NSDictionary *) handleDealsData:(NSMutableDictionary *)json;

@end
