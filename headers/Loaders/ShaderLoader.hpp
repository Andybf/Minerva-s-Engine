//
//  ShaderLoader.hpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"
#include "FileLoader.hpp"

class ShaderLoader : virtual public FileLoader {
    
private:
    static char* read(char* sourcePath);
    static GLuint compile(int shaderType, char* sourceContents);
    static GLuint link(int vextexId, int fragmentId);
    static void check(int status, int shaderId);
    
public:
    static GLuint load(cchar* vertexFileName, cchar* fragmentFileName);
};
