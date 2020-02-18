//
//  VideoEncoder.h
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/18.
//  Copyright © 2020 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "AVConfig.h"


/**h264编码回调代理*/
@protocol VideoEncoderDelegate <NSObject>
//Video-H264数据编码完成回调
- (void)videoEncodeCallback:(NSData *)h264Data;
//Video-SPS&PPS数据编码回调
- (void)videoEncodeCallbacksps:(NSData *)sps pps:(NSData *)pps;
@end

@interface VideoEncoder : NSObject

@property (nonatomic, strong) VideoConfig *config;
@property (nonatomic, weak) id<VideoEncoderDelegate> delegate;

- (instancetype)initWithConfig:(VideoConfig*)config;
/**编码*/
-(void)encodeVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;


@end

