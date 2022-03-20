//
//  ModelLoader.hpp
//  MinervaEngine
//
//  Created by Anderson on 16/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "FileLoader.hpp"
#include "../World/Entity.hpp"
#include "../ObjectsGL/VBO.hpp"
#include "../ObjectsGL/VAO.hpp"
#include "../ObjectsGL/EBO.hpp"

class ModelLoader {
    
private:
    static void moveFilePointerToBefore(FILE* file, char* substring);
    static void readVertex(FILE* file, cchar* VertexTypeName, std::vector<float>* vertexList);
    static void readIndices(FILE* file, std::vector<uint>* indicesList);
    
public:
    static void load(cchar* modelFileName, Entity* entity);
};

