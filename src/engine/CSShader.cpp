/**
 * @file CSShader.cpp
 * @brief
 * @author wanghzh
 * @version 1.0
 * @date Sun Apr 21 20:00:03 PDT 2019
 */

#include "CSShader.h"


/**
 *@brief constructor
 *@param shaderType Specifies the type of shader to be created.
 *@see GLShader::getShaderType()
 *@note  GL_COMPUTE_SHADER is available if gl >= 4.3
 */
GLShader::GLShader(GLenum shaderType)
{
    m_id = glCreateShader(shaderType);
}


/**
 *@brief get shader type.
 *@note GL_VERTEX_SHADER, GL_TESS_CONTROL_SHADER, GL_TESS_EVALUATION_SHADER, GL_GEOMETRY_SHADER, GL_FRAGMENT_SHADER, or GL_COMPUTE_SHADER. 
 */
GLenum
GLShader::getShaderType()
{
    GLint param;
    glGetShaderiv(m_id, GL_SHADER_TYPE, &param);
    return param;
}

/**
 *@brief get status whether the shader is deleted.
 *@return true if the shader is deleted, otherwise false.
 */
bool
GLShader::isDeleted()
{
    GLint param;
    glGetShaderiv(m_id, GL_DELETE_STATUS, &param);
    return (bool)param;
}

/**
 *@brief get status whether the shader is compiled successfully.
 *@return true if the shader is compiled, otherwise false.
 */
bool
GLShader::isCompiled()
{
    GLint param;
    glGetShaderiv(m_id, GL_COMPILE_STATUS, &param);
    return (bool)param;
}

/**
 *@brief get length of the infomation log.
 *@return length of log if it has log, otherwise 0.
 */
GLint
GLShader::getLogLength()
{
    GLint param;
    glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &param);
    return param;
}


/**
 *@brief get length of the shader source code.
 *@return length of source code if it has source, otherwise 0.
 */
GLint
GLShader::getSourceLength()
{
    GLint param;
    glGetShaderiv(m_id, GL_SHADER_SOURCE_LENGTH, &param);
    return param;
}


/**
 *@brief get detail infomation after shader is compiled. 
 *@param log specifies string that is used to return detail infomation.
 */
void
GLShader::getLog(std::string &log)
{
    if (!log.empty()) log.clear();
    char msg[1024];
    int len= 0;
    glGetShaderInfoLog(m_id, 1024, &len, msg);
    log = msg;
}


/**
 *@brief get shader source code. 
 *@param log specifies string that is used to return source code.
 */
void
GLShader::getSource(std::string& src)
{
    if (!src.empty()) src.clear();
    int maxL = getSourceLength();
    char srcStr[maxL];
    int len = 0;
    glGetShaderSource(m_id, maxL, &len, srcStr);
    src = srcStr;
}


/**
 *@brief compiles shader. 
 *@return true if shader is compiled successfully, otherwise false.
 *@note using getLog() to get more information. 
 */
bool
GLShader::compile()
{
    glCompileShader(m_id);
    return isCompiled();
}


/**
 *@brief set shader source code with a file
 *@param pathName specifies shader file
 */
void
GLShader::setSourceFile(const std::string &pathName)
{
    std::string shaderStr;
    std::ifstream hFile;
    hFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        hFile.open(pathName);
        std::stringstream ss;
        ss << hFile.rdbuf();
        hFile.close();
        shaderStr = ss.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout<<"Fail to read shader file!"<<std::endl;
        return;
    }
    const GLchar* p = shaderStr.c_str();
    glShaderSource(m_id, 1, &p, NULL);
}

/**
 *@brief set shader source code
 *@param src specifies source code
 */
void
GLShader::setSource(const std::string &src)
{

    const GLchar* p = src.c_str();
    glShaderSource(m_id, 1, &p, NULL);
}

/**
 *@return get shader object id
 */
GLuint
GLShader::getShaderId()
{
    return m_id;
}


/**
 *@brief set shader object id
 *@pragma shaderId a shader object id
 *@return the old shader object id.
 */
GLuint
GLShader::setShaderId(GLuint shaderId)
{
    GLuint id = m_id;
    m_id = shaderId;
    return id;
}
/*
 * @return ref. glIsShader() 
 */
bool
GLShader::isShader()
{
    return glIsShader(m_id);
}

/*
* @brief frees the memory and invalidates the name associated with the shader objec
* @note If a shader object to be deleted is attached to a program object, it will be flagged for deletion, but it will not be deleted until it is no longer attached to any program object.
*@details ref. glDeleteShader()
*/
void
GLShader::destroy()
{
    glDeleteShader(m_id);
}
