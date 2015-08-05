//
//  ViewController.m
//  Deals
//
//  Created by sharanya on 8/3/15.
//  Copyright (c) 2015 sharanya. All rights reserved.
//

#import "ViewController.h"
#import "UIImageView+AFNetworking.h"

@interface ViewController () 
{
    NSMutableArray *topMenuArray,*popularMenuArray;
    NSMutableDictionary *params;
    BOOL boolData;
    UIView *loadingView;
    UIActivityIndicatorView *activityView;
}

@property (strong, nonatomic) IBOutlet UITableView *tableView;
@property (strong, nonatomic) IBOutlet UIButton *btn;
@property (strong, nonatomic) IBOutlet UIButton *btn1;

@end

@implementation ViewController
@synthesize service = __service;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.navigationItem.title = @"Deals";
    
    boolData = false;
    
    loadingView = [[UIView alloc] initWithFrame:CGRectMake(0, 64, self.view.frame.size.width,self.view.frame.size.height)];
    loadingView.backgroundColor = [UIColor colorWithRed:0.0 / 255.0
                                                  green:0.0 / 255.0
                                                   blue:0.0 / 255.0
                                                  alpha:0.2];
    
    
    activityView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
    activityView.frame = CGRectMake(self.view.frame.size.width/2-15, self.view.frame.size.height/2-100, activityView.bounds.size.width, activityView.bounds.size.height);
    
    
    [self buttonSelected:self];
}

- (IBAction)buttonSelected:(id)sender {
    
    [self performSelector:@selector(doHighlight) withObject:sender afterDelay:0];
}

- (void)doHighlight {
    [self.btn setTitleColor:[UIColor whiteColor] forState:UIControlStateHighlighted];
    [self.btn setBackgroundColor:[UIColor colorWithRed:47.0 / 255.0
                                             green:165.0 / 255.0
                                              blue:228.0 / 255.0
                                             alpha:1.0]];
    
    [self.btn1 setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [self.btn1 setBackgroundColor:[UIColor whiteColor]];
    

    [_btn setHighlighted:YES];
    boolData = TRUE;
    

    [self getData];
    [self.tableView reloadData];
    
    
}

- (IBAction)button1Selected:(id)sender{
    
    [self performSelector:@selector(doHighlight1) withObject:sender afterDelay:0];
}

- (void)doHighlight1 {
    [self.btn setBackgroundColor:[UIColor whiteColor]];
    [self.btn setTitleColor:[UIColor blackColor] forState:UIControlStateHighlighted];
    
    [self.btn1 setBackgroundColor:[UIColor colorWithRed:47.0 / 255.0
                                              green:165.0 / 255.0
                                               blue:228.0 / 255.0
                                              alpha:1.0]];
    [self.btn1 setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.btn1 setHighlighted:YES];
    boolData = false;
    [self.tableView reloadData];

}

- (void)getData{
    //create the service with params
    //...
    
    //assign self as the delegate
    //self.service.delegate = self;
    //[self.service doSignUp];
//    [self performSelector:@selector(doSignUp)
//               withObject:nil
//               afterDelay:0.1];
    
    [UIApplication sharedApplication].networkActivityIndicatorVisible=YES;
    [self.view addSubview:loadingView];
    [loadingView addSubview:activityView];
    [activityView startAnimating];
    
    ApiCalls *api=[[ApiCalls alloc]init];
    [api doSignUp:self];
    
    
   

}

#pragma mark - RemoteApiProtocol
- (void)dictDelegate:(NSDictionary *)dealsDict{
    
    NSArray *topArray = [dealsDict valueForKey:@"top"];
    NSArray *popularArray = [dealsDict valueForKey:@"popular"];
    topMenuArray = [NSMutableArray array];
    popularMenuArray = [NSMutableArray array];

    for (NSDictionary *dictResSub in topArray)
    {
        DealsModal *deals = [[DealsModal alloc] init];
        deals.title = [dictResSub valueForKey:@"title"];
        deals.pic_thumb = [dictResSub valueForKey:@"pic_thumb"];
         NSAttributedString * attrStr = [[NSAttributedString alloc] initWithData:[[dictResSub valueForKey:@"deal_detail"] dataUsingEncoding:NSUnicodeStringEncoding] options:@{ NSDocumentTypeDocumentAttribute: NSHTMLTextDocumentType } documentAttributes:nil error:nil];
        deals.desc = attrStr;
        
        [topMenuArray addObject:deals];
    }
    for (NSDictionary *dictResSub in popularArray)
    {
        DealsModal *deals = [[DealsModal alloc] init];
        deals.title = [dictResSub valueForKey:@"title"];
        deals.pic_thumb = [dictResSub valueForKey:@"pic_thumb"];
        NSAttributedString * attrStr = [[NSAttributedString alloc] initWithData:[[dictResSub valueForKey:@"deal_detail"] dataUsingEncoding:NSUnicodeStringEncoding] options:@{ NSDocumentTypeDocumentAttribute: NSHTMLTextDocumentType } documentAttributes:nil error:nil];
        deals.desc = attrStr;
        
        [popularMenuArray addObject:deals];
    }

    [self.tableView reloadData];
    [UIApplication sharedApplication].networkActivityIndicatorVisible=NO;
    [activityView stopAnimating];
    [loadingView removeFromSuperview];

}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    
    if (boolData) {
        return [topMenuArray count];
    } else {
        return [popularMenuArray count];
    }
    
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 60;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *identifier=@"cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"identifier"];
    }
    DealsModal *deals;
    
    if (boolData) {
        deals=[topMenuArray objectAtIndex:indexPath.row];
    } else {
        deals=[popularMenuArray objectAtIndex:indexPath.row];
    }

    
    UIView *bgView=[[UIView alloc]initWithFrame:CGRectMake(10, 10, self.view.frame.size.width-2*10, 55)];
    
    bgView.layer.cornerRadius=5.0;
    [cell.contentView addSubview:bgView];
    bgView.backgroundColor=[UIColor whiteColor];
    
    
    UIImageView *imgVw=[[UIImageView alloc]initWithFrame:CGRectMake(5, 5, 50, 45)];
    imgVw.backgroundColor=[UIColor clearColor];
    [bgView addSubview:imgVw];

    NSString *strImgUrl = deals.pic_thumb;
    if(!(strImgUrl == nil)){
    [imgVw setImageWithURLRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:strImgUrl]] placeholderImage:nil success:nil failure:^(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error) {
        NSLog(@"Unable to retrieve image");
    }];
    }
    else
    {
        [imgVw setImage:[UIImage imageNamed:@"NoImage"]];
    }
    
    UILabel *lblTitle=[[UILabel alloc]initWithFrame:CGRectMake(60, 5, self.view.frame.size.width - 2*10 - 60, 30)];
    lblTitle.font = [UIFont boldSystemFontOfSize:16.0];
    NSString *strTitle = deals.title;
    lblTitle.text = strTitle;
    lblTitle.textAlignment=NSTextAlignmentCenter;
    lblTitle.textColor=[UIColor blackColor];
    lblTitle.backgroundColor=[UIColor clearColor];
    [bgView addSubview:lblTitle];
    
    UILabel *lblDealDetail=[[UILabel alloc]initWithFrame:CGRectMake(60, 25, self.view.frame.size.width - 2*10 - 70, 30)];
    lblDealDetail.font = [UIFont boldSystemFontOfSize:12.0];
    lblDealDetail.attributedText = deals.desc;
    lblDealDetail.textAlignment=NSTextAlignmentCenter;
    lblDealDetail.textColor=[UIColor blackColor];
    lblDealDetail.backgroundColor=[UIColor clearColor];
    [bgView addSubview:lblDealDetail];
        
    cell.selectionStyle=UITableViewCellSelectionStyleNone;
    cell.backgroundColor=[UIColor clearColor];
    return cell;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
