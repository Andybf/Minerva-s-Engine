//
//  VAO.cpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "VAO.hpp"

VAO::VAO() {
    
}

void VAO::bind(GLuint id) {
    glBindVertexArray(id);
}

void VAO::unbind() {
    glBindVertexArray(0);
}

void VAO::deleteObject(GLuint id) {
    glDeleteVertexArrays(1, &id);
}

GLuint VAO::generateNewVAO() {
    GLuint vertexArrayObject = 0;
    glGenVertexArrays(MI_VAO_TO_GENERATE, &vertexArrayObject);
    return vertexArrayObject;
}

void VAO::linkAttribute(GLuint vertexArrayObject, GLuint shaderAttribute, short numElements, GLulong offset) {
    glEnableVertexAttribArray(shaderAttribute);
    glVertexAttribPointer(shaderAttribute, numElements, GL_FLOAT, GL_FALSE, MI_STRIDE, BUFFER_OFFSET(offset));
}
