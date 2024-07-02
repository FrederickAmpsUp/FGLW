#pragma once

#include <glad/glad.h>

namespace fglw {

class Texture {
public:
    Texture(unsigned int width, unsigned int height);
private:
    GLuint textureID;
};
}