#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "MyClass.h"

int main(void) {
    MyClass a(8);
    std::cout << a.get() << std::endl;
    std::cout << "Hello World!" << std::endl;

    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Error: glew init" << std::endl;
        return -1;
    }
    glClearColor(1.0,1.0,1.0,1.0);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();    
    return 0;
}