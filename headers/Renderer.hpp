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

class Renderer : virtual public Window{
    
private:
    struct ContextInformation {
        char * glVendor;
        char * glRenderer;
        char * glVersion;
        char * glExtensions;
    } contextInformation;
    
    Shader* shader;
    
    short framesPerSecond;
    
    void resetFramesPerSecond();
    
public:
    
    Renderer();
    void InitializeRendering();
    
    virtual void renderGameContents() =0;
    void drawEntityOnScreen(Entity* model, glm::mat4 camera, glm::mat4 projection);
    
};
