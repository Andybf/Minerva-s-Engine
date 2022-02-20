//
//  Projection.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"

class Projection {
    
private:
    glm::mat4 orthographicMatrix;
    glm::mat4 perspectiveMatrix;
    
    uchar activeProjectionMode;
    
public:
    Projection();
    
    glm::mat4 getOrthographic();
    void setOrthographic(GLfloat west, GLfloat east, GLfloat south, GLfloat north, GLfloat behind, GLfloat front);
    
    glm::mat4 getPerspective();
    void setPerspecProjection(GLdouble fieldOfView, GLdouble aspectRatio, GLdouble nearPlane, GLdouble FarPlane);
    void setPerspectiveTranslation(glm::vec3 newTranslation);
    
    void setActiveProjectionMode(uchar activeProjectionMode);
    uchar getActiveProjectionMode();
    
};
