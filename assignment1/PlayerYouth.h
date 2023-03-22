//
// Created by arvin on 2023-03-15.
//

#ifndef ASSIGNMENT1_PLAYERYOUTH_H
#define ASSIGNMENT1_PLAYERYOUTH_H

#include "Player.h"

template<class T>
class PlayerYouth : public Player<T> {
private:
    list<T> attackCard;
public:

    PlayerYouth();

    explicit PlayerYouth(const string &name);

    PlayerYouth(PlayerYouth<T> const &player);

    void setName(const string& newName) override;

    string GetName() override;

    void addDepCard(int card) override;

    void addDepCards(const list<int> &card) override;

    void addAttCard(int card);

    void addAttCards(const list<T> &card);

    PlayerYouth operator&=(PlayerYouth<T> &player);

    int sumDepCards() override;

    void addCash(double newCash) override;

    bool getCash(double newCash) override;

    ~PlayerYouth();

};

#endif //ASSIGNMENT1_PLAYERYOUTH_H
