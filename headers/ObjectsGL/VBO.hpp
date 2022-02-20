//
//  VBO.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "GLObject.hpp"
#include "../World/Entity.hpp"

class VBO : GLObject {
    
private:
    
public:
    VBO();
    
    virtual void bind(GLuint id) override;
    virtual void unbind() override;
    virtual void deleteObject(GLuint id) override;
    
    GLuint generateNewVBO(Entity* entity);
};
