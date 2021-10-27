#include "application.hpp"
#include "interface.hpp"

#include <iostream>

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

    std::cout << "Started up!" << std::endl;

    hdy_init();

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_resource("/com/zaedus/gtk-planner/mainwindow.glade");

    create_main_window(this);

    projects.push_back(Project("My Project", projects_list));
    projects[0].select_list_item();
}

void PlannerApplication::on_activate()
{
    std::cout << "Activated!" << std::endl;
}

int PlannerApplication::on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& cli)
{
    return 0;
}