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

#define MI_MIPMAP_0 0
#define MI_BORDER_WIDTH 0

class TextureLoader {
    
private:
    static struct Image{
        uchar* data;
        int width;
        int height;
        int colorChannels;
    } image;
    
    static void generateTextureId(GLuint* textureId, int texType);
    static void setTextureParameters(int texType);
    static void checkTextureFileIsFound(Image* image, cchar* textureFilePath);
    
public:
    static GLuint load2d(cchar* textureFilePath);
    static GLuint loadCubemap(std::vector<cchar*> textureFaces);
    
};
