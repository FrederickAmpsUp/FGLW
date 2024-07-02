#pragma once

#include <glad/glad.h>

namespace fglw {

class Texture {
public:
    Texture();
    Texture(unsigned int width, unsigned int height, GLenum internalFormat=GL_RGBA32F);
    Texture(unsigned int width, unsigned int height, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat=GL_RGBA32F);

    unsigned int glTextureEnum() const { return GL_TEXTURE0 + this->textureIndex; }
    unsigned int getTextureIndex() const { return this->textureIndex; }
private:
    GLuint textureID;
    unsigned int textureIndex;

protected:
    static unsigned int textureCount;
};
}