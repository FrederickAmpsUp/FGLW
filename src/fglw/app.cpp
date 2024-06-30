#include <fglw/app.hpp>

namespace fglw {

App::App(fglw::Window& win) : win(win) {
    win.on_loop([&]() { this->update(); });
}
}