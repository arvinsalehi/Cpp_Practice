//
// Created by arvin on 2023-03-15.
//

#ifndef ASSIGNMENT1_PLAYERYOUTH_H
#define ASSIGNMENT1_PLAYERYOUTH_H

#include "Player.h"
#include "utilities.h"

template<class T>
class PlayerYouth : public Player<T> {
public:

    PlayerYouth<T>();

    explicit PlayerYouth<T>(string name, int cash = 1000);

    PlayerYouth<T>(PlayerYouth<T> const &player);

    void setName(const string &newName) override;

    string GetName() override;

    void addDepCards(int card) override;

    void addAttCards(int card) override;

    PlayerYouth<T> operator&=(PlayerYouth<T> &player);

    int sumDepCards() override;

    T sumAttCards() const override;

    T sumCards() override;

    void addCash(int newCash) override;

    int getCash() override;

    void setState(bool val) override;

    bool getState() override;

    void report() override;

    bool operator==(Player<T> &player1) override;

    bool operator<(Player<T> &player1) override;

    bool operator>(Player<T> &player1) override;

    ~PlayerYouth();

};

template<class T>
PlayerYouth<T>::PlayerYouth(): Player<T>() {}

template<class T>
PlayerYouth<T>::PlayerYouth(const string name, int cash) : Player<T>(name, cash) {}

template<class T>
PlayerYouth<T>::PlayerYouth(const PlayerYouth &player) {
    this->name = player.name;
    this->attackCard = player.attackCard;
}

template<class T>
void PlayerYouth<T>::setName(const string &newName) {
    Player<T>::setName(newName);
}

template<class T>
string PlayerYouth<T>::GetName() {
    return Player<T>::GetName();
}


template<class T>
int PlayerYouth<T>::sumDepCards() {
    return Player<T>::sumDepCards();
}

template<class T>
T PlayerYouth<T>::sumCards() {
    return Player<T>::sumCards();
}

template<class T>
void PlayerYouth<T>::addCash(int newCash) {
    Player<T>::addCash(newCash);
}

template<class T>
int PlayerYouth<T>::getCash() {
    return Player<T>::getCash();
}

template<class T>
void PlayerYouth<T>::addDepCards(int card) {
    Player<T>::addDepCards(card);
}

template<class T>
void PlayerYouth<T>::addAttCards(int card) {
    for (int i = 0; i <= card; i++) {
        this->attackCard.push_back(generateRandomNumber<T>(1, 10, true));
    }
}

template<class T>
void PlayerYouth<T>::setState(bool val) {
    Player<T>::setState(val);
}

template<class T>
T PlayerYouth<T>::sumAttCards() const {
    T sum = 0;
    for (auto &i: this->attackCard) sum += i;
    return sum;
}

template<class T>
bool PlayerYouth<T>::getState() {
    return Player<T>::getState();
}

template<class T>
PlayerYouth<T> PlayerYouth<T>::operator&=(PlayerYouth &player) {
    strcpy(this->name, player.name);
    this->dependentCards = player.dependentCards;
    this->attackCard = player.attackCard;
    return *this;
}

template<class T>
void PlayerYouth<T>::report() {
    Player<T>::report();
}

template<class T>
bool PlayerYouth<T>::operator>(Player<T> &player1) {
    return Player<T>::operator>(player1);
}

template<class T>
bool PlayerYouth<T>::operator<(Player<T> &player1) {
    return Player<T>::operator<(player1);
}

template<class T>
bool PlayerYouth<T>::operator==(Player<T> &player1) {
    return Player<T>::operator==(player1);
}

template<class T>
PlayerYouth<T>::~PlayerYouth() = default;


#endif //ASSIGNMENT1_PLAYERYOUTH_H
