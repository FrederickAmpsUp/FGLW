#pragma once

#include <vector>
#include <fglw/window.hpp>

namespace fglw {

class App {
public:
    App(fglw::Window& win);

    virtual void setup(std::vector<const char *> argv) = 0;
    virtual void update() = 0;
    virtual void teardown() = 0;
};

 // TODO: window manages loop
#define FGLW_DEFINE_APP(app, title, width, height) \
int main(int argc, const char *argv[]) { \
    const std::string TITLE = (title); \
    fglw::Window win((width), (height), TITLE); \
    app inst = app (win); \
\
    std::vector<const char *> args(argc); \
    for (int i = 0; i < argc; i++) { \
        args[i] = argv[i]; \
    } \
\
    inst.setup( args ); \
    win.loop(); \
    inst.teardown(); \
\
    return 0; \
}

#define FGLW_ENABLE_APP using ::fglw::App::App

}