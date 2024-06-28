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
        glClear(GL_DEPTH_BUFFER_BIT);

        this->loop_fn();

        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }

    glfwDestroyWindow(this->win);
}
}