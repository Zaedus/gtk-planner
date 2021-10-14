#include "window.hpp"

MainWindow::MainWindow()
    : builder{Gtk::Builder::create_from_resource("/ui/mainwindow.glade")}
{
    set_title("GTK Planner");
    set_default_size(500, 500);

    builder->get_widget<Gtk::Viewport>("content", content);
    content->unparent();
    add(*content);

    show_all();
}
