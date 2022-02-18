//
//  Window.hpp
//  Minerva's Engine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"
#include "Inputs/Inputs.hpp"

class Window {
    
private:
    
    char* title;
    ushort width;
    ushort height;
    float aspectRatio;
    Inputs* inputs;

protected:
    GLFWwindow* windowId;
    
    void initializeInputSystem(Inputs* inputs);
        
public:
    
    Window(cchar* title, ushort width, ushort height);
    
    void recieveKeyPress(int buttonPressed, int actionPerformed);
    void recieveClickPress(int buttonPressed, int actionPerformed);
    void recieveMovement(double xpos, double ypos);
    
};
