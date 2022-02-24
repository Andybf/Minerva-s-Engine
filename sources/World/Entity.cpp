//
//  Entity.cpp
//  Minerva's Engine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity() {
    this->matrix = glm::mat4(1.0f);
    this->modelType = GL_TRIANGLES;
    this->isEnabled = true;
    this->texture = {
        .id = 0,
        .type = GL_TEXTURE_2D,
        .dimensions = MI_TEXCOORD_ST
    };
    this->shader = {
        .id = 0,
        .texture = "texture0",
        .model = "modelMatrix", .view = "viewMatrix", .projection = "projectionMatrix",
        .position = ShaderAttribute { .name = "vtxPosition", .dimensions = MI_VECTORS_XYZ},
        .vecColor = ShaderAttribute { .name = "vtxColor", .dimensions = MI_COLORS_RGBA},
        .texCoord = ShaderAttribute { .name = "inTextureCoord", .dimensions = MI_TEXCOORD_ST}
    };
}

glm::mat4 Entity::getMatrix() {
    return this->matrix;
}

void Entity::setScale(glm::vec3 scale) {
    this->matrix = glm::scale(this->matrix, scale);
}
glm::vec3 Entity::getScale() {
    glm::vec3 scale;
    for (short i = 0; i < 3; ++i) {
        scale[i] = glm::length(this->matrix[i]);
        this->matrix[i] /= scale[i];
    }
    return scale;
}

void Entity::setPosition(glm::vec3 position) {
    this->matrix = glm::translate(this->matrix, position);
}
glm::vec3 Entity::getPosition() {
    return this->matrix[3];
}

void Entity::setOrientation(float angle, glm::vec3 orientation) {
    this->matrix = glm::rotate(this->matrix, glm::radians(angle), orientation);
}
glm::quat Entity::getOrientation() {
    return glm::quat_cast(this->matrix);
}
