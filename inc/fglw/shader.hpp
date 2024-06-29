#pragma once

#include <glad/glad.h>
#include <string>

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
private:
    GLuint programID;
};
}