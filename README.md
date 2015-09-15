# TranslationDemo-
百度翻译
百度翻译的使用


项目中使用到了翻译
查了一下百度翻译的使用，特么就是一个调用网址，（太没意思了，直接上代码吧）


```ruby
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

```


```ruby
#import "Translation.h"

// 创建一个应用申请到 appKey (去百度开放平台申请)
#define baiduApiKey @"61emyra2CMGo76PsnKnhH3c1"// 这个key 不能用

@implementation Translation


+ (void )translationWithTxt:(NSString *)content translationType:(TranslationType)translationType success:(TranslationSuccessBlock)successBlock{
    
    
//    TranslationType_En2Zh, // 英语-> 中文
//    TranslationType_En2Ara,// 英语-> 阿拉伯
//    TranslationType_Zh2En,// 中文-> 英语
//    TranslationType_Zh2Ara,// 中文->阿拉伯
//    TranslationType_Ara2En,// 阿拉伯-> 英语
//    TranslationType_Ara2Zh// 阿拉伯-> 中文
//    TranslationType_Auto2Zh,// ？-> 中文
//    TranslationType_Auto2En,// ？-> 中文
//    TranslationType_Auto2Ara// ？-> 中文

    NSString * from;
    NSString * to;
    
    if (translationType == TranslationType_En2Zh) {
        from =@"en";
        to   =@"zh";
    }
    if (translationType == TranslationType_En2Ara) {
        from =@"en";
        to   =@"ara";
    }
    if (translationType == TranslationType_Zh2En) {
        from =@"zh";
        to   =@"en";
    }
    if (translationType == TranslationType_Zh2Ara) {
        from =@"zh";
        to   =@"ara";
    }
    if (translationType == TranslationType_Ara2En) {
        from =@"ara";
        to   =@"en";
    }
    if (translationType == TranslationType_Ara2Zh) {
        from =@"ara";
        to   =@"zh";
    }
    
    
    
    if (translationType == TranslationType_Auto2Zh) {
        from =@"auto";
        to   =@"zh";
    }
    if (translationType == TranslationType_Auto2En) {
        from =@"auto";
        to   =@"en";
    }
    if (translationType == TranslationType_Auto2Ara) {
        from =@"auto";
        to   =@"ara";
    }
    
    NSString  * url= [NSString stringWithFormat:@"http://openapi.baidu.com/public/2.0/bmt/translate?client_id=%@&q=%@&from=%@&to=%@",baiduApiKey,content,from,to];
    [self getUrl:url success:^(NSDictionary * obj) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString * returnContent =obj[@"trans_result"][0][@"dst"];
            successBlock(obj,returnContent);
            
        });
    }];
 
   
}

+(void)getUrl:(NSString *)urlString success:(void (^)(NSDictionary * responseObject))successBlock {
    __block NSString *urlStr=urlString;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        urlStr = [urlStr stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        NSURL *url=[NSURL URLWithString:urlStr];
        NSURLRequest *request=[NSURLRequest requestWithURL:url cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:30.0f];
        [NSURLConnection sendAsynchronousRequest:request queue:[[NSOperationQueue alloc] init] completionHandler:^(NSURLResponse *response, NSData *data, NSError *connectionError) {
            
            NSString * dataString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            NSData *correctStringData=[dataString dataUsingEncoding:NSUTF8StringEncoding];
            id obj=[NSJSONSerialization JSONObjectWithData:correctStringData options:NSJSONReadingAllowFragments error:nil];
            successBlock(obj);
        }];
        
    });
}
@end


```
