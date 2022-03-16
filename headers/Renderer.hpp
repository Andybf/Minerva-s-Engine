//
//  Renderer.hpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"
#include "Window.hpp"
#include "World/Entity.hpp"
#include "ObjectsGL/VBO.hpp"
#include "ObjectsGL/VAO.hpp"
#include "ObjectsGL/EBO.hpp"

class Renderer : virtual public Window {
    
private:
    struct ContextInformation {
        char* glVendor;
        char* glRenderer;
        char* glVersion;
        char* glExtensions;
    } contextInformation;
    
    VBO* vbo;
    VAO* vao;
    EBO* ebo;
    
    short frameCount;
    float framesPerSecond;
    
    void resetFrameCount();
    void saveContextInformation();
    
    virtual void renderGameContents() =0;
    
public:
    
    Renderer();
    
    void InitializeRendering();
    
    void drawElementsInstanced(Entity* model, uint count);
    void drawElements(Entity* model);
    void drawArrays(Entity* model);
    
    void bindVertexArray(uint vertexArrayId);
    void storeEntityOnGPU(Entity* entity);
    
    int getFrameCount();
    float getFramesPerSecond();
    void getContextInformation(char* string);
};
