//
//  TextureLoader.hpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../Core.hpp"
#include "FileLoader.hpp"

#define MI_MIPMAP_LEVEL0 0
#define MI_BORDER_WIDTH 0

class TextureLoader : virtual public FileLoader {
    
private:
    struct Image{
        uchar* data;
        int width;
        int height;
        int colorChannels;
    } image;
    
    void generateTextureId(GLuint* textureId);
    void setTextureParameters();
    void checkTextureFileIsFound(Image* image, cchar* textureFileName);
    
public:
    TextureLoader();
    
    GLuint loadTexture(cchar* textureFilePath);
    
};
