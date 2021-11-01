#include "interface.hpp"

void create_main_window(PlannerApplication *app)
{
    GtkApplicationWindow *main_window;
    GtkListBox *projects_list;
    HdyLeaflet *content_leaflet;
    HdyLeaflet *headerbar_leaflet;
    GtkCssProvider *css_provider;

    GtkBuilder *builder = gtk_builder_new();
    gtk_builder_add_from_resource(builder, "/com/zaedus/gtk-planner/ui/mainwindow.glade", NULL);
    
    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_resource(css_provider, "/com/zaedus/gtk-planner/app.css");
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER (css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    main_window = GTK_APPLICATION_WINDOW (gtk_builder_get_object (builder, "main"));
    gtk_window_set_application(GTK_WINDOW (main_window), app->gobj());
    gtk_window_set_default_size(GTK_WINDOW (main_window), 1300, 900); // Note: Developement size, not official size
    gtk_widget_set_name(GTK_WIDGET (main_window), "gtk planner");


    app->main_window = main_window;

    headerbar_leaflet = HDY_LEAFLET (gtk_builder_get_object(builder, "headerbar_leaflet"));
    content_leaflet = HDY_LEAFLET (gtk_builder_get_object(builder, "content_leaflet"));
    hdy_leaflet_set_visible_child_name(headerbar_leaflet, "list");
    hdy_leaflet_set_visible_child_name(content_leaflet, "list");
    app->headerbar_leaflet = headerbar_leaflet;
    app->content_leaflet = content_leaflet;

    app->projects_list = GTK_LIST_BOX (gtk_builder_get_object (builder, "projects"));
    app->project_content = GTK_STACK (gtk_builder_get_object (builder, "project_content"));
    app->content_headerbar = HDY_HEADER_BAR (gtk_builder_get_object(builder, "project_content_headerbar"));
    app->back_button = GTK_BUTTON (gtk_builder_get_object(builder, "back_button"));

    gtk_widget_show(GTK_WIDGET (main_window));

    g_object_unref(G_OBJECT (builder));
}