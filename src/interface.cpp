#include "interface.hpp"

void create_main_window(PlannerApplication *app)
{
    HdyApplicationWindow *main_window;
    GtkListBox *projects_list;

    GtkBuilder *builder = gtk_builder_new();
    gtk_builder_add_from_resource(builder, "/com/zaedus/gtk-planner/mainwindow.glade", NULL);
    
    main_window = HDY_APPLICATION_WINDOW (gtk_builder_get_object (builder, "main"));
    gtk_window_set_application(GTK_WINDOW (main_window), app->gobj());
    gtk_widget_set_name(GTK_WIDGET (main_window), "gtk-planner");
    app->main_window = main_window;

    projects_list = GTK_LIST_BOX (gtk_builder_get_object (builder, "projects"));
    app->projects_list = projects_list;

    gtk_widget_show(GTK_WIDGET (main_window));

    g_object_unref(G_OBJECT (builder));
}