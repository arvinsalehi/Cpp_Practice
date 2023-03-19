//
// Created by arvin on 2023-03-17.
//

#ifndef LAB_6_SPORTSASSOCIATION_H
#define LAB_6_SPORTSASSOCIATION_H

#include <list>
#include <memory>
#include "string"
#include "Team.h"


class SportsAssociation {
protected:
    std::string name;
    std::list<Team*> teams;
public:
    explicit SportsAssociation(const std::string& name="");
    SportsAssociation operator+=(Team &team);
    void display();
    ~SportsAssociation() = default;
};
#endif //LAB_6_SPORTSASSOCIATION_H
