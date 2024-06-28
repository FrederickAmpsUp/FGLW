#include <glad/glad.h>
#include <fglw/app.hpp>
#include <iostream>
#include <cmath>
#include <chrono>

class TestApp : public fglw::App {
public:
    FGLW_ENABLE_APP;

    virtual void setup(std::vector<const char *> argv) override {
        std::cout << "Setup" << std::endl;
        this->start = std::chrono::high_resolution_clock::now();
    }
    virtual void update() override {
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            // set the screen to a yellow color tranitioning to green
        glClearColor(powf(sinf(time.count() * 3.14 / 1000.0), 2.0f), 1.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    virtual void teardown() override {
        std::cout << "Teardown" << std::endl;
    }

private:
    std::chrono::_V2::system_clock::time_point start;
};

FGLW_DEFINE_APP(
    TestApp,
    "Test App",
    800, 600
)