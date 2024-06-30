#include <fglw/mesh.hpp>
#include <fglw/log.hpp>
#include <GL/glu.h>

namespace fglw {

VertexAttributeLayout VertexAttributeLayout::add(GLenum type, GLuint count) {
    size_t sz;

    switch (type) {
        case GL_FLOAT:
            sz = sizeof(GLfloat);
            break;
        case GL_UNSIGNED_BYTE:
            sz = sizeof(GLubyte);
            break;
        case GL_BYTE:
            sz = sizeof(GLbyte);
            break;
        case GL_UNSIGNED_SHORT:
            sz = sizeof(GLushort);
            break;
        case GL_SHORT:
            sz = sizeof(GLshort);
            break;
        case GL_UNSIGNED_INT:
            sz = sizeof(GLuint);
            break;
        case GL_INT:
            sz = sizeof(GLint);
            break;
        case GL_DOUBLE:
            sz = sizeof(GLdouble);
            break;
        default:
            FGLW_DEBUG_PRINTF("Unknown GL Data type.\n");
    }

    this->stride += sz * count;
    this->attribs.push_back(std::tuple(type, count, sz));

    return *this;
}

void VertexAttributeLayout::use() const {
    int i = 0;
    size_t offset = 0;
    for (const auto& [type, count, sz] : this->attribs) {
        glVertexAttribPointer(i, count, type, GL_FALSE, this->stride, (void *)offset);
        glEnableVertexAttribArray(i);
        offset += sz * count;
        i++;
    }
}
}