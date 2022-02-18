//
//  Shader.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Shader.hpp"

Shader::Shader() {
    this->shaderLoader = new ShaderLoader();
    this->shaderProgramId = shaderLoader->load("VertexShader.vs","FragmentShader.fs");
}

void Shader::setUniformMatrix(GLuint uniformId, glm::mat4 matrix) {
    glUniformMatrix4fv(uniformId, 1, GL_FALSE, &matrix[0][0]);
}

int Shader::getUniformProjectionId() {
    return 0;
}
int Shader::getUniformViewId() {
    return 0;
}
int Shader::getUniformModelId() {
    return 0;
}
int Shader::getUniformActiveTexture() {
    return 0;
}
