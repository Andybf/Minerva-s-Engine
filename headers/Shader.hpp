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
    

    
public:
    
    Shader();
    
    void setUniformMatrix(GLuint uniformId, glm::mat4 matrix);
    void setUniformInt(GLuint uniformId, GLint value);
};
