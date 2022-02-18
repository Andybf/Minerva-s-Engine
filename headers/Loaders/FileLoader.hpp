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
    void discoverOperatingSystemWith(char* programPath);
    void removeExecutableNameFrom(char* programPath);
    
public:
    static char* programPath;
    static short operatingSystem;
    
    FileLoader(char* path);
    
    char* generatePathForFile(cchar* folder, cchar* fileName);
    
};
