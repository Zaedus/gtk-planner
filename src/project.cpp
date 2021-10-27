#include "project.hpp"

Project::Project(std::string name, GtkListBox *projects_list)
    : projects_list{projects_list}, name{name}
{
    create_list_item();
};

void Project::create_list_item()
{
    list_item_container = GTK_GRID (gtk_grid_new());
    GtkWidget *project_icon = gtk_image_new_from_icon_name("starred-symbolic", GTK_ICON_SIZE_BUTTON);
    GtkWidget *project_name = gtk_label_new(name.c_str());

    gtk_grid_attach(list_item_container, project_icon, 0, 0, 1, 1);
    gtk_grid_attach(list_item_container, project_name, 1, 0, 1, 1);

    gtk_grid_set_column_spacing(list_item_container, 15);

    gtk_widget_set_margin_top(GTK_WIDGET (list_item_container), 10);
    gtk_widget_set_margin_bottom(GTK_WIDGET (list_item_container), 10);
    gtk_widget_set_margin_start(GTK_WIDGET (list_item_container), 10);
    gtk_widget_set_margin_end(GTK_WIDGET (list_item_container), 10);

    gtk_widget_show_all(GTK_WIDGET (list_item_container));
    gtk_list_box_insert(projects_list, GTK_WIDGET (list_item_container), -1);
}

void Project::select_list_item()
{
    GtkListBoxRow *row = GTK_LIST_BOX_ROW (gtk_widget_get_parent(GTK_WIDGET (list_item_container)));
    gtk_list_box_select_row(projects_list, row);
}