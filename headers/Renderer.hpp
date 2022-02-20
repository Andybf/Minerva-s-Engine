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
#include "Shader.hpp"
#include "ObjectsGL/VBO.hpp"
#include "ObjectsGL/VAO.hpp"
#include "ObjectsGL/EBO.hpp"

#define MI_TEXCOORD_ST 2
#define MI_VECTORS_XYZ 3
#define MI_COLORS_RGB 3
#define MI_COLORS_RGBA 4

class Renderer : virtual public Window {
    
private:
    struct ContextInformation {
        char * glVendor;
        char * glRenderer;
        char * glVersion;
        char * glExtensions;
    } contextInformation;
    
    Shader* shader;
    
    VBO* vbo;
    VAO* vao;
    EBO* ebo;
    
    short framesPerSecond;
    
    void resetFramesPerSecond();
    void setActiveTextureId(GLuint textureId);
    void printContextInformation();
    
public:
    
    Renderer();
    
    void InitializeRendering();
    
    virtual void renderGameContents() =0;
    
    void drawEntityElements(Entity* model, glm::mat4 camera, glm::mat4 projection);
    void drawEntityArrays(Entity* model, glm::mat4 camera, glm::mat4 projection);
    
    void storeEntityOnGPU(Entity* entity);
};
