#include <fglw/texture.hpp>

namespace fglw {

Texture::Texture() : Texture(1, 1) {}
Texture::Texture(unsigned int width, unsigned int height, GLenum internalFormat) {
    this->textureIndex = Texture::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_2D, this->textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::Texture(unsigned int width, unsigned int height, GLenum dataFormat, GLenum dataType, const void *data, GLenum internalFormat) {
    this->textureIndex = Texture::textureCount++;
    glActiveTexture(GL_TEXTURE0 + this->textureIndex);

    glGenTextures(1, &this->textureID);
    glBindTexture(GL_TEXTURE_2D, this->textureID);


    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, dataType, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}

unsigned int Texture::textureCount = 0;
}