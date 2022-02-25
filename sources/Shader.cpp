//
//  Shader.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Shader.hpp"

GLuint Shader::createNewShaderProgram(cchar* vertexFile, cchar* fragmentFile) {
    GLuint shaderProgramId = ShaderLoader::load(vertexFile,fragmentFile);
    return shaderProgramId;
}

void Shader::useShaderProgram(int shaderId) {
    glUseProgram(shaderId);
}
