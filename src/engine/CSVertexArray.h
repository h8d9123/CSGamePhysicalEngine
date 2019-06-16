#include "CSBase.h"
class GLVertexAttrSetter
{
public:
    virtual void set()=0;
};


class GLVertexDataSetter
{
public:
    virtual void set()=0;
};


class GLVertexArrayObject
{
public:
    GLVertexArrayObject();
    GLboolean isVertexArray();
    void destroy();
    void bind();
    void setAttr(GLVertexAttrSetter &setter) {setter.set();}
    void setData(GLVertexDataSetter &setter) {setter.set();}
    
private:
    GLuint m_id;
};


class GLBufferObject
{
public:
    GLBufferObject(GLenum target);
    GLboolean isBuffer();
    void destroy();
    void bind();
    //glBindBufferBase
    //glBindBufferRange
    //glMapBufferRange
    //glUnMapBuffer
private:
    GLuint m_id;
    GLenum m_type;
};


class GLTextureObject
{
public:
    GLTextureObject(GLenum target);
    GLboolean isTexture();
    void bind();
    void destroy();
private:
    GLuint m_id;
    GLenum m_type;
};
