//
//  Shader.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Shader.hpp"

uint Shader::activeShaderId = 0;

GLuint Shader::createNewShaderProgram(cchar* vertexFile, cchar* fragmentFile) {
    GLuint shaderProgramId = ShaderLoader::load(vertexFile,fragmentFile);
    return shaderProgramId;
}

void Shader::activateProgramWithId(uint shaderId) {
    glUseProgram(shaderId);
    Shader::activeShaderId = shaderId;
}

void Shader::setUniformModelViewProjection(Entity* entity, glm::mat4 camera, glm::mat4 projection) {
    MI_TEST(glBindVertexArray(entity->vaoId));
    Shader::setUniformMatrix("modelMatrix", entity->getMatrix());
    Shader::setUniformMatrix("viewMatrix", camera);
    Shader::setUniformMatrix("projectionMatrix", projection);
}

void Shader::setUniformModelProjection(Entity* entity, glm::mat4 projection) {
    MI_TEST(glBindVertexArray(entity->vaoId));
    Shader::setUniformMatrix("modelMatrix", entity->getMatrix());
    Shader::setUniformMatrix("projectionMatrix", projection);
}

void Shader::setUniformTexture(uint textureId, uint dimensions) {
    MI_TEST(glUniform1i(glGetUniformLocation(Shader::activeShaderId, "texture0"),textureId-1));
    MI_TEST(glActiveTexture(GL_TEXTURE0 + textureId- 1));
    MI_TEST(glBindTexture(dimensions, textureId));
    MI_TEST(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
}
void Shader::setUniformMatrix(cchar* name, glm::mat4 matrix) {
    MI_TEST(glUniformMatrix4fv(glGetUniformLocation(Shader::activeShaderId,name), MI_COUNT, GL_FALSE, &matrix[0][0]));
}
void Shader::setUniformIntArray(cchar* name, int* intArray, int size) {
    MI_TEST(glUniform1iv(glGetUniformLocation(Shader::activeShaderId,name), size*sizeof(int), intArray));
}
void Shader::setUniformFloat(cchar* name, float value) {
    MI_TEST(glUniform1f(glGetUniformLocation(Shader::activeShaderId,name), value));
}
void Shader::setUniformVec2Array(cchar* name, const float* value, int size) {
    MI_TEST(glUniform2fv(glGetUniformLocation(Shader::activeShaderId,name), size, value));
}
