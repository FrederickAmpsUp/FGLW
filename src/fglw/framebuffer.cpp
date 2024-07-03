#include <glad/glad.h>
#include <fglw/framebuffer.hpp>
#include <iostream>

namespace fglw {

void RenderTarget::clear(glm::vec3 color) {
    this->bind();
    glClearColor(color.x, color.y, color.z, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

Framebuffer::Framebuffer(fglw::Texture2D& tex) : tex(tex) {
    glGenFramebuffers(1, &this->fboID);

    glBindFramebuffer(GL_FRAMEBUFFER, this->fboID);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex.getTextureID(), 0);

    this->depthTex = fglw::Texture2D(tex.width(), tex.height(), GL_DEPTH_COMPONENT);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, this->depthTex.getTextureID(), 0);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "Framebuffer incomplete" << std::endl;
    }
}

Framebuffer::Framebuffer(unsigned int width, unsigned int height) {
    this->tex = fglw::Texture2D(width, height, GL_RGBA32F);
}

void Framebuffer::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, this->fboID);
}
}