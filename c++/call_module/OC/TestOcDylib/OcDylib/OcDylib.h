//
//  OcDylib.h
//  OcDylib
//
//  Created by Sw007 on 2020/8/7.
//  Copyright © 2020 hyperxcode. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface OcDylib : NSObject
- (int) oc_add:(int) a withB : (int) b;
int add(int a, int b);
@end
NS_ASSUME_NONNULL_END
