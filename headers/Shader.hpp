//
//  Shader.hpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"
#include "Loaders/ShaderLoader.hpp"

class Shader {
    
private:
    GLuint shaderProgramId;
    ShaderLoader* shaderLoader;
    
public:
    Shader();
    
    void setUniformMatrix(GLuint uniformId, glm::mat4 matrix);
    
    int getUniformProjectionId();
    int getUniformViewId();
    int getUniformModelId();
    int getUniformActiveTexture();
    
    GLuint getShaderProgramId();
};
