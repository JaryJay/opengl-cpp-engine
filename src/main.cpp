#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "QuadMesh.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Window.h"

void processInput(const Window& window)
{
    if (window.getKey(GLFW_KEY_ESCAPE) == GLFW_PRESS)
        window.setShouldClose(true);
}

int main()
{
    glfwInit();

    const Window window(800, 600, "My Window");

    window.makeCurrent();

    // initialize GLAD before we call any OpenGL function
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    // Create texture shader
    const ShaderProgram shaderProgram("shaders/textureVertexShader.glsl", "shaders/textureFragmentShader.glsl");
    const Texture2D texture("assets/math 239 a-5-4 b.jpg");
    const QuadMesh quadMesh{};

    // Render loop
    while (!window.shouldClose())
    {
        // Input
        processInput(window);

        // Rendering commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        quadMesh.bind();
        shaderProgram.use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        shaderProgram.setTexture("texture1", texture.id, 0);

        // Check and call events and swap buffers
        window.swapBuffers();
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
