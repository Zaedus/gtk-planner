#include "window.hpp"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("com.github.zaedus.gtk-planner");

    return app->make_window_and_run<MainWindow>(argc, argv);
}