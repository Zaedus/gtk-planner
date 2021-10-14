#include "window.hpp"

int main(int argc, char* argv[]) {

    Glib::init();

    auto app = Gtk::Application::create(argc, argv, "com.github.zaedus.gtk-planner");
    MainWindow window = MainWindow();

    return app->run(window);
}