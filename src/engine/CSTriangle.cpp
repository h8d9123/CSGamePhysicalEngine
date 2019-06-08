#include <GL/glew.h>
#include "CSShader.h"

bool createTriangle(GLuint &VAO, GLuint &progId)
{
    GLShader vs(GL_VERTEX_SHADER);
    vs.setSourceFile("triangle.vs");
    if(!vs.compile()) std::cout<<"vs fail"<<std::endl;
    GLShader fs(GL_FRAGMENT_SHADER);
    fs.setSourceFile("triangle.fs");
    if(!fs.compile()) std::cout<<"fs fail"<<std::endl;
    progId = glCreateProgram();
    glAttachShader(progId, vs.getShaderId());
    glAttachShader(progId, fs.getShaderId());
    glLinkProgram(progId);

    // check for linking errors
    GLint success;
    char infoLog[512];
    glGetProgramiv(progId, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(progId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        return false;
    }

    float vertices[] =
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f,
    };
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    return true;
}

