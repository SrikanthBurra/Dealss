//
//  ApiCalls.m
//  Deals
//
//  Created by sharanya on 8/3/15.
//  Copyright (c) 2015 sharanya. All rights reserved.
//

#import "ApiCalls.h"
#import "AFHTTPRequestOperationManager.h"

@implementation ApiCalls
@synthesize delegate = _delgate;

- (void) doSignUp:(id) deleGate {
    
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://www.desidime.com/api/v1/premium_deals/list"]];
    
    
    [request setHTTPMethod:@"POST"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Accept"];
    [request setValue:@"text/javascript" forHTTPHeaderField:@"Accept"];
    
    AFHTTPRequestOperation *operation = [[AFHTTPRequestOperation alloc] initWithRequest:request];
    operation.responseSerializer = [AFJSONResponseSerializer serializer];
    [operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id result) {
        //NSLog(@"Success 2: %@", result);
        NSDictionary *dictRes = [self handleDealsData:result];
        
        //[deleGate performSelectorOnMainThread:selector withObject:dictRes waitUntilDone:YES];
        [deleGate dictDelegate:dictRes];
        //delegate = del;
        
        
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        NSLog(@"Error 2: %@", error);
        
    }];
    [operation start];
    
}

- (NSDictionary *) handleDealsData:(NSMutableDictionary *)json {
    NSDictionary *dict;
    if ([[json valueForKey:@"errorcode"] isEqualToString:@"0"])
    {
        
        dict = [json valueForKey:@"result"];
        
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:[json valueForKey:@"errorstr"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
    
    
    return dict;
}

@end
