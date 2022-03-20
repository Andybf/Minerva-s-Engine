//
//  FileLoader.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "FileLoader.hpp"

void FileLoader::removeExecutableNameFrom(cchar* path) {
    std::string tempPath = path;
    for (ushort x = tempPath.size(); x > 0; x--) {
        if (tempPath[x] == '/' || tempPath[x] == '\\') {
            tempPath = tempPath.replace(x, tempPath.size(), "\0");
            break;
        }
    }
    FileLoader::programPath = (char*)calloc(sizeof(char*),tempPath.size());
    strcpy(FileLoader::programPath, tempPath.c_str());
}

void FileLoader::generatePathForFile(char* sourcePath, cchar* folder, cchar* filename) {
    sprintf(sourcePath, "%s%s%s%s%s", FileLoader::programPath,MI_OS_PATH_FORMAT,folder,MI_OS_PATH_FORMAT,filename);
}

char* FileLoader::read(char* sourcePath) {
    FILE* file = fopen(sourcePath, "r");
    if(file == NULL) {
        printf("[MI_ERROR] No such file has been found: %s\n",sourcePath);
        exit(1);
    }
    struct stat fileInfo;
    stat(sourcePath, &fileInfo);
    
    char* fileSource = (char*) calloc(sizeof(char*), fileInfo.st_size);
    fread(fileSource, fileInfo.st_size, 1, file);
    return fileSource;
}
