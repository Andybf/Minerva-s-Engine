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
    
    ShaderLoader* shaderLoader;
    
public:
    
    static GLuint createNewShaderProgram(cchar* vertexFile, cchar* fragmentFile);
    static void useShaderProgram(int shaderId);
    
};
