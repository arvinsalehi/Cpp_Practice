//
// Created by arvin on 2023-03-17.
//

#ifndef LAB_6_BASEBALLTEAM_H
#define LAB_6_BASEBALLTEAM_H

#include "Team.h"

class BaseballTeam : public Team {
private:
    std::string name;
    int wins;
    int losses;
    float winPercentage;
public:
    explicit BaseballTeam(const std::string &name = "", int wins = 0, int losses = 0);

    std::string GetName() const override;

    Err_Status display() const override;

    bool operator==(const Team &) const override;

    ~BaseballTeam();
};

#endif //LAB_6_BASEBALLTEAM_H
