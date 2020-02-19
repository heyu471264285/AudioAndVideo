//
//  AudioEncoder.h
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/19.
//  Copyright © 2020 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
@class AudioConfig;

/**AAC编码器代理*/
@protocol AudioEncoderDelegate <NSObject>
- (void)audioEncodeCallback:(NSData *)aacData;
@end

@interface AudioEncoder : NSObject

/**编码器配置*/
@property (nonatomic, strong) AudioConfig *config;
@property (nonatomic, weak) id<AudioEncoderDelegate> delegate;

/**初始化传入编码器配置*/
- (instancetype)initWithConfig:(AudioConfig*)config;

/**编码*/
- (void)encodeAudioSamepleBuffer: (CMSampleBufferRef)sampleBuffer;

@end

