//
// Created by arvin on 2023-03-17.
//
#include "SportsAssociation.h"


SportsAssociation::SportsAssociation(const std::string &name) {
    this->name = name;
}

SportsAssociation SportsAssociation::operator+=(Team& team) {
    for (Team* t : this->teams) {
        if (*t == team) {
            std::cout << t->GetName() << " Already exists" << std::endl;
            return *this;
        }
    }
    if (this->teams.size() >= 4) {
        std::cout << "Cannot add more teams to the association" << std::endl;
        return *this;
    }
    this->teams.push_back(&team);
    return *this;
}

void SportsAssociation::display() {
    std::cout << this->name << " has the following teams." << std::endl;
    for (auto &t: this->teams) {
        t->display();
    }
}

