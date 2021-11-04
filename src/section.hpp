#pragma once

class Project;
class Card;

#include <vector>
#include "project.hpp"
#include "card.hpp"

class Section 
{
private:
    GtkGrid *container;
    int position;
    std::string title;
    std::vector<Card> cards;
    
public:
    Section(Project *project, std::string title, int position);
    Card *add_card(std::string content, int position);

    Project *project;
};