//
//  ModelLoader.cpp
//  MinervaEngine
//
//  Created by Anderson on 16/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "ModelLoader.hpp"

void ModelLoader::load(cchar* modelFileName, Entity* entity) {
    char* objectSourcePath = (char*)calloc(sizeof(char),256);
    FileLoader::generatePathForFile(objectSourcePath ,"objects", modelFileName);
    FILE* file = fopen(objectSourcePath, "r");
    if(file == NULL) {
        printf("[MI_ERROR] No such file has been found: %s\n",objectSourcePath);
        exit(1);
    }
    free(objectSourcePath);
    
    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> texCoords;
    std::vector<uint> indices;
    
    ModelLoader::moveFilePointerToBefore(file,(char*)"v ");
    ModelLoader::readVertex(file, "v ", &vertices);
    ModelLoader::readVertex(file, "vn ", &normals);
    ModelLoader::readVertex(file, "vt ", &texCoords);
    ModelLoader::moveFilePointerToBefore(file,(char*)"f ");
    ModelLoader::readIndices(file, &indices);
    fclose(file);
    
    ulong modelsSize = vertices.size()*sizeof(GLfloat);
    ulong normalsSize = modelsSize + normals.size()*sizeof(GLfloat);
    
    entity->vboId = VBO::generateNewVBO(vertices,normals,texCoords);
    int vaoId = VAO::generateNewVAO();
    VAO::bind(vaoId);
    VAO::linkAttribute(vaoId, glGetAttribLocation(entity->relatedShaderId, "geometry"), MI_VECTORS_XYZ,  0);
    VAO::linkAttribute(vaoId, glGetAttribLocation(entity->relatedShaderId, "normals" ), MI_NORMALS_XYZ,  modelsSize);
    VAO::linkAttribute(vaoId, glGetAttribLocation(entity->relatedShaderId, "texCoord"), MI_TEXCOORD_STR, normalsSize);
    if (indices.size() > 0) {
        EBO::generateNewEBO(&indices);
        entity->indicesSize = (uint)indices.size();
    } else {
        entity->verticesSize = (uint)vertices.size();
    }
    VAO::unbind();
    VBO::unbind();
    EBO::unbind();
    entity->vaoId = vaoId;
}

void ModelLoader::moveFilePointerToBefore(FILE* file, char* substring) {
    short bufferBlockSize = 64;
    char* buffer = (char*) calloc(sizeof(char*), bufferBlockSize);
    fread(buffer, bufferBlockSize, sizeof(char), file);
    long offset = strstr(buffer, substring) - buffer;
    fseek(file, -strlen(buffer)+offset, SEEK_CUR);
    free(buffer);
}

void ModelLoader::readVertex(FILE* file, cchar* vertexName, std::vector<float>* vertexList) {
    char* buffer = (char*)calloc(sizeof(char*),10);
    int vertexNameSize = (int)strlen(vertexName);
    fread(buffer, vertexNameSize, 1, file);
    while(strcmp(buffer, vertexName) == 0) {
        int counter = -1;
        do {
            counter++;
            buffer[counter] = fgetc(file);
            if (buffer[counter] == ' ') {
                vertexList->push_back(atof(buffer));
                counter = -1;
            }
        } while (buffer[counter] != '\n');
        vertexList->push_back(atof(buffer));
        buffer[vertexNameSize] = '\0';
        fread(buffer, vertexNameSize, 1, file);
    }
    free(buffer);
    fseek(file, ftell(file)-vertexNameSize, SEEK_SET);
}

void ModelLoader::readIndices(FILE* file, std::vector<uint>* indicesList) {
    char* buffer = (char*) calloc(sizeof(char*), 4);
    while (fgetc(file) == 'f' && fgetc(file) == ' ') {
        uchar readChar = '\0';
        while(readChar != '\n' && readChar != 0xFF) {
            readChar = fgetc(file);
            int x=0;
            while(readChar >= 0x30 && readChar <=0x39 ) {
                buffer[x] = readChar;
                readChar = fgetc(file);
                x++;
            }
            indicesList->push_back(atof(buffer)-1);
            while(readChar != ' ' && readChar != '\n' && readChar != 0xFF) {
                readChar = fgetc(file);
            }
        }
    }
    free(buffer);
    fseek(file, ftell(file)-2, SEEK_SET);
}
