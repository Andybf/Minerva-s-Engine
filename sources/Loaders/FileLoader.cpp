//
//  FileLoader.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "FileLoader.hpp"

FileLoader::FileLoader() {
    
}

void FileLoader::discoverOperatingSystemWith(char* programPath) {
    std::string path = programPath;
    for (ushort x = path.size(); x>0; x--) {
        if (path[x] == '\\') {
            FileLoader::operatingSystem = OPERATING_SYSTEM_WINODWS;
            break;
        } else if (path[x] == '/') {
            FileLoader::operatingSystem = OPERATING_SYSTEM_UNIX;
            break;
        }
    }
}

void FileLoader::removeExecutableNameFrom(char* path) {
    std::string tempPath = path;
    for (ushort x = tempPath.size(); x > 0; x--) {
        if (tempPath[x] == '/' || tempPath[x] == '\\') {
            tempPath = tempPath.replace(x, tempPath.size(), "\0");
            break;
        }
    }
    strcpy(path, tempPath.c_str());
}

char* FileLoader::generatePathForFile(cchar* folder, cchar* filename) {
    char* filePath = (char*) calloc(sizeof(char),256);
    if (FileLoader::operatingSystem == OPERATING_SYSTEM_WINODWS) {
        sprintf(filePath, "%s\\%s\\%s", FileLoader::programPath,folder,filename);
    } else {
        sprintf(filePath, "%s/%s/%s", FileLoader::programPath,folder,filename);
    }
    return filePath;
}

void FileLoader::formatProgramPathString(char* path) {
    this->discoverOperatingSystemWith(path);
    this->removeExecutableNameFrom(path);
}

