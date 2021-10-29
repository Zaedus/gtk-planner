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
    on_row_select_payload *select_pd = (on_row_select_payload*) malloc(sizeof(on_row_select_payload)); 
    select_pd->content_leaflet = content_leaflet;
    select_pd->titlebar_leaflet = titlebar_leaflet;
    select_pd->projects = &projects;

    g_signal_connect(projects_list, "row-activated", G_CALLBACK (PlannerApplication::on_new_row_selected), select_pd);
    g_signal_connect(content_leaflet, "child-switched", G_CALLBACK (PlannerApplication::on_content_child_switched), titlebar_leaflet);
    g_object_bind_property(content_leaflet, "folded", back_button, "visible", G_BINDING_SYNC_CREATE);
    g_signal_connect(back_button, "clicked", G_CALLBACK (PlannerApplication::on_back_button_clicked), content_leaflet);
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
    gtk_window_present(GTK_WINDOW (main_window));
}

int PlannerApplication::on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& cli)
{
    return 0;
}

void PlannerApplication::on_new_row_selected(GtkListBox *box, GtkListBoxRow *row, on_row_select_payload *pd)
{
    (*(pd->projects))[gtk_list_box_row_get_index(row)].show_project();
    hdy_leaflet_set_visible_child_name(pd->content_leaflet, "content");
}

void PlannerApplication::on_content_child_switched(HdyLeaflet *content_leaflet, uint index, gint64 duration, HdyLeaflet *titlebar_leaflet) {
    hdy_leaflet_set_visible_child_name(titlebar_leaflet, hdy_leaflet_get_visible_child_name(content_leaflet));
}

void PlannerApplication::on_back_button_clicked(GtkButton *button, HdyLeaflet *leaflet)
{
    hdy_leaflet_set_visible_child_name(leaflet, "list");
}