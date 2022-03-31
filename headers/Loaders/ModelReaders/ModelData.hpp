//
//  ModelData.h
//  Minerva's Engine
//
//  Created by Anderson on 28/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include <vector>

struct ModelData{
    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> texCoords;
    std::vector<unsigned int> indices;
};
