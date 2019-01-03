#pragma once

#include <SDL.h>
#include <Renderer.h>

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
        ProgressiveRenderer(const Scene *scene) : Renderer(scene)
        {
            this->maxDepth = scene->renderOptions.maxDepth;
            init();
        };
        void init();
        void render();
        void update(float secondsElapsed);
        void present();
    };
}