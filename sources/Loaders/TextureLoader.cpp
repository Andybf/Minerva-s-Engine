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

GLuint TextureLoader::load2d(cchar* textureFileName) {
    GLuint entityTextureId;
    
    char* textureFilePath = (char*)calloc(sizeof(char),256);
    FileLoader::generatePathForFile(textureFilePath, "textures",textureFileName);
    
    TextureLoader::Image* image = (TextureLoader::Image*) malloc(sizeof(TextureLoader::Image));
    stbi_set_flip_vertically_on_load(true);
    image->data = stbi_load(textureFilePath, &image->width, &image->height, &image->colorChannels, 0);
    TextureLoader::checkTextureFileIsFound(image, textureFileName);
    
    TextureLoader::generateTextureId(&entityTextureId, GL_TEXTURE_2D);
    TextureLoader::setTextureParameters(GL_TEXTURE_2D);
    
    MI_TEST(glTexImage2D(GL_TEXTURE_2D, MI_MIPMAP_0, GL_RGBA, image->width, image->height, MI_BORDER_WIDTH, GL_RGBA, GL_UNSIGNED_BYTE, image->data));
    MI_TEST(glGenerateMipmap(GL_TEXTURE_2D));
    
    stbi_image_free(image->data);
    free(image);
    free(textureFilePath);
    return entityTextureId;
}

GLuint TextureLoader::loadCubemap(std::vector<cchar*> textureFaces) {
    GLuint entityTextureId =0;
    TextureLoader::generateTextureId(&entityTextureId, GL_TEXTURE_CUBE_MAP);
    char* textureFilePath = (char*)calloc(sizeof(char),256);
    TextureLoader::Image* image = (TextureLoader::Image*) malloc(sizeof(TextureLoader::Image));
    
    for (byte x=0; x<textureFaces.size(); x++) {
        FileLoader::generatePathForFile(textureFilePath, "textures", textureFaces[x]);
        image->data = stbi_load(textureFilePath, &image->width, &image->height, &image->colorChannels, 0);
        MI_TEST(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+x, MI_MIPMAP_0, GL_RGB, image->width, image->height, MI_BORDER_WIDTH, GL_RGB, GL_UNSIGNED_BYTE, image->data));
        TextureLoader::checkTextureFileIsFound(image, textureFilePath);
        stbi_image_free(image->data);
    }
    free(image);
    free(textureFilePath);
    glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
    TextureLoader::setTextureParameters(GL_TEXTURE_CUBE_MAP);
    return entityTextureId;
}

void TextureLoader::generateTextureId(GLuint* textureId, int texType) {
    MI_TEST(glGenTextures(1, textureId));
    MI_TEST(glBindTexture(texType, *textureId));
}

void TextureLoader::setTextureParameters(int texType) {
    MI_TEST(glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    MI_TEST(glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    MI_TEST(glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    MI_TEST(glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    MI_TEST(glTexParameteri(texType, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE));
}

void TextureLoader::checkTextureFileIsFound(Image* image, cchar* textureFileName) {
    if (image->data == NULL) {
        printf("[MI_ERROR] The requested texture file was not found by the texture loader: %s\n",textureFileName);
        exit(1);
    }
}
