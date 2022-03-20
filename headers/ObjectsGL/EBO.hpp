//
//  EBO.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "Core.hpp"

class EBO {
    
private:
    
public:
    
    static void bind(GLuint id);
    static void unbind();
    static void deleteObject(GLuint id);
    static GLuint generateNewEBO(std::vector<uint>* indices);
};
