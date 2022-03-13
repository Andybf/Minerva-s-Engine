//
//  DebuggerInterface.h
//  Minerva's Engine
//
//  Created by Anderson on 04/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#ifndef DebuggerInterface_h
#define DebuggerInterface_h

#include "Core.hpp"

class DebuggerInterface {
    
private:
    virtual void makeMatrixString(char* matrixStr, glm::mat4 matrix) =0;
    
public:
    virtual void updateModelMatrixInfo(glm::mat4 matrix) =0;
    virtual void updateCameraMatrixInfo(glm::mat4 matrix) =0;
    
    virtual void updateProjectionMatrixInfo(glm::mat4 matrix) =0;
    virtual float updateProjectionFovInfo(float fov) =0;
    virtual void updateProjectionAspectRatioInfo(float aspectRatio) =0;
    virtual void updateProjectionNearPlaneInfo(float nearPlane) =0;
    virtual void updateProjectionFarPlaneInfo(float farPlane) =0;
    
};

#endif
