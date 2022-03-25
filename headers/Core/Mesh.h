//
//  Mesh.h
//  Minerva's Engine
//
//  Created by Anderson on 25/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"

struct Mesh {
    uint vboId;
    uint vaoId;
    uint eboId;
    uint indicesSize;
    uint verticesSize;
};
