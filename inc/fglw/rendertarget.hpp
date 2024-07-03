#pragma once

#include <glm/glm.hpp>

namespace fglw {

class RenderTarget {
public:
    /**
     * Bind the target as the graphics library's drawbuffer.
     * This should only be called internally.
     */
    virtual void bind() = 0;

    void clear(glm::vec3 color);
private:

};
}