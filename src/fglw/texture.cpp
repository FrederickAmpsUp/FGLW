#include <fglw/texture.hpp>

namespace fglw {

Texture2D::Texture2D() : Texture2D(1, 1) {}
Texture2D::Texture2D(unsigned int width, unsigned int height, GLenum internalFormat) {
    this->textureIndex = Texture2D::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_2D, this->textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glGenerateMipmap(GL_TEXTURE_2D);

    this->_width = width;
    this->_height = height;
}

Texture2D::Texture2D(unsigned int width, unsigned int height, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat) {
    this->textureIndex = Texture2D::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_2D, this->textureID);


    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, dataType, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    this->_width = width;
    this->_height = height;
}

unsigned int Texture2D::textureCount = 0;
}