//
//  DealsModal.h
//  Deals
//
//  Created by sharanya on 8/4/15.
//  Copyright (c) 2015 sharanya. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DealsModal : NSObject{
    NSString *title;
    NSString *deal_detail;
    NSString *pic_thumb;
}
@property(strong, nonatomic) NSString *title;
@property(strong, nonatomic) NSString *deal_detail;
@property(strong, nonatomic) NSString *pic_thumb;
@property (nonatomic, retain) NSAttributedString *desc;


@end
