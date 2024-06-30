#include <fglw/shader.hpp>
#include <fstream>
#include <sstream>
#include <string>
#include <fglw/log.hpp>
#include <vector>

namespace fglw {

ShaderProgram ShaderProgram::compileGLSL(const std::string& vertSrc, const std::string& fragSrc) {
    ShaderProgram out;

    GLuint vert = glCreateShader(GL_VERTEX_SHADER);
    GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);

    const char *vs = vertSrc.c_str();
    const char *fs = fragSrc.c_str();

    glShaderSource(vert, 1, &vs, nullptr);
    glShaderSource(frag, 1, &fs, nullptr);

    glCompileShader(vert);

    int success;
    glGetShaderiv(vert, GL_COMPILE_STATUS, &success);

    if (!success) {
        GLint logLength;
        glGetShaderiv(vert, GL_INFO_LOG_LENGTH, &logLength);

        std::vector<char> log(logLength);
        glGetShaderInfoLog(vert, logLength, nullptr, log.data());

        FGLW_DEBUG_PRINTF("Vertex shader compilation failed:\n\n%s", log.data());
    }

    glCompileShader(frag);
    glGetShaderiv(frag, GL_COMPILE_STATUS, &success);

    if (!success) {
        GLint logLength;
        glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &logLength);

        std::vector<char> log(logLength);
        glGetShaderInfoLog(frag, logLength, nullptr, log.data());

        FGLW_DEBUG_PRINTF("Fragment shader compilation failed:\n\n%s", log.data());
    }

    out.programID = glCreateProgram();
    glAttachShader(out.programID, vert);
    glAttachShader(out.programID, frag);

    glLinkProgram(out.programID);

    glGetProgramiv(out.programID, GL_LINK_STATUS, &success);

    if (!success) {
        GLint logLength;
        glGetProgramiv(out.programID, GL_INFO_LOG_LENGTH, &logLength);

        std::vector<char> log(logLength);
        glGetProgramInfoLog(out.programID, logLength, nullptr, log.data());

        FGLW_DEBUG_PRINTF("Shader program linking failed:\n\n%s", log.data());
    }

    glDeleteShader(vert);
    glDeleteShader(frag);

    return out;
}

ShaderProgram ShaderProgram::loadGLSLFiles(const std::string& vertFilename, const std::string& fragFilename) {
    std::ifstream file(vertFilename);
    std::stringstream buffer;
    if (!file.is_open()) {
        FGLW_DEBUG_PRINTF("Failed to open vertex shader: %s", vertFilename.c_str());
        return ShaderProgram();
    }

    buffer << file.rdbuf();
    file.close();
    std::string vertSource = buffer.str();

    file = std::ifstream(fragFilename);
    if (!file.is_open()) {
        FGLW_DEBUG_PRINTF("Failed to open fragment shader: %s", fragFilename.c_str());
        return ShaderProgram();
    }
    buffer = std::stringstream();
    buffer << file.rdbuf();
    file.close();

    std::string fragSource = buffer.str();

    return ShaderProgram::compileGLSL(vertSource, fragSource);
}

void ShaderProgram::bind() {
    glUseProgram(this->programID);
}
}