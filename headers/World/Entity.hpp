//
//  Entity.h
//  Minerva's Engine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"

class Entity {
        
private:

    glm::mat4 matrix;

public:

    Entity();
    
    bool isEnabled;
    
    ushort textureType;
    ushort modelDrawType;

    uint relatedShaderId;
    uint relatedTextureId;
    uint vaoId;
    uint vboId;
    
    uint indicesSize;
    uint verticesSize;

    glm::mat4 getMatrix();

    void setScale(glm::vec3 scale);
    glm::vec3 getScale();
    
    void setPosition(glm::vec3 position);
    void addToPosition(glm::vec3 position);
    glm::vec3 getPosition();
    
    void setOrientation(float angle,glm::vec3 orientation);
    glm::quat getOrientation();
};
