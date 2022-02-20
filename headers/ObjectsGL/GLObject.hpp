//
//  GLObject.hpp
//  Minerva's Engine
//
//  Created by Anderson on 19/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))
#define MI_STRIDE 0
#define MI_VAO_TO_GENERATE 1

class GLObject {
    
private:
    
public:
    virtual void bind(GLuint id) =0;
    virtual void unbind() =0;
    virtual void deleteObject(GLuint id) =0;
    
};
