//
// Created by arvin on 2023-03-15.
//

#ifndef ASSIGNMENT1_PLAYERADULT_H
#define ASSIGNMENT1_PLAYERADULT_H
//
// Created by arvin on 2023-03-15.
//

#include "Player.h"
#include "utilities.h"

template<class T>
class PlayerAdult : public Player<T> {
public:
    PlayerAdult<T>();

    explicit PlayerAdult<T>(string name, int cash = 1000);

    PlayerAdult(PlayerAdult<T> const &player);

    void setName(const string &newName) override;

    string GetName() override;

    void addDepCards(int card) override;

    void addAttCards(int card) override;

    PlayerAdult<T> operator&=(PlayerAdult<T> &player);

    int sumDepCards() override;

    T sumAttCards() const override;

    T sumCards() override;

    void addCash(int newCash) override;

    int getCash() override;

    void report() override;

    void setState(bool val) override;

    bool getState() override;

    bool operator==(Player<T> &player1) override;

    bool operator<(Player<T> &player1) override;

    bool operator>(Player<T> &player1) override;

    ~PlayerAdult() override;

};

template<class T>
PlayerAdult<T>::PlayerAdult():Player<T>() {}

template<class T>
PlayerAdult<T>::PlayerAdult(const string name, int cash) : Player<T>(name, cash) {}

template<class T>
PlayerAdult<T>::PlayerAdult(const PlayerAdult &player) {
    this->name = player.name;
    this->attackCard = player.attackCard;
}

template<class T>
void PlayerAdult<T>::setName(const string &newName) {
    Player<T>::setName(newName);
}

template<class T>
string PlayerAdult<T>::GetName() {
    return Player<T>::GetName();
}

template<class T>
void PlayerAdult<T>::addDepCards(int card) {
    Player<T>::addDepCards(card);
}

template<class T>
void PlayerAdult<T>::addAttCards(int card) {
    for (int i = 0; i <= card; i++) {
        this->attackCard.push_back(generateRandomNumber<T>(1, 15, true));
    }
}

template<class T>
bool PlayerAdult<T>::getState() {
    return Player<T>::getState();
}

template<class T>
void PlayerAdult<T>::setState(bool val) {
    Player<T>::setState(val);
}


template<class T>
PlayerAdult<T> PlayerAdult<T>::operator&=(PlayerAdult<T> &player) {
    strcpy(this->name, player.name);
    this->dependentCards = player.dependentCards;
    this->attackCard = player.attackCard;

    return *this;
}

template<class T>
int PlayerAdult<T>::sumDepCards() {
    return Player<T>::sumDepCards();
}

template<class T>
T PlayerAdult<T>::sumAttCards() const {
    T sum = 0;
    for (auto &i: this->attackCard) sum += i;
    return sum;
}


template<class T>
T PlayerAdult<T>::sumCards() {
    return Player<T>::sumCards();
}

template<class T>
void PlayerAdult<T>::addCash(int newCash) {
    Player<T>::addCash(newCash);
}

template<class T>
int PlayerAdult<T>::getCash() {
    return Player<T>::getCash();
}

template<class T>
void PlayerAdult<T>::report() {
    Player<T>::report();
}

template<class T>
bool PlayerAdult<T>::operator>(Player<T> &player1) {
    return Player<T>::operator>(player1);
}

template<class T>
bool PlayerAdult<T>::operator<(Player<T> &player1) {
    return Player<T>::operator<(player1);
}

template<class T>
bool PlayerAdult<T>::operator==(Player<T> &player1) {
    return Player<T>::operator==(player1);
}

template<class T>
PlayerAdult<T>::~PlayerAdult() = default;


#endif //ASSIGNMENT1_PLAYERADULT_H
