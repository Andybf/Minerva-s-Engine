//
//  Camera.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"

class Camera {
    
private:
    glm::mat4 matrix;
    
    glm::vec3 position;
    glm::vec3 upAxis;
    glm::vec3 orientation;
    
public:
    Camera();
    
    glm::mat4 getMatrix();
    
    void setPosition(glm::vec3 position);
    glm::vec3 getPosition();
    
    void setOrientation(float yaw, float pitch);
    glm::vec3 getOrientation();
};
