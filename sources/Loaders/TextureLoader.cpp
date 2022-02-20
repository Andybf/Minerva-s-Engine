//
//  TextureLoader.cpp
//  MinervaEngine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#include "TextureLoader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../../dependencies/stb_image/stb_image.hpp"

TextureLoader::TextureLoader() : FileLoader() {
    
}

GLuint TextureLoader::loadTexture(cchar* textureFileName) {
    GLuint entityTextureId;
    
    char* textureFilePath = (char*)calloc(sizeof(char),256);
    strcpy(textureFilePath, this->generatePathForFile("textures",textureFileName));
    
    TextureLoader::Image* image = (TextureLoader::Image*) malloc(sizeof(TextureLoader::Image));
    stbi_set_flip_vertically_on_load(true);
    image->data = stbi_load(textureFilePath, &image->width, &image->height, &image->colorChannels, 0);
    this->checkTextureFileIsFound(image, textureFileName);
    
    TextureLoader::generateTextureId(&entityTextureId);
    TextureLoader::setTextureParameters();
    
    glTexImage2D(GL_TEXTURE_2D, MI_MIPMAP_LEVEL0, GL_RGBA, image->width, image->height, MI_BORDER_WIDTH, GL_RGBA, GL_UNSIGNED_BYTE, image->data);
    __glewGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
    return entityTextureId;
}

void TextureLoader::generateTextureId(GLuint* textureId) {
    glGenTextures(1, textureId);
    glBindTexture(GL_TEXTURE_2D, *textureId);
}

void TextureLoader::setTextureParameters() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
}

void TextureLoader::checkTextureFileIsFound(Image* image, cchar* textureFileName) {
    if (image->data == NULL) {
        printf("[MI][ERROR] The requested texture file was not found by the texture loader: %s\n",textureFileName);
        exit(1);
    }
}
