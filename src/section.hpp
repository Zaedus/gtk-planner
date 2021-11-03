#pragma once

class Project;
class Card;

#include <vector>
#include "project.hpp"
#include "card.hpp"

class Section 
{
private:
    GtkBox *container;
    int position;
    std::string title;
    std::vector<Card> cards;
    
public:
    Section(Project *project, std::string title, int position);

    Project *project;
};