//
// Created by arvin on 2023-03-17.
//

#ifndef LAB_6_HOCKEYTEAM_H
#define LAB_6_HOCKEYTEAM_H

#include "Team.h"

class HockeyTeam : public Team {
private:
    std::string name;
    int wins;
    int ties;
    int losses;
    int points;
public:
    explicit HockeyTeam(const std::string &name = "", int wins = 0, int ties = 0, int losses = 0);

    std::string GetName() const override;

    Err_Status display() const override;

    bool operator==(const Team &hockeyTeam) const override;

    ~HockeyTeam();
};

#endif //LAB_6_HOCKEYTEAM_H
