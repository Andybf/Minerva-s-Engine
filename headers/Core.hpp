//
//  Core.h
//  Minerva's Engine
//
//  Created by Anderson on 17/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#ifdef _WIN32
    #define GLEW_STATIC
    #define GLFW_STATIC
    #include <GL/gl.h>
    #include "../dependencies/glew/glew.h"
    #include <GL/glfw.h>
    #include <Windows.h>
    #include <math.h>
#endif

#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glew.h>
    #include <GL/glfw.h>
    #include <unistd.h>
    #include <math.h>
#endif

#ifdef __APPLE__
    #define GLFW_STATIC
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    #include <OpenGL/gl3.h>
    #include "../dependencies/glfw/glfw3.h"
    #include <unistd.h>
#endif

#include "../dependencies/glm/glm.hpp"
#include "../dependencies/glm/gtx/matrix_decompose.hpp"
#include "../dependencies/glm/gtc/random.hpp"
#include "../dependencies/glm/gtx/rotate_vector.hpp"

#include <stdio.h>
#include <sys/stat.h>

#include <iostream>
#include <vector>

typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef unsigned const char ucchar;
typedef unsigned int   uint;
typedef unsigned long  ulong;
typedef const float cfloat;
typedef const    char  cchar;
typedef char byte;

#define KEY_TAB GLFW_KEY_TAB
#define KEY_0 GLFW_KEY_0
#define KEY_1 GLFW_KEY_1
#define KEY_2 GLFW_KEY_2
#define KEY_3 GLFW_KEY_3
#define KEY_4 GLFW_KEY_4
#define KEY_5 GLFW_KEY_5
#define KEY_6 GLFW_KEY_6
#define KEY_7 GLFW_KEY_7
#define KEY_8 GLFW_KEY_8
#define KEY_9 GLFW_KEY_9

#define KEY_NUMPAD_0 GLFW_KEY_KP_0
#define KEY_NUMPAD_1 GLFW_KEY_KP_1
#define KEY_NUMPAD_2 GLFW_KEY_KP_2
#define KEY_NUMPAD_3 GLFW_KEY_KP_3
#define KEY_NUMPAD_4 GLFW_KEY_KP_4
#define KEY_NUMPAD_5 GLFW_KEY_KP_5
#define KEY_NUMPAD_6 GLFW_KEY_KP_6
#define KEY_NUMPAD_7 GLFW_KEY_KP_7
#define KEY_NUMPAD_8 GLFW_KEY_KP_8
#define KEY_NUMPAD_9 GLFW_KEY_KP_9
#define KEY_NUMPAD_DECIMAL GLFW_KEY_KP_DECIMAL

#define KEY_A GLFW_KEY_A
#define KEY_B GLFW_KEY_B
#define KEY_C GLFW_KEY_C
#define KEY_D GLFW_KEY_D
#define KEY_E GLFW_KEY_E
#define KEY_F GLFW_KEY_F
#define KEY_G GLFW_KEY_G
#define KEY_H GLFW_KEY_H
#define KEY_I GLFW_KEY_I
#define KEY_J GLFW_KEY_J
#define KEY_K GLFW_KEY_K
#define KEY_L GLFW_KEY_L
#define KEY_M GLFW_KEY_M
#define KEY_N GLFW_KEY_N
#define KEY_O GLFW_KEY_O
#define KEY_P GLFW_KEY_P
#define KEY_Q GLFW_KEY_Q
#define KEY_R GLFW_KEY_R
#define KEY_S GLFW_KEY_S
#define KEY_T GLFW_KEY_T
#define KEY_U GLFW_KEY_U
#define KEY_V GLFW_KEY_V
#define KEY_W GLFW_KEY_W
#define KEY_X GLFW_KEY_X
#define KEY_Y GLFW_KEY_Y
#define KEY_Z GLFW_KEY_Z

#define MI_TEXCOORD_ST 2
#define MI_TEXCOORD_STR 3
#define MI_VECTORS_XY 2
#define MI_VECTORS_XYZ 3
#define MI_VECTORS_XYZW 4
#define MI_COLORS_RGB 3
#define MI_COLORS_RGBA 4

#define MI_STARTING_INDEX 0
#define MI_COUNT 1

#define MI_SIZE_CHAR 1
#define MI_SIZE_SHORT 2
#define MI_SIZE_INT 4
#define MI_SIZE_FLOAT 8

#ifdef MI_DEBUG
    #define MI_TEST(glFunctionCall)\
        while(glGetError() != GL_NO_ERROR);\
        glFunctionCall;\
        while (GLenum errorCode = glGetError()) {\
            printf("[GL_ERROR] code: %d|0x%x | line: %d\n",errorCode,errorCode,__LINE__);\
        }
#else
    #define MI_TEST(glFunctionCall)\
        glFunctionCall
#endif
