#include <glad/glad.h>
#include <fglw/app.hpp>
#include <fglw/mesh.hpp>
#include <iostream>
#include <cmath>
#include <chrono>
#include <array>

struct MeshVertexData {
public:
    glm::vec3 position;
    glm::vec3 normal   = glm::vec3(1.0);
    glm::vec2 texcoord = glm::vec2(0.0);

    static const fglw::VertexAttributeLayout layout() { 
        return fglw::VertexAttributeLayout::empty()
            .add(GL_FLOAT, 3)  // position
            .add(GL_FLOAT, 3)  // normal
            .add(GL_FLOAT, 2); // texcoord
    }
};

class TriangleMeshTest : public fglw::App {
public:
    FGLW_ENABLE_APP;

    virtual void setup(std::vector<const char *> argv) override {

        mesh = fglw::TriangleMesh<MeshVertexData>(std::vector{
            std::array<MeshVertexData, 3>{
                MeshVertexData{glm::vec3(-0.5f, -0.5f, 0.0f)},
                MeshVertexData{glm::vec3( 0.5f, -0.5f, 0.0f)},
                MeshVertexData{glm::vec3( 0.0f,  0.5f, 0.0f)}}
        });

        shader = fglw::ShaderProgram::loadGLSLFiles("assets/shaders/01-triangle-mesh.vsh", "assets/shaders/01-triangle-mesh.fsh");
    }
    virtual void update() override {

            // set the screen to a yellow color tranitioning to green
        this->win.clear(glm::vec3(1.0, 1.0, 0.0));
        
        mesh.draw(this->win, shader);
    }
    virtual void teardown() override {
    }

private:
    fglw::TriangleMesh<MeshVertexData> mesh;
    fglw::ShaderProgram shader;
};

FGLW_DEFINE_APP(
    TriangleMeshTest,
    "Test App",
    800, 600
)