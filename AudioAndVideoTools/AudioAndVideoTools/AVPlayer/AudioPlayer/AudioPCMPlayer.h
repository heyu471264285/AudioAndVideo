//
//  AudioPCMPlayer.h
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/19.
//  Copyright © 2020 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AudioConfig;

@interface AudioPCMPlayer : NSObject

- (instancetype)initWithConfig:(AudioConfig *)config;
/**播放pcm*/
- (void)playPCMData:(NSData *)data;
/** 设置音量增量 0.0 - 1.0 */
- (void)setupVoice:(Float32)gain;
/**销毁 */
- (void)dispose;


@end

