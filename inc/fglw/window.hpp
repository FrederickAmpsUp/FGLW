#pragma once

#define GLFW_INCLUDE_OPENGL
#include <GLFW/glfw3.h>

#include <string>
#include <functional>

namespace fglw {

class Window {
public:
    using LoopCallback = std::function<void()>;

    Window(int width, int height, const std::string& title);

    void on_loop(LoopCallback fn) { loop_fn = fn; }

    void loop();
private:
    GLFWwindow *win;
    LoopCallback loop_fn;
};
}