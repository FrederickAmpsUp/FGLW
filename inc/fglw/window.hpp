#pragma once

#include <GLFW/glfw3.h>

#include <string>
#include <functional>

#include <fglw/rendertarget.hpp>

namespace fglw {

class Window : public RenderTarget {
public:
    using LoopCallback = std::function<void()>;

    Window(int width, int height, const std::string& title);

    void on_loop(LoopCallback fn) { loop_fn = fn; }

    void loop();

    float run_time() const { glfwMakeContextCurrent(this->win); return glfwGetTime(); }

    virtual void bind() override;

    unsigned int width() const {
        int w, h;
        glfwGetWindowSize(this->win, &w, &h);
        return w;
    }

    unsigned int height() const {
        int w, h;
        glfwGetWindowSize(this->win, &w, &h);
        return h;
    }
private:
    GLFWwindow *win;
    LoopCallback loop_fn;
};
}