//
//  DebugCamera.hpp
//  MinervaEngine
//
//  Created by Anderson on 21/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"
#include "../World/Camera.hpp"

class DebugCamera {
    
private:
    
    Camera* camera;
    struct Mouse {
        float x;
        float y;
        bool isRightPressed;
        bool isLeftPressed;
    } actualMouseState, lastMouseState;
    
    float yaw;
    float pitch;
    
public:
    DebugCamera(Camera* camera);
    
    void handleMousePress(short buttonPressed, short actionPerformed);
    void handleMouseMovement(float x, float y);
};
