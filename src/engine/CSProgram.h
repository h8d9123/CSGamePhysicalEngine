#pragma once 
/**
 * @file CSProgram.h
 * @brief
 * @author wanghzh
 * @version 1.0
 * @date 2019-6-9 
 */


/**
 *@class GLProgram
 *@brief wraps glprogram function
 *@author wanghzh
 *@version 1.0
 *@date 2019-06-09
 */

#include <GL/glew.h>
#include<iostream>
#include <string>
#include <cassert>

class GLProgram
{
public:
    GLProgram();
    void attach(GLuint shaderId);
    void detach(GLuint shaderId);
    void getAttachedShaders(GLsizei maxCnt, GLsizei &count, GLuint* shaders);
    bool isDeleted();
    bool isLinked();
    bool isValidate();
    GLint getLogLength();
    GLint getAttachedShadersNumber();
    GLint getActiveAtomicCounterBuffers();
    GLint getActiveAttributesNumber();
    GLint getActiveAttributesMaxLength();
    GLint getActiveUniformNumber();
    GLint getActiveUniformMaxLength();
    GLint getProgramBinaryLength();
    void getComputeWorkGroupSize(GLint* param);
    GLint getTransformFeedbackBufferMode();
    GLint getTransformFeedbackVaryingVariableNumber();
    GLint getTransformFeedbackVaryingVariableMaxLength();
    GLint getGeometryVerticesOutputNumber();
    GLint getGeometryInputNumber();
    GLint getGeometryOutputNumber();
    void getLog(std::string &log);
    bool isProgram();
    bool link();
    void use();
    GLuint setProgramId(GLuint programId);
    GLuint getProgramId();
    //glGetActiveAttrib
    //glGetProgramInterfaceiv
    //glGetProgramResourceiv
  
private:
    GLuint m_id;
};

