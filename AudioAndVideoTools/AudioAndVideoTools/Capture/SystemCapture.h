//
//  SystemCapture.h
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/18.
//  Copyright © 2020 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

//捕获类型
typedef NS_ENUM(int,SystemCaptureType) {
    SystemCaptureTypeVideo = 0,
    SystemCaptureTypeAudio,
    SystemCaptureTypeAll
};

//捕获的音频/视频数据回调,
@protocol SystemCaptureDelegate <NSObject>
@optional
//回调的数据CMSampleBufferRef：sampleBuffer用于音视频编码，type：回调的类型
- (void)captureSampleBuffer:(CMSampleBufferRef)sampleBuffer type: (SystemCaptureType)type;

@end

@interface SystemCapture : NSObject

/**预览层*/
@property (nonatomic,strong) UIView * preView;

@property (nonatomic,weak) id<SystemCaptureDelegate> delegate;

/**捕获视频的宽*/
@property (nonatomic, assign, readonly) NSUInteger witdh;
/**捕获视频的高*/
@property (nonatomic, assign, readonly) NSUInteger height;

//被始方法
- (instancetype)initWithType:(SystemCaptureType)type;
- (instancetype)init;

/** 准备工作(只捕获音频时调用)*/
- (void)prepare;
//捕获内容包括视频时调用（预览层大小，添加到view上用来显示）
- (void)prepareWithPreviewSize:(CGSize)size;

/**开始*/
- (void)start;
/**结束*/
- (void)stop;
/**切换摄像头*/
- (void)changeCamera;


//授权检测
+ (int)checkMicrophoneAuthor;
+ (int)checkCameraAuthor;


@end


