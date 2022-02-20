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

#define MATRICES_TO_GENERATE 1

class Shader {
    
private:
    GLuint shaderProgramId;
    ShaderLoader* shaderLoader;
    
    int attributePositionId;
    int attributeColorId;
    int attributeTextureCoordId;
    
    int uniformProjectionId;
    int uniformViewId;
    int uniformModelId;
    int uniformActiveTexture;
    
public:
    Shader();
    
    void setUniformMatrix(GLuint uniformId, glm::mat4 matrix);
    void setUniformInt(GLuint uniformId, GLint value);
    
    GLuint getShaderProgramId();
    
    int getAttributePositionId();
    int getAttributeColorId();
    int getAttributeTextureCoordId();
    
    int getUniformProjectionId();
    int getUniformViewId();
    int getUniformModelId();
    int getUniformActiveTexture();
};
