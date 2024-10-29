#pragma once
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

enum WindowMode
{
    WINDOWED,
    FULLSCREEN,
    WINDOWED_FULLSCREEN,
};

class Window
{
public:
    Window(int width,
           int height,
           const char* title,
           bool resizable = true,
           WindowMode mode = WINDOWED);
    void makeCurrent() const;
    [[nodiscard]] glm::ivec2 getSize() const;
    [[nodiscard]] bool shouldClose() const;
    void setShouldClose(bool close) const;
    void changeWindowMode(WindowMode new_window_mode);
    [[nodiscard]] int getKey(int key) const;
    void swapBuffers() const;

    ~Window() = default;

private:
    GLFWwindow* _window;
    int _width;
    int _height;
    WindowMode _current_mode;
};



