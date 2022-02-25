//
//  FileLoader.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "FileLoader.hpp"

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

void FileLoader::generatePathForFile(char* sourcePath, cchar* folder, cchar* filename) {
    if (FileLoader::operatingSystem == OPERATING_SYSTEM_WINODWS) {
        sprintf(sourcePath, "%s\\%s\\%s", FileLoader::programPath,folder,filename);
    } else {
        sprintf(sourcePath, "%s/%s/%s", FileLoader::programPath,folder,filename);
    }
}

void FileLoader::formatProgramPathString(char* path) {
    FileLoader::discoverOperatingSystemWith(path);
    FileLoader::removeExecutableNameFrom(path);
}

