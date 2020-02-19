//
//  AudioDataQueue.h
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/19.
//  Copyright © 2020 mac. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface AudioDataQueue : NSObject

@property (nonatomic, readonly) int count;

+(instancetype) shareInstance;

- (void)addData:(id)obj;

- (id)getData;

@end


