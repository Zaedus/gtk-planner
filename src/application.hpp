#pragma once

#include <gtkmm.h>
#include <libhandy-1/handy.h>

#include <vector>

#include "project.hpp"

typedef struct on_row_select_payload {
    std::vector<Project> *projects;
    HdyLeaflet *content_leaflet;
    HdyLeaflet *headerbar_leaflet;
} on_row_select_payload;

class PlannerApplication : public Gtk::Application
{
private:
    void setup_signals();

    std::vector<Project> projects;

protected:
    PlannerApplication();

    virtual void on_activate();
    virtual void on_startup();
    virtual int on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& cli);

public:
    static Glib::RefPtr<PlannerApplication> get();
    static void on_new_row_selected(GtkListBox *box, GtkListBoxRow *row, on_row_select_payload *pd);
    static void on_back_button_clicked(GtkButton *button, HdyLeaflet *leaflet);

    GtkApplicationWindow *main_window;
    GtkListBox *projects_list;
    GtkStack *project_content;
    GtkButton *back_button;

    HdyLeaflet *content_leaflet;
    HdyLeaflet *headerbar_leaflet;
    HdyHeaderBar *content_headerbar;
};