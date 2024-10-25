#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "window.h"

const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(const Window* window)
{
    if (window->getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
        window->setShouldClose(true);
}

int main()
{
    glfwInit();

    Window window{};
    if (!window.create(800, 600, "My Window", true, false))
        return -1;

    window.makeCurrent();

    // initialize GLAD before we call any OpenGL function
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    // Render loop
    while (!window.shouldClose())
    {
        // Input
        processInput(&window);

        // Rendering commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Check and call events and swap buffers
        window.swapBuffers();
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
