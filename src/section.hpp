#pragma once

class Project;

#include "project.hpp"

class Section 
{
private:
    Project *project;
    
public:
    Section(Project *project);
};