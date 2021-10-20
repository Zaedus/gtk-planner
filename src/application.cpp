#include "application.hpp"
#include "interface.hpp"

/**
 * Constructing
 */

PlannerApplication::PlannerApplication()
    : Gtk::Application{"com.zaedus.gtk-planner", Gio::APPLICATION_HANDLES_COMMAND_LINE}
{
    Glib::set_application_name("Planner");
}

Glib::RefPtr<PlannerApplication> PlannerApplication::get()
{
    static Glib::RefPtr<PlannerApplication> singleton;

    if (!singleton) {
        singleton = Glib::RefPtr<PlannerApplication>(new PlannerApplication());
    }
    return singleton;
}


/**
 * Inherited events
 */

void PlannerApplication::on_startup()
{
    Gtk::Application::on_startup();

    hdy_init();

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_resource("/com/zaedus/gtk-planner/mainwindow.glade");

    create_main_window(this);
}

void PlannerApplication::on_activate()
{

}

int PlannerApplication::on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& cli)
{
    return 0;
}