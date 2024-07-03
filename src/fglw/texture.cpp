#include <fglw/texture.hpp>
#include <fglw/log.hpp>
#include <GL/glu.h>

namespace fglw {

Texture2D::Texture2D() : Texture2D(1, 1) {}
Texture2D::Texture2D(unsigned int width, unsigned int height, GLenum internalFormat) {
    this->textureIndex = Texture2D::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_2D, this->textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    GLenum dataFormat;
    GLenum dataType;

    switch (internalFormat) {
        case GL_DEPTH_COMPONENT:
            dataFormat = GL_DEPTH_COMPONENT;
            dataType = GL_FLOAT;
            break;
        case GL_DEPTH_STENCIL:
            dataFormat = GL_DEPTH_STENCIL;
            dataType = GL_UNSIGNED_INT_24_8;
            break;
        case GL_RED:
            dataFormat = GL_RED;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RG:
            dataFormat = GL_RG;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RGB:
            dataFormat = GL_RGB;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RGBA:
            dataFormat = GL_RGBA;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_R8:
            dataFormat = GL_RED;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_R8_SNORM:
            dataFormat = GL_RED;
            dataType = GL_BYTE;
            break;
        case GL_R16:
            dataFormat = GL_RED;
            dataType = GL_UNSIGNED_SHORT;
            break;
        case GL_R16_SNORM:
            dataFormat = GL_RED;
            dataType = GL_SHORT;
            break;
        case GL_RG8:
            dataFormat = GL_RG;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RG8_SNORM:
            dataFormat = GL_RG;
            dataType = GL_BYTE;
            break;
        case GL_RG16:
            dataFormat = GL_RG;
            dataType = GL_UNSIGNED_SHORT;
            break;
        case GL_RG16_SNORM:
            dataFormat = GL_RG;
            dataType = GL_SHORT;
            break;
        case GL_RGB8:
            dataFormat = GL_RGB;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RGB8_SNORM:
            dataFormat = GL_RGB;
            dataType = GL_BYTE;
            break;
        case GL_RGB16_SNORM:
            dataFormat = GL_RGB;
            dataType = GL_SHORT;
            break;
        case GL_RGBA8:
            dataFormat = GL_RGBA;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RGBA8_SNORM:
            dataFormat = GL_RGBA;
            dataType = GL_BYTE;
            break;
        case GL_RGBA16:
            dataFormat = GL_RGBA;
            dataType = GL_UNSIGNED_SHORT;
            break;
        case GL_RGBA16_SNORM:
            dataFormat = GL_RGBA;
            dataType = GL_SHORT;
            break;
        case GL_SRGB8:
            dataFormat = GL_RGB;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_SRGB8_ALPHA8:
            dataFormat = GL_RGBA;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_R16F:
            dataFormat = GL_RED;
            dataType = GL_HALF_FLOAT;
            break;
        case GL_RG16F:
            dataFormat = GL_RG;
            dataType = GL_HALF_FLOAT;
            break;
        case GL_RGB16F:
            dataFormat = GL_RGB;
            dataType = GL_HALF_FLOAT;
            break;
        case GL_RGBA16F:
            dataFormat = GL_RGBA;
            dataType = GL_HALF_FLOAT;
            break;
        case GL_R32F:
            dataFormat = GL_RED;
            dataType = GL_FLOAT;
            break;
        case GL_RG32F:
            dataFormat = GL_RG;
            dataType = GL_FLOAT;
            break;
        case GL_RGB32F:
            dataFormat = GL_RGB;
            dataType = GL_FLOAT;
            break;
        case GL_RGBA32F:
            dataFormat = GL_RGBA;
            dataType = GL_FLOAT;
            break;
        case GL_R11F_G11F_B10F:
            dataFormat = GL_RGB;
            dataType = GL_UNSIGNED_INT_10F_11F_11F_REV;
            break;
        case GL_RGB9_E5:
            dataFormat = GL_RGB;
            dataType = GL_UNSIGNED_INT_5_9_9_9_REV;
            break;
        case GL_R8I:
            dataFormat = GL_RED_INTEGER;
            dataType = GL_BYTE;
            break;
        case GL_R8UI:
            dataFormat = GL_RED_INTEGER;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_R16I:
            dataFormat = GL_RED_INTEGER;
            dataType = GL_SHORT;
            break;
        case GL_R16UI:
            dataFormat = GL_RED_INTEGER;
            dataType = GL_UNSIGNED_SHORT;
            break;
        case GL_R32I:
            dataFormat = GL_RED_INTEGER;
            dataType = GL_INT;
            break;
        case GL_R32UI:
            dataFormat = GL_RED_INTEGER;
            dataType = GL_UNSIGNED_INT;
            break;
        case GL_RG8I:
            dataFormat = GL_RG_INTEGER;
            dataType = GL_BYTE;
            break;
        case GL_RG8UI:
            dataFormat = GL_RG_INTEGER;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RG16I:
            dataFormat = GL_RG_INTEGER;
            dataType = GL_SHORT;
            break;
        case GL_RG16UI:
            dataFormat = GL_RG_INTEGER;
            dataType = GL_UNSIGNED_SHORT;
            break;
        case GL_RG32I:
            dataFormat = GL_RG_INTEGER;
            dataType = GL_INT;
            break;
        case GL_RG32UI:
            dataFormat = GL_RG_INTEGER;
            dataType = GL_UNSIGNED_INT;
            break;
        case GL_RGB8I:
            dataFormat = GL_RGB_INTEGER;
            dataType = GL_BYTE;
            break;
        case GL_RGB8UI:
            dataFormat = GL_RGB_INTEGER;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RGB16I:
            dataFormat = GL_RGB_INTEGER;
            dataType = GL_SHORT;
            break;
        case GL_RGB16UI:
            dataFormat = GL_RGB_INTEGER;
            dataType = GL_UNSIGNED_SHORT;
            break;
        case GL_RGB32I:
            dataFormat = GL_RGB_INTEGER;
            dataType = GL_INT;
            break;
        case GL_RGB32UI:
            dataFormat = GL_RGB_INTEGER;
            dataType = GL_UNSIGNED_INT;
            break;
        case GL_RGBA8I:
            dataFormat = GL_RGBA_INTEGER;
            dataType = GL_BYTE;
            break;
        case GL_RGBA8UI:
            dataFormat = GL_RGBA_INTEGER;
            dataType = GL_UNSIGNED_BYTE;
            break;
        case GL_RGBA16I:
            dataFormat = GL_RGBA_INTEGER;
            dataType = GL_SHORT;
            break;
        case GL_RGBA16UI:
            dataFormat = GL_RGBA_INTEGER;
            dataType = GL_UNSIGNED_SHORT;
            break;
        case GL_RGBA32I:
            dataFormat = GL_RGBA_INTEGER;
            dataType = GL_INT;
            break;
        case GL_RGBA32UI:
            dataFormat = GL_RGBA_INTEGER;
            dataType = GL_UNSIGNED_INT;
            break;
        default:
            dataFormat = GL_RGBA;
            dataType = GL_UNSIGNED_BYTE;
            FGLW_DEBUG_PRINTF("Unsupported internal format. Defaulting to GL_RGBA and GL_UNSIGNED_BYTE.\n");
            break;
    }


    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, dataType, nullptr);
    glGenerateMipmap(GL_TEXTURE_2D);

    this->_width = width;
    this->_height = height;

    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        FGLW_DEBUG_PRINTF("GL error: %s\n", gluErrorString(err));
    }
}

Texture2D::Texture2D(unsigned int width, unsigned int height, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat) {
    this->textureIndex = Texture2D::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_2D, this->textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, dataType, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    this->_width = width;
    this->_height = height;
}

unsigned int Texture2D::textureCount = 0;
}