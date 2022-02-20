//
//  Projection.cpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "../../headers/World/Projection.hpp"

Projection::Projection() {
    this->perspectiveMatrix = glm::mat4(1.0f);
}

void Projection::setActiveProjectionMode(uchar activeProjectionMode) {
    this->activeProjectionMode = activeProjectionMode;
}

uchar Projection::getActiveProjectionMode() {
    return this->activeProjectionMode;
}

glm::mat4 Projection::getPerspective() {
    return this->perspectiveMatrix;
}

void Projection::setPerspecProjection(
                                      GLdouble fieldOfView,
                                      GLdouble aspectRatio,
                                      GLdouble nearPlane,
                                      GLdouble FarPlane
                                      ) {
    this->perspectiveMatrix = glm::perspective(fieldOfView,aspectRatio,nearPlane,FarPlane);
}

void Projection::setPerspectiveTranslation(glm::vec3 newTranslation) {
    this->perspectiveMatrix = glm::translate(this->perspectiveMatrix, newTranslation);
}
