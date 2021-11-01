#pragma once

class Project;

#include "project.hpp"

class Section 
{
private:
    Project *project;
    GtkBox *container;
    int position;
    std::string title;
    
public:
    Section(Project *project, std::string title, int position);
};