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

void ShaderProgram::uniform(GLint location, int value) {
    glUniform1i(location, value);
}
void ShaderProgram::uniform(GLint location, glm::ivec2 value) {
    glUniform2i(location, value.x, value.y);
}
void ShaderProgram::uniform(GLint location, glm::ivec3 value) {
    glUniform3i(location, value.x, value.y, value.z);
}
void ShaderProgram::uniform(GLint location, glm::ivec4 value) {
    glUniform4i(location, value.x, value.y, value.z, value.w);
}

void ShaderProgram::uniform(GLint location, float value) {
    glUniform1f(location, value);
}
void ShaderProgram::uniform(GLint location, glm::vec2 value) {
    glUniform2f(location, value.x, value.y);
}
void ShaderProgram::uniform(GLint location, glm::vec3 value) {
    glUniform3f(location, value.x, value.y, value.z);
}
void ShaderProgram::uniform(GLint location, glm::vec4 value) {
    glUniform4f(location, value.x, value.y, value.z, value.w);
}
void ShaderProgram::uniform(GLint location, glm::mat2 value) {
    glUniformMatrix2fv(location, 1, GL_FALSE, &value[0][0]);
}
void ShaderProgram::uniform(GLint location, glm::mat3 value) {
    glUniformMatrix3fv(location, 1, GL_FALSE, &value[0][0]);
}
void ShaderProgram::uniform(GLint location, glm::mat4 value) {
    glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}

void ShaderProgram::uniform(GLint location, fglw::Texture2D& tex) {
    glUniform1i(location, tex.getTextureIndex());
}
}