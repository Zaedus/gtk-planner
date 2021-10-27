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

void PlannerApplication::setup_signals()
{
    g_signal_connect(projects_list, "row-selected", G_CALLBACK (PlannerApplication::on_new_row_selected), &projects);
}


/**
 * Events
 */

void PlannerApplication::on_startup()
{
    Gtk::Application::on_startup();

    std::cout << "Started up!" << std::endl;

    hdy_init();

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_resource("/com/zaedus/gtk-planner/mainwindow.glade");

    create_main_window(this);

    setup_signals();

    projects.push_back(Project("My Project", projects_list, project_content));
    projects.push_back(Project("My Second Project", projects_list, project_content));
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

void PlannerApplication::on_new_row_selected(GtkListBox *box, GtkListBoxRow *row, gpointer pd)
{
    std::vector<Project> *projects = (std::vector<Project>*)pd;
    (*projects)[gtk_list_box_row_get_index(row)].show_project();
}