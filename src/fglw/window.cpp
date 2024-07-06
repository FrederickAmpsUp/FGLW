#include <glad/glad.h>
#include <fglw/window.hpp>
#include <fglw/log.hpp>

namespace fglw {

Window::Window(int width, int height, const std::string& title) {
    static bool glad_initialized = false;

    if (!glfwInit()) {
        FGLW_DEBUG_PRINTF("Failed to initialize GLFW.\n");
    }

    win = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(win);

    if (!glad_initialized) {
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            FGLW_DEBUG_PRINTF("Failed to initialize GLAD.\n");
        }
        glad_initialized = true;
    }
}

void Window::loop() {
    glfwMakeContextCurrent(this->win);
    while (!glfwWindowShouldClose(this->win)) {
        this->loop_fn();

        glfwSwapInterval(0);
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }

    glfwDestroyWindow(this->win);
}

void Window::bind() {
    glfwMakeContextCurrent(this->win);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, this->width(), this->height());
}
}