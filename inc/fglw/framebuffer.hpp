#pragma once

#include <glm/glm.hpp>

namespace fglw {

class Framebuffer {
public:
    /**
     * Bind the framebuffer as the graphics library's drawbuffer.
     * This should only be called internally.
     */
    virtual void bind() = 0;

    void clear(glm::vec3 color);
private:

};
}