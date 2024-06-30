#pragma once

#define GLFW_INCLUDE_OPENGL
#include <GLFW/glfw3.h>

#include <string>
#include <functional>

#include <fglw/framebuffer.hpp>

namespace fglw {

class Window : public Framebuffer {
public:
    using LoopCallback = std::function<void()>;

    Window(int width, int height, const std::string& title);

    void on_loop(LoopCallback fn) { loop_fn = fn; }

    void loop();

    float run_time() const { glfwMakeContextCurrent(this->win); return glfwGetTime(); }

    virtual void bind() override;
private:
    GLFWwindow *win;
    LoopCallback loop_fn;
};
}