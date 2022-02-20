//
//  Camera.cpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera() {
    this->matrix = glm::mat4(1.0f);
    this->upDirection = glm::vec3(0.0f, 1.0f, 0.0f);
    this->orientation = glm::vec3(0.0f,0.0f,-1.0f);
}

glm::mat4 Camera::getMatrix() {
    return this->matrix;
}

void Camera::setPosition(glm::vec3 position) {
    this->matrix = glm::translate(this->matrix, position);
}
glm::vec3 Camera::getPosition() {
    return this->position;
}

void Camera::setOrientation(float angle, glm::vec3 orientation) {
    this->matrix = glm::rotate(this->matrix, glm::radians(0.5f), orientation);
    this->orientation = glm::vec3(this->orientation.x+orientation.x, this->orientation.y+orientation.y, this->orientation.z+orientation.z);
}

glm::quat Camera::getOrientation() {
    return this->orientation;
}
