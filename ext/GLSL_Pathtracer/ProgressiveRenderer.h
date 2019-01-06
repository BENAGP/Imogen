#pragma once

#include "Renderer.h"

namespace GLSLPathTracer
{
    class ProgressiveRenderer : public Renderer
    {
    private:
        GLuint pathTraceFBO, pathTraceFBOHalf, accumFBO;
        Program *pathTraceShader, *accumShader, *outputShader, *outputFadeShader;
        GLuint pathTraceTexture, pathTraceTextureHalf, accumTexture;
        int maxSamples, maxDepth;
        float sampleCounter, timeToFade, fadeTimer, lowResTimer;
        bool lowRes, fadeIn;

    public:
        ProgressiveRenderer(const Scene *scene, const std::string& shadersDirectory) : Renderer(scene, shadersDirectory)
            , maxDepth(scene->renderOptions.maxDepth)
        {
        };
        
        void init();
        void finish();

        void render();
        void present() const;
        void update(float secondsElapsed);
        float getProgress() const { return 1.f; }
        RendererType getType() const { return Renderer_Progressive; }
    };
}