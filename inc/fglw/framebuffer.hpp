#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <fglw/rendertarget.hpp>
#include <fglw/texture.hpp>

namespace fglw {

class Framebuffer : public RenderTarget, public fglw::Texture2D {
public:
    Framebuffer() : Framebuffer(1,1) {}
    Framebuffer(unsigned int width, unsigned int height);

    virtual void bind() override;
private:
    GLuint fboID;
    fglw::Texture2D depthTex;
};
}