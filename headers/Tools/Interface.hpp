//
//  Interface.hpp
//  MinervaEngine
//
//  Created by Anderson on 07/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"
#include "../World/Entity.hpp"

class Interface : public Entity {
    
private:
    short elementsCountX;
    short elementsCountY;
    
    float fontmapWidth;
    float fontElementWidth;
    int* string32bit;
    glm::vec2* stringPos;
    int stringSize;
    
public:
    Interface();
    void setText(uchar* string);
    int* get32bitString();
    int getStringSize();
};
