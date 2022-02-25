//
//  FileLoader.hpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"

#define OPERATING_SYSTEM_WINODWS 0
#define OPERATING_SYSTEM_UNIX 1

class FileLoader {
    
private:
    static void discoverOperatingSystemWith(char* programPath);
    static void removeExecutableNameFrom(char* programPath);
    
public:
    static char* programPath;
    static short operatingSystem;
        
    static void generatePathForFile(char* sourcePath, cchar* folder, cchar* fileName);
    static void formatProgramPathString(char* path);
    
};
