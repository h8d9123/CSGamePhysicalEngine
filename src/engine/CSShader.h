#pragma once
#include <GL/glew.h>
#include<iostream>
#include <string>
#include <fstream>
#include <sstream>


/**
 * @file CSShader.h
 * @brief shader classes
 * @author wanghzh
 * @email 2466621355@qq.com
 * @version 1.0
 * @date   Sun Apr 21 19:27:43 PDT 2019
 */

/**
 * @class CSShaderBase
 * @brief create a shader using text;
 */
class CSShaderBase
{
public:
    CSShaderBase() {}
    CSShaderBase(const char* fileName, GLenum shaderType, bool isFile);
    CSShaderBase(const GLchar* pShaderString, GLenum shaderType);
    int state(std::string msg);
    ~CSShaderBase() {}
private:
    GLboolean compile();

private:
    GLuint m_shaderId;
    int m_state;
public:
    enum {
        SUCCESS,
        INVALID_SHADER_TYPE,
        INVALID_SHADER_CONTENT,
        INVALID_SHADER_FILE,
        FAIL_COMPILE_FILE,
    };
};
