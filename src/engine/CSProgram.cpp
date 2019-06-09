#include "CSProgram.h"
/**
 *@brief constructor.
 */
GLProgram::GLProgram()
{
    m_id = glCreateProgram();
}


/**
 *@brief Attach a shader to program
 *@param shaderId Specifies a shader that's to be attached.
 */
void GLProgram::attach(GLuint shaderId)
{
    assert(glIsShader(shaderId));
    glAttachShader(m_id, shaderId);
}

/**
 *@brief Attach a shader to program
 *@param shaderId Specifies a shader that's to be attached.
 */
void GLProgram::detach(GLuint shaderId)
{
    glDetachShader(m_id, shaderId);
}

/**
 *@return true if program is currently flagged for deletion, otherwise false
 */
bool
GLProgram::isDeleted()
{
    GLint params;
    glGetProgramiv(m_id, GL_DELETE_STATUS, &params);
    return params;
}

/**
 *@return true if program is linked successfully, otherwise false
 */
bool
GLProgram::isLinked()
{
    GLint params;
    glGetProgramiv(m_id, GL_LINK_STATUS, &params);
    return params;
}


/**
 *@return true if program is validate successfully, otherwise false
 */
bool
GLProgram::isValidate()
{
    GLint params;
    glGetProgramiv(m_id, GL_VALIDATE_STATUS, &params);
    return params;
}

/**
 *@return the number of the log about program 
 */
GLint
GLProgram::getLogLength()
{
    GLint params;
    glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &params);
    return params;
}

/**
 *@return the number of shaders attached to program 
 */
GLint
GLProgram::getAttachedShadersNumber()
{
    GLint params;
    glGetProgramiv(m_id, GL_ATTACHED_SHADERS, &params);
    return params;
}

/**
 *@return the number of active attribute atomic counter buffers used by program 
 */
GLint
GLProgram::getActiveAtomicCounterBuffers()
{
    GLint params;
    glGetProgramiv(m_id, GL_ACTIVE_ATOMIC_COUNTER_BUFFERS, &params);
    return params;
}

/**
 *@return the length of the longest active attribute name for program​,
 */
GLint
GLProgram::getActiveAttributesMaxLength()
{
    GLint params;
    glGetProgramiv(m_id, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &params);
    return params;
}

/**
 *@return the number of active attribute variables for program​.
 */
GLint
GLProgram::getActiveAttributesNumber()
{
    GLint params;
    glGetProgramiv(m_id, GL_ACTIVE_ATTRIBUTES, &params);
    return params;
}

/**
 *@return the number of active uniform variables for program​.
 */
GLint
GLProgram::getActiveUniformNumber()
{
    GLint params;
    glGetProgramiv(m_id, GL_ACTIVE_UNIFORMS, &params);
    return params;
}

/**
 *@return the length of the longest active uniform variable name for program​
 */
GLint
GLProgram::getActiveUniformMaxLength()
{
    GLint params;
    glGetProgramiv(m_id, GL_ACTIVE_UNIFORM_MAX_LENGTH, &params);
    return params;
}

/**
 *@return  the length of the program binary
 */
GLint
GLProgram::getProgramBinaryLength()
{
    GLint params;
    glGetProgramiv(m_id, GL_PROGRAM_BINARY_LENGTH, &params);
    return params;
}

/**
 *@brief  get the local work group size of the compute program as specified by its input layout qualifier
 *@params [output] an array of three integers.
 *@note gl>=4.3
 */
void
GLProgram::getComputeWorkGroupSize(GLint* params)
{
    glGetProgramiv(m_id, GL_COMPUTE_WORK_GROUP_SIZE, params);
}

/**
 *@return  a symbolic constant indicating the buffer mode used when transform feedback is active. This may be GL_SEPARATE_ATTRIBS or GL_INTERLEAVED_ATTRIBS.
 */
GLint
GLProgram::getTransformFeedbackBufferMode()
{
    GLint params;
    glGetProgramiv(m_id, GL_TRANSFORM_FEEDBACK_BUFFER_MODE, &params);
    return params;
}

/**
 *@return  returns the number of varying variables to capture in transform feedback mode for the program.
 */
GLint
GLProgram::getTransformFeedbackVaryingVariableNumber()
{
    GLint params;
    glGetProgramiv(m_id, GL_TRANSFORM_FEEDBACK_VARYINGS, &params);
    return params;
}

/**
 *@return the length of the longest variable name to be used for transform feedback
 */
GLint
GLProgram::getTransformFeedbackVaryingVariableMaxLength()
{
    GLint params;
    glGetProgramiv(m_id, GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH, &params);
    return params;
}

/**
 *@return returns the maximum number of vertices that the geometry shader in program​ will output
 *@note gl>=3.2
 */
GLint
GLProgram::getGeometryVerticesOutputNumber()
{
    GLint params;
    glGetProgramiv(m_id, GL_GEOMETRY_VERTICES_OUT, &params);
    return params;
}

/**
 *@return a symbolic constant indicating the primitive type accepted as input to the geometry shader contained in program​.
 *@note gl>=3.2
 */
GLint
GLProgram::getGeometryInputNumber()
{
    GLint params;
    glGetProgramiv(m_id, GL_GEOMETRY_INPUT_TYPE, &params);
    return params;
}

/**
 *@return a symbolic constant indicating the primitive type that will be output by the geometry shader contained in program​.
 *@note gl>=3.2
 */
GLint
GLProgram::getGeometryOutputNumber()
{
    GLint params;
    glGetProgramiv(m_id, GL_GEOMETRY_OUTPUT_TYPE, &params);
    return params;
}

/**
 *@briefreturns the information log for the specified program object. The information log for a program object is modified when the program object is linked or validated. The string that is returned will be null terminated. 
 *@param log specifies string that is used to return detail infomation.
 */
void
GLProgram::getLog(std::string &log)
{
    if (!log.empty()) log.clear();
    char msg[1024];
    int len= 0;
    glGetProgramInfoLog(m_id, 1024, &len, msg);
    log = msg;
}

/*
 *@return true if program​ is the name of a program object previously created with glCreateProgram and not yet deleted with glDeleteProgram. If program​ is zero or a non-zero value that is not the name of a program object, or if an error occurs, glIsProgram returns false.
 */
bool
GLProgram::isProgram()
{
    return glIsProgram(m_id);
}

/**
 *@brief get shaders attached to program
 *@param maxCnt the max number of shader to be queried
 *@param count the queried shader number
 *@param shaders an array contains queried shaders id.
 *@note getAttatchedShadersNumber() can get shader number.
 */
void
GLProgram::getAttachedShaders(GLsizei maxCnt, GLsizei &count, GLuint* shaders)
{
    assert(shaders);
    glGetAttachedShaders(m_id, maxCnt, &count, shaders);
}

/**
 *@return true if program is linked successfully, otherwise false.
 *@see glLinkprogram()
 */
bool
GLProgram::link()
{
    glLinkProgram(m_id);
    return isLinked();
}
/**
 *@brief use this program.
 */
void
GLProgram::use()
{
    assert(!isDeleted());
    glUseProgram(m_id);
}

/**
 *@brief set gl program
 */
GLuint
GLProgram::setProgramId(GLuint programId)
{
    GLuint id = m_id;
    m_id = programId;
    return id;
}

/**
 *@brief get gl program
 */
GLuint
GLProgram::getProgramId()
{
    return m_id;
}

/**
 *@brief delete program
 *@note frees the memory and invalidates the name associated with the program object specified by program.​If a program object is in use as part of current rendering state, it will be flagged for deletion, but it will not be deleted until it is no longer part of current state for any rendering context.
 *@details ref glDeleteProgram
 */
void
GLProgram::destroy()
{
    glDeleteProgram(m_id);
}
