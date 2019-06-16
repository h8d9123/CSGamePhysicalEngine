#include "CSVertexArray.h"

GLVertexArrayObject::GLVertexArrayObject():m_id(0)
{
    glGenVertexArrays(1, &m_id);
}


GLboolean
GLVertexArrayObject::isVertexArray()
{
    return glIsVertexArray(m_id);
}

void
GLVertexArrayObject::destroy()
{
    glDeleteVertexArrays(1, &m_id);
}

void
GLVertexArrayObject::bind()
{
    glBindVertexArray(m_id); 
}

GLBufferObject::GLBufferObject(GLenum target):m_id(0), m_type(target)
{
    glGenBuffers(1, &m_id);
}

GLboolean
GLBufferObject::isBuffer()
{
    return glIsBuffer(m_id); 
}

void
GLBufferObject::destroy()
{
    glDeleteBuffers(1, &m_id);
}

void
GLBufferObject::bind()
{
    glBindBuffer(m_type, m_id);
}

GLTextureObject::GLTextureObject(GLenum target)
    :m_id(0), m_type(target)
{
    glGenTextures(1, &m_id);
}

GLboolean
GLTextureObject::isTexture()
{
    return glIsTexture(m_id);
}

void
GLTextureObject::bind()
{
    glBindTexture(m_type, m_id); 
}

void
GLTextureObject::destroy()
{
    glDeleteTextures(1, &m_id);
}
