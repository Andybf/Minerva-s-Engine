//
//  VBO.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"

class VBO {
    
private:
    
public:
    
    static void bind(GLuint id);
    static void unbind();
    static void deleteObject(GLuint id);
    static GLuint generateNewVBO(std::vector<float> vertices,
                                 std::vector<float> normals,
                                 std::vector<float> texCoords);
};
