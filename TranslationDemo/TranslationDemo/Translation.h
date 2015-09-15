//
//  Translation.h
//  TranslationDemo
//
//  Created by 冯洪建 on 15/9/15.
//  Copyright (c) 2015年 冯洪建. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TranslationType) {
    
    TranslationType_En2Zh, // 英语-> 中文
    TranslationType_En2Ara,// 英语-> 阿拉伯
    TranslationType_Zh2En,// 中文-> 英语
    TranslationType_Zh2Ara,// 中文->阿拉伯
    TranslationType_Ara2En,// 阿拉伯-> 英语
    TranslationType_Ara2Zh,// 阿拉伯-> 中文
    TranslationType_Auto2Zh,// ?-> 中文  /**自动检测*/
    TranslationType_Auto2En,// ?-> 英语  /**自动检测*/
    TranslationType_Auto2Ara// ?-> 阿拉伯 /**自动检测*/

};



typedef void(^TranslationSuccessBlock)(NSDictionary * obj,NSString * dstContent);


@interface Translation : NSObject


+ (void )translationWithTxt:(NSString *)content translationType:(TranslationType)translationType success:(TranslationSuccessBlock)successBlock;




@end















// // 英语-> 中文
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=en&to=zh
//
//// 英语-> 阿拉伯
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=en&to=ara
////中文-> 英语
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=zh&to=en
//// 中文->阿拉伯
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=zh&to=ara
//// 阿拉伯-> 英语
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=ara&to=en
//// 阿拉伯-> 中文
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=ara&to=zh
//
//// ?-> 中文  /**自动检测*/
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=auto&to=zh
//
//// ?-> 英语  /**自动检测*/
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=auto&to=en
//
//// ?-> 阿拉伯 /**自动检测*/
//http://openapi.baidu.com/public/2.0/bmt/translate?client_id=61emyra2CMGo76PsnKnhH3co&q=hello&from=auto&to=ara
