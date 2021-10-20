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

    GtkGrid *project = GTK_GRID (gtk_grid_new());
    GtkWidget *project_icon = gtk_image_new_from_icon_name("starred-symbolic", GTK_ICON_SIZE_BUTTON);
    GtkWidget *project_name = gtk_label_new("Sample Project Name");

    gtk_grid_attach(project, project_icon, 0, 0, 1, 1);
    gtk_grid_attach(project, project_name, 1, 0, 1, 1);

    gtk_grid_set_column_spacing(project, 15);

    gtk_widget_set_margin_top(GTK_WIDGET (project), 10);
    gtk_widget_set_margin_bottom(GTK_WIDGET (project), 10);
    gtk_widget_set_margin_start(GTK_WIDGET (project), 10);
    gtk_widget_set_margin_end(GTK_WIDGET (project), 10);

    gtk_widget_show_all(GTK_WIDGET (project));
    gtk_list_box_insert(projects_list, GTK_WIDGET (project), -1);
}

void PlannerApplication::on_activate()
{
    std::cout << "Activated!" << std::endl;
}

int PlannerApplication::on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& cli)
{
    return 0;
}