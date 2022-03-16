//
//  Shader.hpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"
#include "World/Entity.hpp"
#include "Loaders/ShaderLoader.hpp"

class Shader {
    
private:
    
    ShaderLoader* shaderLoader;
    
    static uint activeShaderId;
    
    static void setUniformMatrix(cchar* name, glm::mat4 matrix);
    
public:
    
    static GLuint createNewShaderProgram(cchar* vertexFile, cchar* fragmentFile);
    static void activateProgramWithId(uint shaderId);
    
    static void setUniformModelViewProjection(Entity* entity, glm::mat4 camera, glm::mat4 projection);
    static void setUniformModelProjection(Entity* entity, glm::mat4 projection);
    
    static void setUniformTexture(uint textureId, uint dimensions);
    static void setUniformIntArray(cchar* name, int* intArray, int size);
    static void setUniformFloat(cchar* name, float value);
    static void setUniformVec2Array(cchar* name, const float* value, int size);
    
};
