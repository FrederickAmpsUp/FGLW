#include <fglw/fglw.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct VertexData {
    glm::vec3 position;
    glm::vec3 normal = glm::vec3(1.0f);
    glm::vec2 texcoord = glm::vec2(1.0f);

    static const fglw::VertexAttributeLayout layout() {
        return fglw::VertexAttributeLayout::empty()
            .add(GL_FLOAT, 3)  // position
            .add(GL_FLOAT, 3)  // normal
            .add(GL_FLOAT, 2); // texcoord
    }
};

class AdvancedRenderingTest : public fglw::App {
public:
    FGLW_ENABLE_APP;

    virtual void setup(std::vector<const char *> args) override {
        std::cout << "TEST" << std::endl;
        mesh = fglw::TriangleMesh<VertexData>();

        mesh.add_triangle(
            VertexData{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
            VertexData{glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
            VertexData{glm::vec3( 0.0f,  0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f)}
        );

        shader = fglw::ShaderProgram::loadGLSLFiles("assets/shaders/02-advanced-rendering.vsh", "assets/shaders/02-advanced-rendering.fsh");

        this->object = glm::identity<glm::mat4x4>();
        this->view = glm::lookAt(glm::vec3(0.0f, 1.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        this->projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    }

    virtual void update() override {
        this->win.clear(glm::vec3(0.1, 0.1, 0.1));

        this->object = glm::identity<glm::mat4x4>();
        this->object = glm::rotate(this->object, this->win.run_time(), glm::vec3(0.1f, 1.0f, 0.0f));

        this->shader.uniform("proj", this->projection);
        this->shader.uniform("view", this->view);
        this->shader.uniform("model", this->object);

        this->mesh.draw(this->win, this->shader);
    }
    virtual void teardown() override {

    }

private:
    fglw::TriangleMesh<VertexData> mesh;
    fglw::ShaderProgram shader;
    glm::mat4x4 object, view, projection;
};

FGLW_DEFINE_APP(
    AdvancedRenderingTest,
    "Advanced Rendering Text",
    800, 600
)