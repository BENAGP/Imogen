#pragma once

#include <GL/gl3w.h>
#include <Renderer.h>

namespace GLSLPathTracer
{
    class TiledRenderer : public Renderer
    {
    private:
        GLuint pathTraceFBO, accumFBO, outputFBO;
        Program *pathTraceShader, *accumShader, *tileOutputShader, *outputShader;
        GLuint pathTraceTexture, accumTexture, tileOutputTexture;
        int tileX, tileY, numTilesX, numTilesY, tileWidth, tileHeight, maxSamples, maxDepth;
        bool renderCompleted;
        float **sampleCounter, totalTime;
    public:
        TiledRenderer(const Scene *scene, const std::string& shadersDirectory) : Renderer(scene)
        {
            this->numTilesX = scene->renderOptions.numTilesX;
            this->numTilesY = scene->renderOptions.numTilesY;
            this->maxSamples = scene->renderOptions.maxSamples;
            this->maxDepth = scene->renderOptions.maxDepth;
            init(shadersDirectory);
        };
        void init(const std::string& shadersDirectory);
        void render();
        void present();
        void update(float secondsElapsed);
    };
}