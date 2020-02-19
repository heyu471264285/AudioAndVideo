//
//  VideoDecoder.h
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/18.
//  Copyright © 2020 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "AVConfig.h"

@protocol VideoDecoderDelegate <NSObject>
//解码后H264数据回调
- (void)videoDecodeCallback:(CVPixelBufferRef)imageBuffer;
@end

@interface VideoDecoder : NSObject

@property (nonatomic, strong) VideoConfig *config;
@property (nonatomic, weak) id<VideoDecoderDelegate> delegate;

/**初始化解码器**/
- (instancetype)initWithConfig:(VideoConfig*)config;

/**解码h264数据*/
- (void)decodeNaluData:(NSData *)frame;

@end

