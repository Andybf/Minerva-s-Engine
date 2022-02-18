//
//  Window.hpp
//  Minerva's Engine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"

class Window {
    
    private:
        
        char* title;
        ushort width;
        ushort height;
        float aspectRatio;
    
    protected:
        GLFWwindow* windowId;
        
    public:
        
        Window(cchar* title, ushort width, ushort height);
};
