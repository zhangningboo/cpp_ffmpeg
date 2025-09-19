#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

extern "C" {
    #include "libavcodec/avcodec.h"
}

// export XDG_RUNTIME_DIR=`pwd`
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);//for Mac

    std::cout << avcodec_configuration() << std::endl;

    return 0;
}
