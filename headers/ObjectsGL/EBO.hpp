//
//  EBO.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "GLObject.hpp"
#include "../World/Entity.hpp"

class EBO : GLObject {
    
private:
    
public:
    EBO();
    
    virtual void bind(GLuint id) override;
    virtual void unbind() override;
    virtual void deleteObject(GLuint id) override;
    
    GLuint generateNewEBO(Entity* entity);
};
