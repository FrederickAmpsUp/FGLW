#include <glad/glad.h>
#include <fglw/framebuffer.hpp>
#include <iostream>

namespace fglw {

void RenderTarget::clear(glm::vec3 color) {
    this->bind();
    glClearColor(color.x, color.y, color.z, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

Framebuffer::Framebuffer(unsigned int width, unsigned int height) : Texture2D(width, height, GL_RGBA32F) {
    glGenFramebuffers(1, &this->fboID);

    glBindFramebuffer(GL_FRAMEBUFFER, this->fboID);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->getTextureID(), 0);

    this->depthTex = fglw::Texture2D(this->width(), this->height(), GL_DEPTH_COMPONENT);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, this->depthTex.getTextureID(), 0);

    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        // Handle the error based on the status code
        switch (status) {
            case GL_FRAMEBUFFER_UNDEFINED:
                std::cout << "Framebuffer undefined." << std::endl;
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
                std::cout << "Framebuffer incomplete attachment." << std::endl;
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
                std::cout << "Framebuffer incomplete missing attachment." << std::endl;
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
                std::cout << "Framebuffer incomplete draw buffer." << std::endl;
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
                std::cout << "Framebuffer incomplete read buffer." << std::endl;
                break;
            case GL_FRAMEBUFFER_UNSUPPORTED:
                std::cout << "Framebuffer unsupported." << std::endl;
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
                std::cout << "Framebuffer incomplete multisample." << std::endl;
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
                std::cout << "Framebuffer incomplete layer targets." << std::endl;
                break;
            default:
                std::cout << "Unknown framebuffer error." << std::endl;
                break;
        }
    }
}

void Framebuffer::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, this->fboID);
    glViewport(0,0, this->width(), this->height());
}
}