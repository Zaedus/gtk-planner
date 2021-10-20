#pragma once

#include <gtkmm.h>
#include <libhandy-1/handy.h>

class PlannerApplication : public Gtk::Application
{
protected:
    PlannerApplication();

    virtual void on_activate();
    virtual void on_startup();
    virtual int on_command_line(const Glib::RefPtr<Gio::ApplicationCommandLine>& cli);

public:
    static Glib::RefPtr<PlannerApplication> get();

    HdyApplicationWindow *main_window;
    GtkListBox *projects_list;
};