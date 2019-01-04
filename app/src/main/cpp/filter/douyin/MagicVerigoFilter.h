#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <GLES3/gl3.h>
#include "src/main/cpp/filter/gpuimage/GpuImageFilter.h"
#include "RenderBuffer.h"

/**
 * cangwang 2019.1.4
 */
class MagicVerigoFilter: public GPUImageFilter{

public:
    MagicVerigoFilter();
    MagicVerigoFilter(AAssetManager *assetManager);
    ~MagicVerigoFilter();
    void onDestroy() override ;

protected:
    void onInit() override;
    void onInitialized() override ;
    void onDrawArraysPre() override;
    void onDrawArraysAfter() override;

private:
    AAssetManager* mAssetManager;
    RenderBuffer* mRenderBuffer;
    RenderBuffer* mRenderBuffer2;
    RenderBuffer* mRenderBuffer3;
    GLint mLutTexture;
    GLuint mCurrentFrameProgram;
    GLuint mLastFrameProgram;
    bool mFirst = true;
    void drawToBuffer();
    void drawCurrentFrame();
    void setup(GLuint programId,GLint* textureId);
};