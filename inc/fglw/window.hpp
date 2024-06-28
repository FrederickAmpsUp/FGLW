#pragma once

#define GLFW_INCLUDE_OPENGL
#include <GLFW/glfw3.h>

#include <string>

namespace fglw {

class Window {
public:
    Window(int width, int height, const std::string& title);
private:
    GLFWwindow *win;
};
}