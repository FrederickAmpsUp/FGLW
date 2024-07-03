#include <fglw/shader.hpp>
#include <fstream>
#include <sstream>
#include <string>
#include <fglw/log.hpp>
#include <vector>
#include <filesystem>

static std::string loadFileContents(std::string filename, uint32_t fileIdx=0) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        FGLW_DEBUG_PRINTF("FGLW Error while opening shader: \n\nFailed to open file \"%s\" for reading.\n", filename.c_str());
        return "";
    }

    std::ostringstream contentStream;
    if (fileIdx != 0) contentStream << "#line 1 " << fileIdx << "\n";
    uint32_t lineIdx = 0;
    while (file.peek() != EOF) {
        std::string line;
        std::getline(file, line);

        if (line.rfind("#include ", 0) == 0) { // include directive
            std::string arg = line.substr(9);
            if (arg[0] != '"') {
                FGLW_DEBUG_PRINTF("FGLW Error while preprocessing shader \"%s\": Expected string after #include directive.", filename.c_str());
                continue;
            }
            size_t rightQuotePos = arg.find("\"", 1); // find the right quote
            std::string included = arg.substr(1, rightQuotePos-1);
            std::filesystem::path shaderDir = std::filesystem::path(filename).parent_path();
            contentStream << "\n" << loadFileContents((shaderDir/std::filesystem::path(included)).string(), fileIdx+1) << "\n";
            contentStream << "#line " << lineIdx+1 << " " << fileIdx << "\n";
            continue;
        }

        contentStream << line << "\n";
        lineIdx++;
    }

    file.close();
    return contentStream.str(); // Convert stringstream to string and return
}

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
    std::string vertSource = loadFileContents(vertFilename);
    std::string fragSource = loadFileContents(fragFilename);

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

void ShaderProgram::uniform(GLint location, fglw::Texture& tex) {
    glUniform1i(location, tex.getTextureIndex());
}
}