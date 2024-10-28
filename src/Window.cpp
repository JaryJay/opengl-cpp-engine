#include "Window.h"
#include <iostream>

void setFramebufferSizeCallback(GLFWwindow* window, const int width, const int height)
{
    glViewport(0, 0, width, height);
}

Window::Window(const int width, const int height, const char* title, const bool resizable, const WindowMode mode):
    _width(width), _height(height), _current_mode(mode)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    if (mode == FULLSCREEN)
    {
        _window = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), nullptr);
    }
    else
    {
        _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    }
    if (_window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    if (resizable)
        glfwSetFramebufferSizeCallback(_window, setFramebufferSizeCallback);
}

void Window::makeCurrent() const
{
    glfwMakeContextCurrent(_window);
}

void Window::getSize(int* width, int* height) const
{
    glfwGetWindowSize(_window, width, height);
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(_window);
}

void Window::setShouldClose(const bool close) const
{
    glfwSetWindowShouldClose(_window, close);
}

void Window::changeWindowMode(const WindowMode new_window_mode)
{
    if (_current_mode == new_window_mode) return;


    std::cout << "changeWindowMode not yet implemented. Sorry!" << std::endl;
    return;

    // switch (new_window_mode)
    // {
    // case WINDOWED:
    //     break;
    // case FULLSCREEN:
    //     break;
    // case WINDOWED_FULLSCREEN:
    //     break;
    // }

    _current_mode = new_window_mode;
}

/**
 * @param key the key to check
 * @return Returns either GLFW_PRESS or GLFW_RELEASE
 */
int Window::getKey(const int key) const
{
    return glfwGetKey(_window, key);
}

void Window::swapBuffers() const
{
    glfwSwapBuffers(_window);
}

