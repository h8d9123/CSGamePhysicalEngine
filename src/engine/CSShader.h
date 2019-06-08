#pragma once

/**
 * @file CSShader.h
 * @brief shader classes
 * @author wanghzh
 * @version 1.0
 * @date   Sun Apr 21 19:27:43 PDT 2019
 */

#include <GL/glew.h>
#include<iostream>
#include <string>
#include <fstream>
#include <sstream>



 
/**
 *@class GLShader
 *@brief wraps glxxxShaderxxx function
 *@author wanghzh
 *@version 1.0
 *@date 2019-06-08
 */
class GLShader
{
public:
    GLShader(GLenum shaderType);
    void setSourceFile(const std::string &pathName);
    void setSource(const std::string &src);
    GLenum getShaderType();
    bool isDeleted();
    bool isCompiled();
    GLint getLogLength();
    GLint getSourceLength();
    void getLog(std::string &log);
    void getSource(std::string& src);
    bool compile();
    GLuint getShaderId();
    
private:
    GLuint m_id;
};



