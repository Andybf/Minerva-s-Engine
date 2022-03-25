//
//  Entity.h
//  Minerva's Engine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"
#include "../Core/Mesh.h"

class Entity {
        
private:

    glm::mat4 matrix;

public:

    Entity();
    
    bool isEnabled;
    
    ushort textureType;
    ushort modelDrawType;
    ushort relatedShaderId;
    ushort relatedTextureId;
    Mesh* mesh;

    glm::mat4 getMatrix();

    void setScale(glm::vec3 scale);
    glm::vec3 getScale();
    
    void setPosition(glm::vec3 position);
    void addToPosition(glm::vec3 position);
    glm::vec3 getPosition();
    
    void setOrientation(float angle,glm::vec3 orientation);
    glm::quat getOrientation();
};
