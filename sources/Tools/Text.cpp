//
//  Interface.cpp
//  MinervaEngine
//
//  Created by Anderson on 07/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "Text.hpp"

Text::Text(uint fontMapTextureId, uint textShaderId) {
    this->fontmapWidth = 256.0f;
    this->elementsCountX = 16;
    this->elementsCountY = 16;
    this->characterScale = this->fontmapWidth/this->elementsCountY;
    this->setPosition(glm::vec3(0,characterScale,1));
    this->setScale(glm::vec3(characterScale));
    this->relatedTextureId = fontMapTextureId;
    this->relatedShaderId = textShaderId;
    this->model = std::vector<float> {
        0.0f,  0.0f, 0.0f,
        1.0f,  0.0f, 0.0f,
        1.0f,  1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
    this->colors = std::vector<float> {
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f
    };
    this->textureCoords = std::vector<float> {
        0.0000f, 0.0000f, // 0 0
        0.0625f, 0.0000f, // 1 0
        0.0625f, 0.0625f, // 1 1
        0.0000f, 0.0625f  // 0 1
    };
    this->indices = std::vector<uint> {
        0, 1, 3,
        1, 2, 3
    };
}

void Text::countStringSize(uchar* string) {
    this->stringSize = 0;
    while(string[this->stringSize] != '\0') {
        this->stringSize++;
    }
}

void Text::calcCharPositionOnScreen(uchar* string) {
    short x = 0;
    short y = 0;
    stringPositionList.clear();
    for(ushort c=0; c<stringSize; c++) {
        stringPositionList.push_back(glm::vec2(x,y));
        if (string[c] == '\n') {
            y++;
            x=0;
            this->string32bit[c] = 0xFF;
        } else {
            this->string32bit[c] = string[c];
            x++;
        }
    }
}

void Text::setText(uchar* string) {
    free(this->string32bit);
    this->countStringSize(string);
    this->string32bit = (int*) calloc(sizeof(int), stringSize);
    this->calcCharPositionOnScreen(string);
}

int* Text::get32bitString() {
    return this->string32bit;
}

int Text::getStringSize() {
    return this->stringSize;
}

std::vector<glm::vec2> Text::getStringPositionList() {
    return this->stringPositionList;
}
