//
//  Shader.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Shader.hpp"

Shader::Shader() {
    
}

void Shader::setUniformMatrix(GLuint uniformId, glm::mat4 matrix) {
    glUniformMatrix4fv(uniformId, MATRICES_TO_GENERATE, GL_FALSE, &matrix[0][0]);
}

void Shader::setUniformInt(GLuint uniformId, GLint value) {
    glUniform1i(uniformId,value);
}

