//
//  Mouse.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"
#include "../Window.hpp"

class Mouse : virtual public Window {
    
private:
    
public:
    Mouse(GLFWwindow* window);
    
    void respondInputPress(int buttonPressed, int actionPerformed);
    
    void handleMouseClick(GLFWwindow* window, int buttonPressed, int actionPerformed, int mods);
    void handleMouseMovement();
};
