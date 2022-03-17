//
//  FileLoader.hpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#ifdef _WIN32
    #define MI_OS_PATH_FORMAT "\\" //for Windows based system
#else
    #define MI_OS_PATH_FORMAT "/" //for Unix-like system
#endif

#include "../Core.hpp"

class FileLoader {
    
private:
    
public:
    static char* programPath;
        
    static void generatePathForFile(char* sourcePath, cchar* folder, cchar* fileName);
    static void removeExecutableNameFrom(cchar* programPath);
    static char* read(char* sourcePath);
    
};
