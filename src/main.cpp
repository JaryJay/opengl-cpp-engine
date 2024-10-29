#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "QuadMesh.h"
#include "Renderer.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Window.h"

#include <glm/gtc/matrix_transform.hpp>

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
    const QuadMesh quadMesh{};
    const Renderer renderer(shaderProgram, quadMesh, window);
    const Texture2D texture("assets/math 239 a-5-4 b.jpg");

    // Render loop
    while (!window.shouldClose())
    {
        // Input
        processInput(window);

        // Rendering commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.drawTexture(texture, glm::vec2{400, 300}, glm::vec2{100, 100});

        // Check and call events and swap buffers
        window.swapBuffers();
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
