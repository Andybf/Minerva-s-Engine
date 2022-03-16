//
//  VAO.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "GLObject.hpp"
#include "../Core.hpp"

class VAO : GLObject {
    
private:
    
public:
    VAO();
    
    virtual void bind(GLuint id) override;
    virtual void unbind() override;
    virtual void deleteObject(GLuint id) override;
    
    GLuint generateNewVAO();
    void linkAttribute(GLuint vertexArrayObject, GLuint shaderAttribute, short numElements, ulong offset);
};
