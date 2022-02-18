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
    #include <GL/glew.h>
    #include <GL/glfw.h>
    #include <Windows.h>
#endif

#ifdef __linux__
    #include <GL/gl.h>
    #include <GL/glew.h>
    #include <GL/glfw.h>
    #include <unistd.h>
#endif

#ifdef __APPLE__
    #define GLEW_STATIC
    #define GLFW_STATIC
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    #define glGenVertexArraysAE glGenVertexArrays
    #define glBindVertexArrayAE glBindVertexArray
    #define glDeleteVertexArraysAE glDeleteVertexArrays
    #include "../dependencies/glew/glew.h"
    #include "../dependencies/glfw/glfw3.h"
    #include <unistd.h>
#endif

#include "../dependencies/glm/glm.hpp"
#include "../dependencies/glm/ext/matrix_transform.hpp"
#include "../dependencies/glm/gtx/matrix_decompose.hpp"
#include "../dependencies/glm/ext/matrix_clip_space.hpp"
#include "../dependencies/glm/gtc/random.hpp"
#include "../dependencies/glm/gtc/type_ptr.hpp"
#include "../dependencies/glm/gtx/rotate_vector.hpp"
#include "../dependencies/glm/gtx/vector_angle.hpp"

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>

typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef const    char  cchar;
typedef unsigned const char ucchar;
