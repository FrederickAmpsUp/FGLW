#pragma once

#include <glad/glad.h>

namespace fglw {

class Texture2D {
public:
    Texture2D();
    Texture2D(unsigned int width, unsigned int height, GLenum internalFormat=GL_RGBA32F);
    Texture2D(unsigned int width, unsigned int height, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat=GL_RGBA32F);

    GLenum glTextureEnum() const { return GL_TEXTURE0 + this->textureIndex; }
    unsigned int getTextureIndex() const { return this->textureIndex; }

    unsigned int getTextureID() const { return this->textureID; }

    unsigned int width() const { return _width; }
    unsigned int height() const { return _height; }
private:
    GLuint textureID;
    unsigned int textureIndex;
    unsigned int _width, _height;

protected:
    static unsigned int textureCount;
};
}