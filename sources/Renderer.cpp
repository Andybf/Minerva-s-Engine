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
}

void Renderer::InitializeRendering() {
    glfwSetTime(0.0);
    while (!glfwWindowShouldClose(this->windowId)) {
        if (glfwGetTime() >= 1.0) {
            printf("FPS: %hd\n",this->framesPerSecond);
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

void Renderer::drawEntityOnScreen(Entity* model, glm::mat4 camera, glm::mat4 projection) {
    this->shader->setUniformMatrix(shader->getUniformModelId(), model->getMatrix());
}

void Renderer::resetFramesPerSecond() {
    this->framesPerSecond = 0;
    glfwSetTime(0.0);
}
