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
    
    this->attributePositionId = glGetAttribLocation(this->shaderProgramId, "vtxPosition");
    this->attributeColorId = glGetAttribLocation(this->shaderProgramId, "vtxColor");
    this->attributeTextureCoordId = glGetAttribLocation(this->shaderProgramId, "inTextureCoord");
    
    this->uniformProjectionId = glGetUniformLocation(this->shaderProgramId, "projectionMatrix");
    this->uniformViewId = glGetUniformLocation(this->shaderProgramId, "viewMatrix");
    this->uniformModelId = glGetUniformLocation(this->shaderProgramId, "modelMatrix");
    this->uniformActiveTexture = glGetUniformLocation(this->shaderProgramId, "tex0");
    
    glUseProgram(this->shaderProgramId);
}

void Shader::setUniformMatrix(GLuint uniformId, glm::mat4 matrix) {
    glUniformMatrix4fv(uniformId, MATRICES_TO_GENERATE, GL_FALSE, &matrix[0][0]);
}

void Shader::setUniformInt(GLuint uniformId, GLint value) {
    glUniform1i(uniformId,value);
}

GLuint Shader::getShaderProgramId() {
    return this->shaderProgramId;
}

int Shader::getAttributePositionId() {
    return this->attributePositionId;
}
int Shader::getAttributeColorId() {
    return this->attributeColorId;
}
int Shader::getAttributeTextureCoordId() {
    return this->attributeTextureCoordId;
}

int Shader::getUniformProjectionId() {
    return this->uniformProjectionId;
}
int Shader::getUniformViewId() {
    return this->uniformViewId;
}
int Shader::getUniformModelId() {
    return this->uniformModelId;
}
int Shader::getUniformActiveTexture() {
    return this->uniformActiveTexture;
}
