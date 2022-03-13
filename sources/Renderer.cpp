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
    printf("\nMinerva OpenGL Context Information:\nglVendor   : %s\nglRenderer : %s\nglVersion  : %s\n\n",
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

void Renderer::drawElementsInstanced(Entity* model, int count) {
    MI_TEST(glDrawElementsInstanced(model->modelType, (int)model->indices.size(), GL_UNSIGNED_INT, 0, count));
}
void Renderer::drawElements(Entity* model) {
    MI_TEST(glDrawElements(model->modelType, (int)model->indices.size(), GL_UNSIGNED_INT, 0));
}
void Renderer::drawArrays(Entity* model) {
    MI_TEST(glDrawArrays(model->modelType, MI_STARTING_INDEX, (float)model->model.size()/3));
}

void Renderer::bindVertexArray(uint vertexArrayId){
    MI_TEST(glBindVertexArray(vertexArrayId));
}
void Renderer::storeEntityOnGPU(Entity* entity) {
    GLulong modelsSize = entity->model.size()*sizeof(GLfloat);
    GLulong colorsSize = modelsSize + entity->colors.size()*sizeof(GLfloat);
    
    entity->vboId = this->vbo->generateNewVBO(entity);
    entity->vaoId = this->vao->generateNewVAO();
    this->vao->bind(entity->vaoId);
    this->vao->linkAttribute(entity->vaoId, glGetAttribLocation(entity->relatedShaderId, "position"), entity->dimensions.position, 0);
    this->vao->linkAttribute(entity->vaoId, glGetAttribLocation(entity->relatedShaderId, "color"), entity->dimensions.color, modelsSize);
    this->vao->linkAttribute(entity->vaoId, glGetAttribLocation(entity->relatedShaderId, "texCoord"), entity->dimensions.texCoord, colorsSize);
    entity->eboId = this->ebo->generateNewEBO(entity);
    
    this->vao->unbind();
    this->ebo->unbind();
    this->vbo->unbind();
}

void Renderer::resetFramesPerSecond() {
    this->framesPerSecond = 0;
    glfwSetTime(0.0);
}
