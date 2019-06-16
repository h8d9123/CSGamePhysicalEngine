#include "GLVertexArray.h"

GLVertexArray::GLVertexArray():m_id(0)
{
    glGenVertexArrays(1, &m_id);
}


GLboolean
GLVertexArray::isVertexArray()
{
    return glIsVertexArray(m_id);
}

void
GLVertexArray::destroy()
{
    glDeleteVertexArrays(1, &m_id);
}

void
GLVertexArray::bind()
{
    glBindVertexArray(m_id); 
}

GLBuffer::GLBuffer(GLenum target):m_id(0), m_type(target)
{
    glGenBuffers(1, &m_id);
}

GLboolean
GLBuffer::isBuffer()
{
    return glIsBuffer(m_id); 
}

void destroy()
{
    glDeleteBuffers(1, &m_id);
}

void
GLBuffer::bind()
{
    glBindBuffer(m_type, m_id);
}
