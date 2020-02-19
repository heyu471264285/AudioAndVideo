//
//  AAPLEAGLLayer.h
//  AudioAndVideoTools
//
//  Created by mac on 2020/2/19.
//  Copyright © 2020 mac. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#include <CoreVideo/CoreVideo.h>


@interface AAPLEAGLLayer : CAEAGLLayer

@property CVPixelBufferRef pixelBuffer;
- (id)initWithFrame:(CGRect)frame;
- (void)resetRenderBuffer;

@end

