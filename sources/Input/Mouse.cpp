//
//  Mouse.cpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Mouse.hpp"

void mouseCallback(GLFWwindow* window, int buttonPressed, int actionPerformed, int mods) {
    ((Window*)glfwGetWindowUserPointer(window))->recieveClickPress(buttonPressed, actionPerformed);
}

void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos) {
    ((Window*)glfwGetWindowUserPointer(window))->recieveMovement(xpos, ypos);
}

void mouseScrollCallback(GLFWwindow* window, double xpos, double ypos) {
    ((Window*)glfwGetWindowUserPointer(window))->recieveScroll(xpos, ypos);
}

Mouse::Mouse(GLFWwindow* windowReference){
    glfwSetMouseButtonCallback(windowReference, mouseCallback);
    glfwSetCursorPosCallback(windowReference, mouseMoveCallback);
    glfwSetScrollCallback(windowReference, mouseScrollCallback);
}
