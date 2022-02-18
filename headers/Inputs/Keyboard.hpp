//
//  Keyboard.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"
#include "../Window.hpp"

class Keyboard : public virtual Inputs {
    
private:
    
public:
    Keyboard(GLFWwindow* window);
    
    virtual void respondKeyPress(int buttonPressed, int actionPerformed) =0;
};
