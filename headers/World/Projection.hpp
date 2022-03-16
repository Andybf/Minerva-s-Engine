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
    
    float fieldOfView;
    float aspectRatio;
    float nearPlane;
    float farPlane;
    
public:
    Projection();
    
    glm::mat4 getOrthographic();
    void setOrthographic(float west, float east, float south, float north);
    
    glm::mat4 getPerspective();
    void setPerspecProjection(float fieldOfView, float aspectRatio, float nearPlane, float FarPlane);
    
    float getFieldOfView();
    void setFieldOfView(float fieldOfView);
    
    float getNearPlane();
    void setNearPlane(float nearPlane);
    
    float getFarPlane();
    void setFarPlane(float farPlane);
};
