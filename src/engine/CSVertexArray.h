
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
    GLVertexArray();
    GLboolean isVertexArray();
    void destroy();
    void bind();
    void setAttr(const GLVertexAttrSetter &setter) {setter.set();}
    void setData(const GLVertexDataSetter &setter) {setter.set();}
    
private:
    GLuint m_id;
};


class GLBufferObject
{
public:
    GLBuffer(GLenum target);
    GLboolean isBuffer();
    destroy();
    void bind();
    //glBindBufferBase
    //glBindBufferRange
    //glMapBufferRange
    //glUnMapBuffer
private:
    GLuint m_id;
    GLenum m_type;
};

