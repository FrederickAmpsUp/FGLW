#pragma once

#include <glad/glad.h>
#include <GL/gl.h>
#include <vector>
#include <tuple>
#include <stddef.h>
#include <fglw/log.hpp>
#include <type_traits>
#include <fglw/framebuffer.hpp>
#include <fglw/shader.hpp>
#include <GL/glu.h>
#include <iostream>

namespace fglw {

class VertexAttributeLayout {
public:
    VertexAttributeLayout() { this->stride = 0; }
    static VertexAttributeLayout empty() { return VertexAttributeLayout(); }

    VertexAttributeLayout add(GLenum type, GLuint count);

    /**
     * Bind the layout to the currently bound array buffer.
     * This should only be called internally.
     */
    void use() const;

private:
    std::vector<std::tuple<GLenum, GLuint, size_t> > attribs;
    size_t stride;
};

template<typename V>
class TriangleMesh {
public:
    TriangleMesh() {
        vertices.clear();
        indices.clear();

        glGenVertexArrays(1, &this->VAO);
        glBindVertexArray(this->VAO);

        glGenBuffers(1, &this->VBO);
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glGenBuffers(1, &this->EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);

        this->ready = false;
    }

    TriangleMesh(std::vector<V> vertices, std::vector<GLuint> indices) : TriangleMesh() {
        this->vertices = vertices;
        this->indices = indices;
        this->ready = false;
    }

    TriangleMesh(std::vector<std::array<V, 3>> triangles) : TriangleMesh() {
        for (const auto& [a, b, c] : triangles) {
            this->add_triangle(a, b, c);
        }
        this->ready = false;
    }

    void add_triangle(V a, V b, V c) {
        unsigned int start = vertices.size();

        vertices.push_back(a);
        indices.push_back(start++);
        vertices.push_back(b);
        indices.push_back(start++);
        vertices.push_back(c);
        indices.push_back(start++);
        this->ready = false;
    }

    void draw(fglw::RenderTarget& fb, fglw::ShaderProgram& shader) {
        fb.bind();
        shader.bind();
        this->construct();

        glBindVertexArray(this->VAO);
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
    }
private:
    void construct() {
        if (this->ready) return;
        this->ready = true;
        glBindVertexArray(this->VAO);

        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(V), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), this->indices.data(), GL_STATIC_DRAW);

        V::layout().use();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    std::vector<V> vertices;
    std::vector<GLuint> indices;
    bool ready = false;

    GLuint VAO, VBO, EBO;
};
}