#pragma once

#include <gtk/gtk.h>
#include <libhandy-1/handy.h>

#include <string>
#include <vector>

class Section;

#include "section.hpp"

typedef struct project_widgets
{
    GtkListBox *projects_list;
    GtkStack *project_content;
    HdyHeaderBar *content_headerbar;
} ProjectWidgets;

class Project
{
private:
    void create_list_item();
    
    GtkListBox *projects_list;
    GtkStack *project_content;
    HdyHeaderBar *content_headerbar;

    GtkFlowBox *content_container = nullptr;
    GtkGrid *list_item_container;

    std::vector<Section> sections;

public:
    Project(std::string name, ProjectWidgets *widgets);
    void select_list_item();
    void show_project();

    std::string name;
};