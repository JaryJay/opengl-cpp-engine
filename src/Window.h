#pragma once
#include <GLFW/glfw3.h>

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
    void getSize(int* width, int* height) const;
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



