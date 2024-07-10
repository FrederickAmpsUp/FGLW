#include <fglw/texture.hpp>
#include <fglw/log.hpp>
#include <GL/glu.h>
#include <tuple>

namespace fglw {

static std::tuple<GLenum, GLenum> getDataFormat(GLenum internalFormat) {
    GLenum dataFormat, dataType;
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
    return { dataFormat, dataType };
} 


Texture1D::Texture1D() : Texture1D(1) {}
Texture1D::Texture1D(unsigned int sz, GLenum internalFormat) {
    this->textureIndex = Texture::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_1D, this->textureID);

    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    const auto [dataFormat, dataType] = getDataFormat(internalFormat);
    
    glTexImage1D(GL_TEXTURE_1D, 0, internalFormat, sz, 0, dataFormat, dataType, nullptr);

    this->_sz = sz;

    this->dataFmt = dataFormat;
    this->dataType = dataType;
    this->internalFmt = internalFormat;
}

Texture1D::Texture1D(unsigned int sz, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat) {
    this->textureIndex = Texture::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_1D, this->textureID);

    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage1D(GL_TEXTURE_1D, 0, internalFormat, sz, 0, dataFormat, dataType, data);

    this->_sz = sz;

    this->dataFmt = dataFormat;
    this->dataType = dataType;
    this->internalFmt = internalFormat;
}

void Texture1D::upload(const void *data) {
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glTexImage1D(GL_TEXTURE_1D, 0, this->internalFmt, this->_sz, 0, this->dataFmt, this->dataType, data);
}

Texture2D::Texture2D() : Texture2D(1, 1) {}
Texture2D::Texture2D(unsigned int width, unsigned int height, GLenum internalFormat) {
    this->textureIndex = Texture::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_2D, this->textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    const auto [dataFormat, dataType] = getDataFormat(internalFormat);

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, dataType, nullptr);
    glGenerateMipmap(GL_TEXTURE_2D);

    this->_width = width;
    this->_height = height;

    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        FGLW_DEBUG_PRINTF("GL error: %s\n", gluErrorString(err));
    }

    this->dataFmt = dataFormat;
    this->dataType = dataType;
    this->internalFmt = internalFormat;
}

Texture2D::Texture2D(unsigned int width, unsigned int height, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat) {
    this->textureIndex = Texture::textureCount++;
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

    this->dataFmt = dataFormat;
    this->dataType = dataType;
    this->internalFmt = internalFormat;
}

void Texture2D::upload(const void *data) {
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glTexImage2D(GL_TEXTURE_2D, 0, this->internalFmt, this->_width, this->_height, 0, this->dataFmt, this->dataType, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}

Texture3D::Texture3D() : Texture3D(1,1,1) {}
Texture3D::Texture3D(unsigned int dX, unsigned int dY, unsigned int dZ, GLenum internalFormat) {
    this->textureIndex = Texture::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_3D, this->textureID);

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    const auto [dataFormat, dataType] = getDataFormat(internalFormat);

    glTexImage3D(GL_TEXTURE_3D, 0, internalFormat, dX, dY, dZ, 0, dataFormat, dataType, nullptr);

    this->_dx = dX;
    this->_dy = dY;
    this->_dz = dZ;

    this->dataFmt = dataFormat;
    this->dataType = dataType;
    this->internalFmt = internalFormat;
}

Texture3D::Texture3D(unsigned int dX, unsigned int dY, unsigned int dZ, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat) {
    this->textureIndex = Texture::textureCount++;

    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_3D, this->textureID);

    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    
    glTexImage3D(GL_TEXTURE_3D, 0, internalFormat, dX, dY, dZ, 0, dataFormat, dataType, data);
    
    this->_dx = dX;
    this->_dy = dY;
    this->_dz = dZ;

    this->dataFmt = dataFormat;
    this->dataType = dataType;
    this->internalFmt = internalFormat;
}

void Texture3D::upload(const void *data) {
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);
    glBindTexture(GL_TEXTURE_3D, this->textureID);

    glTexSubImage3D(GL_TEXTURE_3D, 0, 0, 0, 0, this->_dx, this->_dy, this->_dz, this->dataFmt, this->dataType, data);
}

unsigned int Texture::textureCount = 0;
}