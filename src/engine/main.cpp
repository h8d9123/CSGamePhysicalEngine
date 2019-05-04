// g++ main.cpp `pkg-config --cflags --libs glew` `pkg-config --libs glew` `pkg-config --cflags glfw3` `pkg-config --static --libs glfw3` -lGL -lGLEW
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define CS_NS_START namespace cs { 
#define CS_NS_END }
void glfwErroCb(int error, const char*desc)
{
    std::cerr<<"GLFW error:"<<error<<"--"<<desc<<std::endl;
}

CS_NS_START

const unsigned int window_width = 800;
const unsigned int window_height = 600;
const char window_title[] = "CS Demo\0";


void error(const std::string msg)
{
    std::cerr<<msg<<std::endl;
}

//callback when wnd size changed
void framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
    glViewport(0, 0, w, h);
}


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window , true);
}


void clearWindow()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

CS_NS_END



int main(int argc, char* argv[])
{
    glfwSetErrorCallback(glfwErroCb);
    if (!glfwInit()) {cs::error("glfwInit fail!"); return -1;}
    //create a window
    GLFWwindow *window = glfwCreateWindow(cs::window_width, 
                                          cs::window_height,
                                          cs::window_title,
                                          NULL, NULL);//monitor , share
    if (!window) 
    {
        cs::error("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    //set context
    glfwMakeContextCurrent(window);
    //init glew
    glewExperimental = GL_TRUE;
    if (glewInit())
    {
        glfwTerminate();
        cs::error("Failed to init GLEW!");
        return -1;
    }
    //set viewport
    //gl cordinate is (-1, -1)( 1, 1), 
    //screen is (0,0)(w, h)
    glViewport(0,0,cs::window_width, cs::window_height);
    glfwSetFramebufferSizeCallback(window, cs::framebuffer_size_callback);
    cs::clearWindow();
    while(!glfwWindowShouldClose(window))
    {
        cs::processInput(window);
        glfwSwapBuffers(window);
        //process event
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

