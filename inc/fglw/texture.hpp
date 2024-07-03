#pragma once

#include <glad/glad.h>

namespace fglw {

class Texture {
public:
    GLenum glTextureEnum() const { return GL_TEXTURE0 + this->textureIndex; }
    unsigned int getTextureIndex() const { return this->textureIndex; }

    unsigned int getTextureID() const { return this->textureID; }
protected:
    GLuint textureID;
    unsigned int textureIndex;
    static unsigned int textureCount;
};

class Texture2D : public Texture {
public:
    Texture2D();
    Texture2D(unsigned int width, unsigned int height, GLenum internalFormat=GL_RGBA32F);
    Texture2D(unsigned int width, unsigned int height, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat=GL_RGBA32F);

    unsigned int width() const { return _width; }
    unsigned int height() const { return _height; }
private:
    unsigned int _width, _height;

protected:
    static unsigned int textureCount;
};

class Texture3D : public Texture {
public:
    Texture3D();
    Texture3D(unsigned int dX, unsigned int dY, unsigned int dZ, GLenum internalFormat=GL_RGBA32F);
    Texture3D(unsigned int dX, unsigned int dY, unsigned int dZ, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat=GL_RGBA32F);


    unsigned int dimX() const { return _dx; }
    unsigned int dimY() const { return _dy; }
    unsigned int dimZ() const { return _dz; }
private:
    unsigned int _dx, _dy, _dz;

protected:
};
}