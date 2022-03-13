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
    this->orthographicMatrix = glm::mat4(1.0f);
}

// Orthographic ================================================================

glm::mat4 Projection::getOrthographic() {
    return this->orthographicMatrix;
}

void Projection::setOrthographic(float west, float east, float south, float north) {
    this->orthographicMatrix = glm::ortho(west, east, south, north);
}

// Perspective =================================================================

glm::mat4 Projection::getPerspective() {
    return this->perspectiveMatrix;
}

void Projection::setPerspecProjection(float fieldOfView, float aspectRatio, float nearPlane, float farPlane) {
    this->fieldOfView = fieldOfView;
    this->nearPlane = nearPlane;
    this->farPlane = farPlane;
    this->perspectiveMatrix = glm::perspective(fieldOfView, aspectRatio, nearPlane, farPlane);
}

void Projection::setPerspectiveTranslation(glm::vec3 newTranslation) {
    this->perspectiveMatrix = glm::translate(this->perspectiveMatrix, newTranslation);
}

float Projection::getFieldOfView() {
    return this->fieldOfView;
}
void Projection::setFieldOfView(float fieldOfView) {
    this->fieldOfView = fieldOfView;
    this->perspectiveMatrix = glm::perspective(this->fieldOfView, this->aspectRatio, this->nearPlane, this->farPlane);
}

float Projection::getNearPlane() {
    return this->nearPlane;
}
void Projection::setNearPlane(float nearPlane) {
    this->nearPlane = nearPlane;
}

float Projection::getFarPlane() {
    return this->farPlane;
}
void Projection::setFarPlane(float farPlane) {
    this->farPlane = farPlane;
}
