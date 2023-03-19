//
// Created by arvin on 2023-03-15.
//

#ifndef ASSIGNMENT1_PLAYERADULT_H
#define ASSIGNMENT1_PLAYERADULT_H
//
// Created by arvin on 2023-03-15.
//


#include "Player.h"

template<class T>
class PlayerAdult : public Player<T> {
private:
    list<int> attackCard;
public:
    PlayerAdult();

    explicit PlayerAdult(string name);

    PlayerAdult(PlayerAdult const &player);

    void setName(string newName);

    string GetName() override;

    void addDepCard(int card) override;

    void addDepCards(const list<int> &card) override;

    void addAttCard(int card);

    void addAttCards(const list<int> &card);

    PlayerAdult operator&=(PlayerAdult &player);

    int sumDepCards() override;

    void addCash(double newCash) override;

    bool getCash(double newCash) override;

    ~PlayerAdult() override;

};

#endif //ASSIGNMENT1_PLAYERADULT_H
