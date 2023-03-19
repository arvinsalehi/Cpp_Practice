//
// Created by arvin on 2023-03-17.
//
#include "HockeyTeam.h"

HockeyTeam::HockeyTeam(const std::string& name, int wins, int ties, int losses) {
    this->name = name;
    this->wins = wins;
    this->ties = ties;
    this->losses = losses;
    this->points = 2*wins+ties;
}

std::string HockeyTeam::GetName() const {
    return this->name;
}

Err_Status HockeyTeam::display() const {
    if (this->name.empty()) {
        return Err_Undefined;
    }
    std::cout << this->name << " has " << this->wins << " wins, " << this->losses << " losses, "
    << this->ties << " ties, " << " for " << this->points << std::endl;
    return Err_Success;
}

bool HockeyTeam::operator==(const Team &other) const {
    if (const auto *ht = dynamic_cast<const HockeyTeam *>(&other)) {
        if (typeid(*this).name() == typeid(other).name() && this->points == ht->points) {
            return true;
        }
    }
    return false;
}

HockeyTeam::~HockeyTeam() = default;

