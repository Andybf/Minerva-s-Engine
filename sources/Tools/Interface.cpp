//
//  Interface.cpp
//  MinervaEngine
//
//  Created by Anderson on 07/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Interface.hpp"

Interface::Interface() {
    this->elementsCountX = 16;
    this->elementsCountY = 16;
    
    this->fontmapWidth = 256.0f;
    this->fontElementWidth = this->fontmapWidth/this->elementsCountX;
}

void Interface::setText(uchar* string) {
    int stringSize = 0;
    while(string[stringSize] != '\0') {
        stringSize++;
    }
    
    free(this->string32bit);
    this->string32bit = (int*) calloc(sizeof(int), stringSize);
    this->stringPos = (glm::vec2*) calloc(sizeof(glm::vec2), stringSize);
    
    for(short x=0; x<stringSize; x++) {
        if (string[x] == 0x0A) {
            this->string32bit[x] = 0xFF;
        } else {
            this->string32bit[x] = string[x];
        }
    }
    this->stringSize = stringSize;
}

int* Interface::get32bitString() {
    return this->string32bit;
}

int Interface::getStringSize() {
    return this->stringSize;
}
