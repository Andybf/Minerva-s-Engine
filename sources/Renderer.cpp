//
//  Renderer.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Renderer.hpp"

Renderer::Renderer() :
    shader(new Shader())
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    
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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        this->renderGameContents();
        glfwSwapBuffers(this->windowId);
        glfwPollEvents();
        this->framesPerSecond++;
    }
    glfwTerminate();
}

void Renderer::drawEntityElements(Entity* entity, glm::mat4 camera, glm::mat4 projection) {
    this->setActiveTextureId(entity->textureId);
    glBindVertexArray(entity->vaoId);
    
    this->shader->setUniformMatrix(shader->getUniformProjectionId(), projection);
    this->shader->setUniformMatrix(shader->getUniformViewId(), camera);
    this->shader->setUniformMatrix(shader->getUniformModelId(), entity->getMatrix());
    
    glPolygonMode(GL_FRONT_AND_BACK, NULL);
    glDrawElements(entity->modelType, (int)entity->indices.size(), GL_UNSIGNED_INT, 0);
}

void Renderer::drawEntityArrays(Entity* entity, glm::mat4 camera, glm::mat4 projection) {
    glBindVertexArray(entity->vaoId);
    this->setActiveTextureId(entity->textureId);
    this->shader->setUniformMatrix(shader->getUniformProjectionId(), projection);
    this->shader->setUniformMatrix(shader->getUniformViewId(), camera);
    this->shader->setUniformMatrix(shader->getUniformModelId(), entity->getMatrix());
    
    glPolygonMode(GL_FRONT_AND_BACK, NULL);
    glDrawArrays(entity->modelType, 0, (float)entity->model.size()/3);
}

void Renderer::setActiveTextureId(GLuint textureId) {
    this->shader->setUniformInt(this->shader->getUniformActiveTexture(),textureId-1);
    glActiveTexture(GL_TEXTURE0 + textureId- 1);
    glBindTexture(GL_TEXTURE_2D, textureId);
}

void Renderer::storeEntityOnGPU(Entity* entity) {
    GLulong modelsSize = entity->model.size()*sizeof(GLfloat);
    GLulong colorsSize = modelsSize + entity->colors.size()*sizeof(GLfloat);
    
    entity->vboId = this->vbo->generateNewVBO(entity);
    
    entity->vaoId = this->vao->generateNewVAO();
    this->vao->bind(entity->vaoId);
    this->vao->linkAttribute(entity->vaoId, this->shader->getAttributePositionId(), MI_VECTORS_XYZ, 0);
    this->vao->linkAttribute(entity->vaoId, this->shader->getAttributeColorId(), MI_COLORS_RGBA, modelsSize);
    this->vao->linkAttribute(entity->vaoId, this->shader->getAttributeTextureCoordId(), MI_TEXCOORD_ST, colorsSize);
    
    entity->eboId = this->ebo->generateNewEBO(entity);
    
    this->vao->unbind();
    this->ebo->unbind();
    this->vbo->unbind();
}

void Renderer::resetFramesPerSecond() {
    this->framesPerSecond = 0;
    glfwSetTime(0.0);
}
