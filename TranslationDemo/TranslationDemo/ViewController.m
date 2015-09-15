//
//  ViewController.m
//  TranslationDemo
//
//  Created by 冯洪建 on 15/9/15.
//  Copyright (c) 2015年 冯洪建. All rights reserved.
//

#import "ViewController.h"

#import "Translation.h"



@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    
    

    NSString * txt = @"مرحبا لا نعم، أنا لا";
    
    
    [Translation translationWithTxt:txt translationType:TranslationType_Auto2En success:^(NSDictionary *obj, NSString *dstContent) {
        
        NSLog(@"\n\n---%@----\n\n%@",obj,dstContent);
        
    }];




}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
