//
// Created by arvin on 2023-03-17.
//
#include "BaseballTeam.h"

BaseballTeam::BaseballTeam(const std::string &name, int wins, int losses) {
    this->name = name;
    this->wins = wins;
    this->losses = losses;
    this->winPercentage = ((float) this->wins / (float) (this->wins + this->losses));
}

std::string BaseballTeam::GetName() const {
    return this->name;
}

Err_Status BaseballTeam::display() const {
    if (this->name.empty()) return Err_Undefined;
    std::cout << this->name << " has " << this->wins << " wins and " << this->losses
              << " losses for a winning percentage of " << this->winPercentage << std::endl;
    return Err_Success;
}

bool BaseballTeam::operator==(const Team &other) const {
    if (const auto *bt = dynamic_cast<const BaseballTeam *>(&other)) {
        if (typeid(*this).name() == typeid(other).name() && this->winPercentage == bt->winPercentage) {
            return true;
        }
    }
    return false;
}


BaseballTeam::~BaseballTeam() = default;

