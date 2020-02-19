//
//  AudioDataQueue.m
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/19.
//  Copyright © 2020 mac. All rights reserved.
//

#import "AudioDataQueue.h"

@interface AudioDataQueue ()
@property (nonatomic, strong) NSMutableArray *bufferArray;
@end

@implementation AudioDataQueue

@synthesize count;
static AudioDataQueue *_instance = nil;

+(instancetype) shareInstance
{
    static dispatch_once_t onceToken ;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    }) ;
    return _instance ;
}

- (instancetype)init{
    if (self = [super init]) {
        _bufferArray = [NSMutableArray array];
        count = 0;
    }
    return self;
}

-(void)addData:(id)obj{
    @synchronized (_bufferArray) {
        [_bufferArray addObject:obj];
        count = (int)_bufferArray.count;
    }
}

- (id)getData{
    @synchronized (_bufferArray) {
        id obj = nil;
        if (count) {
            obj = [_bufferArray firstObject];
            [_bufferArray removeObject:obj];
            count = (int)_bufferArray.count;
        }
        return obj;
    }
}

@end
