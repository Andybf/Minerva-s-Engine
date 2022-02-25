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


#define MI_STARTING_INDEX 0
#define MI_COUNT 1

class Renderer : virtual public Window {
    
private:
    struct ContextInformation {
        char * glVendor;
        char * glRenderer;
        char * glVersion;
        char * glExtensions;
    } contextInformation;
    
    VBO* vbo;
    VAO* vao;
    EBO* ebo;
    
    short framesPerSecond;
    
    void resetFramesPerSecond();
    void printContextInformation();
    
public:
    
    Renderer();
    
    void InitializeRendering();
    
    virtual void renderGameContents() =0;
    
    void select(Entity* model, glm::mat4 camera, glm::mat4 projection);
    void drawElementsFrom(Entity* model);
    void drawArraysFrom(Entity* model);
    
    void storeEntityOnGPU(Entity* entity);
};
