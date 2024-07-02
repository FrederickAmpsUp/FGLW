# fglw (Fred's Graphics Library Wrapper)

fglw is a lightweight C++ wrapper around OpenGL designed to simplify graphics programming tasks and provide a modern, efficient interface.

## Features

- **Mesh Abstraction:** Simplifies vertex attribute setup and rendering for arbitrary mesh configurations.
- **Window Management:** Provides easy window creation and event handling.
- **Shader Program Abstraction:** Manages shader loading, compilation, and uniform management.
- **Texture Handling:** Simplifies texture loading and binding.
- **Modern OpenGL:** Leverages OpenGL's latest features and optimizations.
- **Bindless Rendering:** Simplifies programming and makes code structure management easier.

## Installation

Clone the repository and build using CMake:

```bash
git clone https://github.com/yourusername/fglw.git
cd fglw
mkdir build
cd build
cmake ..
make
```

## Usage

Usage instructions and documentation coming soon! For now, bask in this example program:
```cpp
#include <fglw/fglw.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

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
            VertexData{glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f)}
        );
        mesh.add_triangle(
            VertexData{glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
            VertexData{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
            VertexData{glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)}
        );

        shader = fglw::ShaderProgram::loadGLSLFiles("assets/shaders/02-advanced-rendering.vsh", "assets/shaders/02-advanced-rendering.fsh");

        this->object = glm::identity<glm::mat4x4>();
        this->view = glm::lookAt(glm::vec3(0.0f, 1.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        this->projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        stbi_set_flip_vertically_on_load(true);
        int width, height, channels;
        unsigned char *data = stbi_load("assets/images/test_dev_texture.jpg", &width, &height, &channels, 0);
        if (channels == 3)
            this->texture0 = fglw::Texture(width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);

        data = stbi_load("assets/images/test_nyancat.png", &width, &height, &channels, 0);
        if (channels == 3)
            this->texture1 = fglw::Texture(width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

        this->shader.uniform("tex0", this->texture0);
        this->shader.uniform("tex1", this->texture1);
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
    fglw::Texture texture0, texture1;
    glm::mat4x4 object, view, projection;
};

FGLW_DEFINE_APP(
    AdvancedRenderingTest,
    "Advanced Rendering Text",
    800, 600
)
```

## EARLY DEV NOTICE!

This project is in early development. As such, many features (like documentation) are missing. Aditionally, any part of the API is subject to change.
