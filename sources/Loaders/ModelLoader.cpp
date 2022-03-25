//
//  ModelLoader.cpp
//  MinervaEngine
//
//  Created by Anderson on 16/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "ModelLoader.hpp"

Mesh* ModelLoader::load(cchar* modelFileName, uint relatedShaderId) {
    char* objectSourcePath = (char*)calloc(sizeof(char),256);
    FileLoader::generatePathForFile(objectSourcePath ,"objects", modelFileName);
    FILE* file = fopen(objectSourcePath, "r");
    if (file == NULL) {
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
    
    Mesh* mesh = (Mesh*)calloc(sizeof(Mesh*), 1);
    mesh->vboId = VBO::generateNewVBO(vertices,normals,texCoords);
    mesh->vaoId = VAO::generateNewVAO();
    VAO::bind(mesh->vaoId);
    VAO::linkAttribute(mesh->vaoId, glGetAttribLocation(relatedShaderId, "geometry"), MI_VECTORS_XYZ,  0);
    VAO::linkAttribute(mesh->vaoId, glGetAttribLocation(relatedShaderId, "normals" ), MI_NORMALS_XYZ,  modelsSize);
    VAO::linkAttribute(mesh->vaoId, glGetAttribLocation(relatedShaderId, "texCoord"), MI_TEXCOORD_STR, normalsSize);
    if (indices.size() > 0) {
        EBO::generateNewEBO(&indices);
        mesh->indicesSize = (uint)indices.size();
    } else {
        mesh->verticesSize = (uint)vertices.size();
    }
    VAO::unbind();
    VBO::unbind();
    EBO::unbind();
    
    return mesh;
}

void ModelLoader::moveFilePointerToBefore(FILE* file, char* substring) {
    short bufferBlockSize = 64;
    char* buffer = (char*) calloc(sizeof(char*), bufferBlockSize);
    long offset = -1;
    while (offset < 0) {
        fread(buffer, bufferBlockSize, sizeof(char), file);
        offset = strstr(buffer, substring) - buffer;
    }
    fseek(file, -strlen(buffer)+offset, SEEK_CUR);
    free(buffer);
}

void ModelLoader::readVertex(FILE* file, cchar* vertexName, std::vector<float>* vertexList) {
    char* buffer = (char*)calloc(sizeof(char*),10);
    int vertexNameSize = (int)strlen(vertexName);
    fread(buffer, vertexNameSize, 1, file);
    while(strcmp(buffer, vertexName) == 0) {
        int index = -1;
        do {
            index++;
            buffer[index] = fgetc(file);
            if (buffer[index] == 'e') {
                fseek(file, +4, SEEK_CUR);
            }
            if (buffer[index] == ' ') {
                vertexList->push_back(atof(buffer));
                index = -1;
            }
        } while(buffer[index] != '\n');
        vertexList->push_back(atof(buffer));
        memset(&buffer[0], 0, sizeof(buffer));
        fread(buffer, vertexNameSize, 1, file);
    }
    free(buffer);
    fseek(file, ftell(file)-vertexNameSize, SEEK_SET);
}

void ModelLoader::readIndices(FILE* file, std::vector<uint>* indicesList) {
    char* buffer = (char*) calloc(sizeof(char*), 5);
    while (fgetc(file) == 'f' && fgetc(file) == ' ') {
        char readChar = NULL;
        while(readChar != '\n' && readChar != EOF) {
            readChar = fgetc(file);
            int x=0;
            while(readChar >= '0' && readChar <='9' ) {
                buffer[x] = readChar;
                readChar = fgetc(file);
                x++;
            }
            indicesList->push_back(atof(buffer)-1);
            memset(&buffer[0], 0, sizeof(buffer));
            while(readChar != ' ' && readChar != '\n' && readChar != EOF) {
                readChar = fgetc(file);
            }
        }
    }
    free(buffer);
    fseek(file, ftell(file)-2, SEEK_SET);
}
