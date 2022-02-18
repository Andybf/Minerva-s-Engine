//
//  Keyboard.cpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Keyboard.hpp"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    ((Window*)glfwGetWindowUserPointer(window))->recieveKeyPress(key, action);
}

Keyboard::Keyboard(GLFWwindow* windowReference) {
    glfwSetKeyCallback(windowReference, keyCallback);
}

//void Keyboard::respondKeyPress(int buttonPressed, int actionPerformed) {
//    printf("%d, %d\n",buttonPressed,actionPerformed);
//}
