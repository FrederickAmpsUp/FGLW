#include <glad/glad.h>
#include <fglw/app.hpp>
#include <iostream>
#include <cmath>
#include <chrono>

class TestApp : public fglw::App {
public:
    FGLW_ENABLE_APP;

    virtual void setup(std::vector<const char *> argv) override {
    }
    virtual void update() override {
        auto end = std::chrono::high_resolution_clock::now();

        this->win.clear(glm::vec3(1.0, 0.0, 0.0));
    }
    virtual void teardown() override {
    }

private:
};

FGLW_DEFINE_APP(
    TestApp,
    "Test App",
    800, 600
)