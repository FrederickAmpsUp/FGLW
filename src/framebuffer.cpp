#include <glad/glad.h>
#include <fglw/framebuffer.hpp>

namespace fglw {

void Framebuffer::clear(glm::vec3 color) {
    this->bind();
    glClearColor(color.x, color.y, color.z, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
}