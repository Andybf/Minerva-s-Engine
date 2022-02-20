//
//  VBO.cpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "VBO.hpp"

VBO::VBO() {
    
}

void VBO::bind(GLuint id) {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::deleteObject(GLuint id) {
    glDeleteBuffers(1, &id);
}

GLuint VBO::generateNewVBO(Entity* entity) {
    GLulong modelsSize = entity->model.size()*sizeof(GLfloat);
    GLulong colorsSize = entity->colors.size()*sizeof(GLfloat);
    GLulong texCrdSize = entity->textureCoords.size()*sizeof(GLfloat);
    GLuint vertexBufferObjectId = 0;
    
    glGenBuffers(1, &vertexBufferObjectId);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjectId);
    glBufferData(GL_ARRAY_BUFFER, modelsSize+colorsSize+texCrdSize, NULL, GL_STATIC_DRAW);
    
    glBufferSubData(GL_ARRAY_BUFFER, 0, modelsSize, entity->model.data());
    glBufferSubData(GL_ARRAY_BUFFER, modelsSize, colorsSize, entity->colors.data());
    glBufferSubData(GL_ARRAY_BUFFER, modelsSize+colorsSize, texCrdSize, entity->textureCoords.data());
    return vertexBufferObjectId;
}
