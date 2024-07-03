#pragma once

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <fglw/log.hpp>
#include <fglw/texture.hpp>

namespace fglw {

class ShaderProgram {
public:
    static ShaderProgram compileGLSL(const std::string& vertSource, const std::string& fragSource);

    static ShaderProgram loadGLSLFiles(const std::string& vertFilename, const std::string& fragFilename);

    /**
     * Bind the shader for use.
     * This should only be called internally.
     */
    void bind();

    void uniform(GLint location, int value);
    void uniform(GLint location, glm::ivec2 value);
    void uniform(GLint location, glm::ivec3 value);
    void uniform(GLint location, glm::ivec4 value);

    void uniform(GLint location, float value);
    void uniform(GLint location, glm::vec2 value);
    void uniform(GLint location, glm::vec3 value);
    void uniform(GLint location, glm::vec4 value);
    void uniform(GLint location, glm::mat2 value);
    void uniform(GLint location, glm::mat3 value);
    void uniform(GLint location, glm::mat4 value);

    void uniform(GLint location, fglw::Texture& value);

    template<typename T>
    void uniform(const std::string& name, T value) {
        this->bind();
        GLint location = glGetUniformLocation(this->programID, name.c_str());
        if(location != -1) {
            this->uniform(location, value);
        } else {
            FGLW_DEBUG_PRINTF("Uniform %s not found\n", name.c_str());
        }
    }
private:
    GLuint programID;
};
}