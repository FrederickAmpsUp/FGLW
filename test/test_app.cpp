#include <fglw/app.hpp>
#include <iostream>

class TestApp : public fglw::App {
public:
    FGLW_ENABLE_APP;

    virtual void setup(std::vector<const char *> argv) override {
        std::cout << "Setup" << std::endl;
    }
    virtual void update() override {

    }
    virtual void teardown() override {
        std::cout << "Teardown" << std::endl;
    }
};

FGLW_DEFINE_APP(
    TestApp,
    "Test App",
    800, 600
)