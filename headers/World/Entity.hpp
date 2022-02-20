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

    std::vector<GLfloat> model;
    std::vector<GLuint> indices;
    std::vector<GLfloat> colors;
    std::vector<GLfloat> textureCoords;

    GLuint textureId;
    unsigned char modelType;
    bool isEnabled;

    GLuint vaoId;
    GLuint vboId;
    GLuint eboId;

    glm::mat4 getMatrix();

    void setScale(glm::vec3 scale);
    glm::vec3 getScale();
    
    void setPosition(glm::vec3 position);
    glm::vec3 getPosition();
    
    void setOrientation(float angle,glm::vec3 orientation);
    glm::quat getOrientation();
};
