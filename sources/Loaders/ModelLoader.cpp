//
//  ModelLoader.cpp
//  MinervaEngine
//
//  Created by Anderson on 16/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "ModelLoader.hpp"

ModelLoader::Model ModelLoader::model;

uint ModelLoader::load(cchar* modelFileName) {
    char* objectSourcePath = (char*)calloc(sizeof(char),256);
    
    FileLoader::generatePathForFile(objectSourcePath ,"objects", modelFileName);
    FILE* file = fopen(objectSourcePath, "r");
    if(file == NULL) {
        printf("[MI_ERROR] No such file has been found: %s\n",objectSourcePath);
        exit(1);
    }
    struct stat fileInfo;
    stat(objectSourcePath, &fileInfo);
    
    ModelLoader::skipComments(file);
    
    char coord[10];
    while(fgetc(file) == 'v' && fgetc(file) == ' ') {
        int x =0;
        while (coord[x-1] != 0x0A) {
            coord[x] = fgetc(file);
            if (coord[x] == '\n') {
                ModelLoader::model.vertices.push_back(atof(coord));
            }
            if (coord[x] == 0x20) {
                ModelLoader::model.vertices.push_back(atof(coord));
                x = -1;
            }
            x++;
        }
    }
    
    free(objectSourcePath);
    return 0;
}

void ModelLoader::skipComments(FILE* file) {
    fseek(file, 0x0, SEEK_SET);
    while ((fgetc(file) != '\n') || (fgetc(file) != 'v'));
    fseek(file, ftell(file)-1, SEEK_SET);
}
