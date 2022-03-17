//
//  ModelLoader.hpp
//  MinervaEngine
//
//  Created by Anderson on 16/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "FileLoader.hpp"

class ModelLoader {
    
private:
    struct Model {
        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> texCoords;
        std::vector<int> indices;
    };
    static Model model;
    static void skipComments(FILE* file);
    
public:
    static uint load(cchar* modelFileName);
};
