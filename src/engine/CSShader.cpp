/**
 * @file CSShader.cpp
 * @brief
 * @detail
 * @detail
 * @author wanghzh
 * @version 1.0
 * @date Sun Apr 21 20:00:03 PDT 2019
 */

#include "CSShader.h"


/**
 * @brief create and compile a shader
 * @param fileName a shader filename
 * @param shaderType Specifies the type of shader to be created. @see glCreateShader
 */
CSShaderBase::CSShaderBase(const char* fileName, GLenum shaderType, bool isFile)
{
    std::string shaderStr;
    std::ifstream hFile;
    hFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        hFile.open(fileName);
        std::stringstream ss;
        ss << hFile.rdbuf();
        hFile.close();
        shaderStr = ss.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout<<"Fail to read shader file!"<<std::endl;
        m_state = CSShaderBase::INVALID_SHADER_FILE;
        return;
    }
    CSShaderBase(shaderStr.c_str(), shaderType);
}


/**
 * @brief create and compile a shader
 * @param pShaderString a pointer to Shader Content.
 * @param shaderType Specifies the type of shader to be created. @see glCreateShader
 */
CSShaderBase::CSShaderBase(const GLchar* pShaderString, GLenum shaderType)
{ 
    if (!pShaderString) 
    {
        m_state = CSShaderBase::INVALID_SHADER_CONTENT;
        return;
    }

    //create shader
    m_shaderId = glCreateShader(shaderType);
    if (!m_shaderId) 
    {
        m_state = CSShaderBase::INVALID_SHADER_TYPE;
        return;
    }

    //copy string to shader
    glShaderSource(m_shaderId, 1, &pShaderString, NULL);

    //compile shader string
    if(!compile())
    {
        m_state = CSShaderBase::FAIL_COMPILE_FILE;
        return;
    }
}
/**
 * @brief to compile a shader 
 * @return GL_TRUE if the shader was compiled successfully, and GL_FALSE otherWise.
 */
GLboolean
CSShaderBase::compile()
{
    if(!m_shaderId) return GL_FALSE;
    glCompileShader(m_shaderId);
    int success;
    glGetShaderiv(m_shaderId, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        char infoLog[1024];
        glGetShaderInfoLog(m_shaderId, 1024, NULL, infoLog);
        std::cout<<infoLog<<std::endl;
    }
    return success;
}


