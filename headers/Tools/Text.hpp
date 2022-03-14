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

class Text : public Entity {
    
private:
    short elementsCountX;
    short elementsCountY;
    float characterScale;
    
    float fontmapWidth;
    int* string32bit;
    std::vector<glm::vec2> stringPositionList;
    int stringSize;
    
    void countStringSize(uchar* string);
    void calcCharPositionOnScreen(uchar* string);
    
public:
    Text(uint fontMapTextureId, uint textShaderId);
    void setText(uchar* string);
    int* get32bitString();
    int getStringSize();
    std::vector<glm::vec2> getStringPositionList();
};
