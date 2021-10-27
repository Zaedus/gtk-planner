#pragma once

#include <gtk/gtk.h>
#include <string>

class Project
{
private:
    void create_list_item();
    
    GtkListBox *projects_list;
    GtkGrid *list_item_container;

public:
    Project(std::string name, GtkListBox *projects_list);
    void select_list_item();

    std::string name;
};