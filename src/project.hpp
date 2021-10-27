#pragma once

#include <gtk/gtk.h>

class Project
{
private:
    void create_list_item();
    
    GtkListBox *project_list;


public:
    Project(GtkListBox *project_list);


};