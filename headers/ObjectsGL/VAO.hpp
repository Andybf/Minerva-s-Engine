//
//  VAO.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"

class VAO {
    
private:
    
public:
    
    static void bind(GLuint id);
    static void unbind();
    static void deleteObject(GLuint id);
    
    static GLuint generateNewVAO();
    static void linkAttribute(GLuint vertexArrayObject, GLuint shaderAttribute, short numElements, ulong offset);
};
