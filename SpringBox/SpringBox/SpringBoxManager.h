//
//  SpringBoxManager.h
//  SpringBox
//
//  Created by zhengsw on 2020/6/18.
//  Copyright © 2020 58. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^Block)(void);

@interface AlertConfig : NSObject
@property (nonatomic,assign) NSInteger alertType;

/// 阻断后，是否需要激活
@property (nonatomic,assign) BOOL isActivate;
/// 优先级
@property (nonatomic,assign) NSInteger priority;
@property (nonatomic,strong) NSDictionary *params;

@property (nonatomic,copy) Block block;

- (instancetype)initWithPatams:(NSDictionary *)params activate:(BOOL)isActivate;

@end


@interface AlertManager : NSObject

+ (instancetype)shareManager;

- (void)addAlert:(AlertConfig *)config;

- (void)alertShowWithType:(NSString *)type config:(AlertConfig *)config success:(Block)successBlock;

- (void)alertDissMissWithType:(NSString *)type success:(Block)successBlock;

@end

NS_ASSUME_NONNULL_END
