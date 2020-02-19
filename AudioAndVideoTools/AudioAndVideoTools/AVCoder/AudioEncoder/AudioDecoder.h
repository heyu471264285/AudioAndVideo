//
//  AudioDecoder.h
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/19.
//  Copyright © 2020 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
@class AudioConfig;

/**AAC解码回调代理*/
@protocol AudioDecoderDelegate <NSObject>
- (void)audioDecodeCallback:(NSData *)pcmData;
@end


@interface AudioDecoder : NSObject
@property (nonatomic, strong) AudioConfig *config;
@property (nonatomic, weak) id<AudioDecoderDelegate> delegate;

//初始化 传入解码配置
- (instancetype)initWithConfig:(AudioConfig *)config;

/**解码aac*/
- (void)decodeAudioAACData: (NSData *)aacData;
@end

