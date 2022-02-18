//
//  Window.cpp
//  Minerva's Engine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Window.hpp"

Window::Window(cchar* title, ushort width, ushort height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    this->windowId = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(this->windowId);
    glfwSetWindowUserPointer(this->windowId, this);
    glewInit();
}

void Window::initializeInput(Inputs* inputs) {
    this->inputs = inputs;
}

void Window::recieveKeyPress(int buttonPressed, int actionPerformed) {
    this->inputs->respondKeyPress(buttonPressed, actionPerformed);
}

void Window::recieveClickPress(int buttonPressed, int actionPerformed) {
    this->inputs->respondClickPress(buttonPressed, actionPerformed);
}

void Window::recieveMovement(double xpos, double ypos) {
    this->inputs->respondMovement(xpos, ypos);
}
