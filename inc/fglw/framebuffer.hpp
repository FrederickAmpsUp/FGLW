#pragma once

#include <glm/glm.hpp>
#include <fglw/texture.hpp>

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

class Framebuffer : public RenderTarget, public fglw::Texture2D {
public:
    Framebuffer() : Framebuffer(1,1) {}
    Framebuffer(fglw::Texture2D& tex);
    Framebuffer(unsigned int width, unsigned int height);

    virtual void bind() override;
private:
    GLuint fboID;
    fglw::Texture2D tex;
    fglw::Texture2D depthTex;
};
}