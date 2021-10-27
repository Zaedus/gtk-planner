#pragma once

#include <gtk/gtk.h>
#include <string>

class Project
{
private:
    void create_list_item();
    
    GtkListBox *projects_list;
    GtkStack *project_content;

    GtkFlowBox *content_container = nullptr;
    GtkGrid *list_item_container;

public:
    Project(std::string name, GtkListBox *projects_list, GtkStack *project_content);
    void select_list_item();
    void show_project();

    std::string name;
};