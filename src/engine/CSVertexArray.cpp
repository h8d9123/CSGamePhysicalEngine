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
