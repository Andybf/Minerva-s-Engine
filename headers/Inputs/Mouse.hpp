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

class Mouse : public virtual Inputs {
    
private:
    
public:
    Mouse(GLFWwindow* window);
    
    virtual void respondClickPress(int buttonPressed, int actionPerformed) =0;
    virtual void respondMovement(double xpos, double ypos) =0;
};
