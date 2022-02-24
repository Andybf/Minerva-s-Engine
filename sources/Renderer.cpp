//
//  Renderer.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Renderer.hpp"

Renderer::Renderer() {
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    
    this->shader = new Shader();
    
    this->vbo = new VBO();
    this->vao = new VAO();
    this->ebo = new EBO();
    this->framesPerSecond = 0;
    this->printContextInformation();
}

void Renderer::printContextInformation() {
    this->contextInformation.glVendor     = (char*)glGetString(GL_VENDOR);
    this->contextInformation.glRenderer   = (char*)glGetString(GL_RENDERER);
    this->contextInformation.glVersion    = (char*)glGetString(GL_VERSION);
    this->contextInformation.glExtensions = (char*)glGetString(GL_EXTENSIONS);
    printf("\nOpenGL Context Information:\nglVendor   : %s\nglRenderer : %s\nglVersion  : %s\n\n",
           this->contextInformation.glVendor,
           this->contextInformation.glRenderer,
           this->contextInformation.glVersion
           );
}

void Renderer::InitializeRendering() {
    glfwSetTime(0.0);
    while (!glfwWindowShouldClose(this->windowId)) {
        if (glfwGetTime() >= 1.0) {
            //printf("FPS: %hd\n",this->framesPerSecond);
            this->resetFramesPerSecond();
        }
        MI_TEST(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
        this->renderGameContents();
        glfwSwapBuffers(this->windowId);
        glfwPollEvents();
        this->framesPerSecond++;
    }
    glfwTerminate();
}

void Renderer::drawEntityElements(Entity* entity, glm::mat4 camera, glm::mat4 projection) {
    this->shader->setUniformInt(glGetUniformLocation(entity->shader.id, entity->shader.texture),entity->texture.id-1);
    MI_TEST(glActiveTexture(GL_TEXTURE0 + entity->texture.id- 1));
    MI_TEST(glBindTexture(entity->texture.type, entity->texture.id));
    
    MI_TEST(glBindVertexArray(entity->vaoId));
    this->shader->setUniformMatrix(glGetUniformLocation(entity->shader.id,entity->shader.model), entity->getMatrix());
    this->shader->setUniformMatrix(glGetUniformLocation(entity->shader.id,entity->shader.view), camera);
    this->shader->setUniformMatrix(glGetUniformLocation(entity->shader.id,entity->shader.projection), projection);
    
    MI_TEST(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
    MI_TEST(glDrawElements(entity->modelType, (int)entity->indices.size(), GL_UNSIGNED_INT, 0));
}

void Renderer::drawEntityArrays(Entity* entity, glm::mat4 camera, glm::mat4 projection) {
    this->shader->setUniformInt(glGetUniformLocation(entity->shader.id, entity->shader.texture),entity->texture.id-1);
    MI_TEST(glActiveTexture(GL_TEXTURE0 + entity->texture.id- 1));
    MI_TEST(glBindTexture(entity->texture.type, entity->texture.id));
    
    MI_TEST(glBindVertexArray(entity->vaoId));
    this->shader->setUniformMatrix(glGetUniformLocation(entity->shader.id,entity->shader.model), entity->getMatrix());
    this->shader->setUniformMatrix(glGetUniformLocation(entity->shader.id,entity->shader.view), camera);
    this->shader->setUniformMatrix(glGetUniformLocation(entity->shader.id,entity->shader.projection), projection);
    
    MI_TEST(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
    MI_TEST(glDrawArrays(entity->modelType, MI_STARTING_INDEX, (float)entity->model.size()/3));
}

void Renderer::storeEntityOnGPU(Entity* entity) {
    GLulong modelsSize = entity->model.size()*sizeof(GLfloat);
    GLulong colorsSize = modelsSize + entity->colors.size()*sizeof(GLfloat);
    
    entity->vboId = this->vbo->generateNewVBO(entity);
    
    entity->vaoId = this->vao->generateNewVAO();
    this->vao->bind(entity->vaoId);
    this->vao->linkAttribute(entity->vaoId, glGetAttribLocation(entity->shader.id, entity->shader.position.name), entity->shader.position.dimensions, 0);
    this->vao->linkAttribute(entity->vaoId, glGetAttribLocation(entity->shader.id, entity->shader.vecColor.name), entity->shader.vecColor.dimensions, modelsSize);
    this->vao->linkAttribute(entity->vaoId, glGetAttribLocation(entity->shader.id, entity->shader.texCoord.name), entity->shader.texCoord.dimensions, colorsSize);
    
    entity->eboId = this->ebo->generateNewEBO(entity);
    
    this->vao->unbind();
    this->ebo->unbind();
    this->vbo->unbind();
}

GLuint Renderer::createNewShaderProgram(cchar* vertexFile, cchar* fragmentFile) {
    GLuint shaderProgramId =0;
    this->shaderLoader = new ShaderLoader();
    shaderProgramId = shaderLoader->load(vertexFile,fragmentFile);
    return shaderProgramId;
}

void Renderer::useShaderProgram(int shaderId) {
    glUseProgram(shaderId);
}

void Renderer::resetFramesPerSecond() {
    this->framesPerSecond = 0;
    glfwSetTime(0.0);
}
