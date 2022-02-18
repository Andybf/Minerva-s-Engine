//
//  ShaderLoader.cpp
//  MinervaEngine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "ShaderLoader.hpp"

ShaderLoader::ShaderLoader() : FileLoader(FileLoader::programPath) {
    
}

GLuint ShaderLoader::load(cchar* vertexFileName, cchar* fragmentFileName) {
    char* vertexShaderSourcePath   = (char*)calloc(sizeof(char),256);
    char* fragmentShaderSourcePath = (char*)calloc(sizeof(char),256);
    
    strcpy(vertexShaderSourcePath, this->generatePathForFile("shaders",vertexFileName));
    strcpy(fragmentShaderSourcePath, this->generatePathForFile("shaders",fragmentFileName));
    
    char* vertexShaderSource = read(vertexShaderSourcePath);
    char* fragmentShaderSource = read(fragmentShaderSourcePath);
    
    int vertexId = compile(GL_VERTEX_SHADER, vertexShaderSource);
    int fragmentId = compile(GL_FRAGMENT_SHADER, fragmentShaderSource);
    
    free(vertexShaderSourcePath);
    free(fragmentShaderSourcePath);
    free(vertexShaderSource);
    free(fragmentShaderSource);
    
    return link(vertexId, fragmentId);
}

char* ShaderLoader::read(char* sourcePath) {
    FILE * file = fopen(sourcePath, "r");
    if(file == NULL) {
        printf("[ERROR] No such file has been found: %s\n",sourcePath);
        exit(1);
    }
    struct stat fileInfo;
    stat(sourcePath, &fileInfo);
    
    char * fileSource = (char*)calloc(sizeof(char), fileInfo.st_size);
    fread(fileSource, fileInfo.st_size, 1, file);
    return fileSource;
}

GLuint ShaderLoader::compile(int shaderType, char* sourceContents) {
    GLuint shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &sourceContents, 0);
    glCompileShader(shaderId);
    if (!check(GL_COMPILE_STATUS, shaderId)) {
        exit(1);
    }
    return shaderId;
}

GLuint ShaderLoader::link(int vextexId, int fragmentId) {
    GLuint shaderProgramId = glCreateProgram();
    glAttachShader(shaderProgramId, vextexId);
    glAttachShader(shaderProgramId, fragmentId);
    glLinkProgram(shaderProgramId);
    if ( !check(GL_LINK_STATUS,shaderProgramId) ) {
        exit(1);
    }
    return shaderProgramId;
}

bool ShaderLoader::check(int status, int shaderId) {
    int isShaderSuccessfullyCompiled = 1;
    glGetShaderiv(shaderId, status, &isShaderSuccessfullyCompiled);
    if (isShaderSuccessfullyCompiled != GL_TRUE) {
        char* infoLog = (char*) malloc(sizeof(char)*512);
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        printf("[ERROR] shaderId %d unchecked:\n%s\n",shaderId,infoLog);
        free(infoLog);
    }
    return isShaderSuccessfullyCompiled;
}
