//
// Created by arvin on 2023-03-09.
//

#ifndef ASSIGNMENT1_PLAYER_H
#define ASSIGNMENT1_PLAYER_H

#include <string>
#include <list>
#include "utilities.h"

using namespace std;

template<class T>
class Player {
protected:
    string name;
    int cash{};
    list<int> dependentCards;
    list <T> attackCard;
    bool disqualified{};
public:
    explicit Player<T>(const string &name = "", int cash = 1000);

    Player(Player<T> const &player);

    virtual void setName(const string &newName);

    virtual string GetName();

    virtual void addDepCards(int card);

    virtual void addAttCards(int card);

    virtual int sumDepCards();

    virtual T sumAttCards() const;

    virtual T sumCards();

    virtual void addCash(int newCash);

    virtual int getCash();

    virtual void setState(bool val);

    virtual bool getState();

    virtual void report();

    virtual Player<T> operator&=(Player<T> &player);

    virtual bool operator==(Player<T> &player1);

    virtual bool operator<(Player<T> &player1);

    virtual bool operator>(Player<T> &player1);

    virtual ~Player();

};


template<class T>
Player<T>::Player(const string &name, int cash) {
    this->name = name;
    this->cash = cash;
    this->disqualified = false;
}

template<class T>
Player<T>::Player(const Player<T> &player) {
    this->name = player.name;
    this->cash = player.cash;
}

template<class T>
void Player<T>::setName(const string &newName) {
    this->name = newName;
}

template<class T>
string Player<T>::GetName() {
    return this->name;
}

template<class T>
int Player<T>::sumDepCards() {
    int sum = 0;
    for (auto i: this->dependentCards) {
        sum+=i;
    }
    return sum;
}

template<class T>
void Player<T>::addCash(int newCash) {
    this->cash += newCash;
}

template<class T>
int Player<T>::getCash() {
    return this->cash;
}

template<class T>
void Player<T>::setState(bool val) {
    this->disqualified = val;
}

template<class T>
T Player<T>::sumCards() {
    T sum = this->sumAttCards() - this->sumDepCards();
    return sum;
}

template<class T>
void Player<T>::addDepCards(int card)  {
    for (int i = 0; i <= card; i++) {
        this->dependentCards.push_back(generateRandomNumber<int>(1, 5));
    }
}

template<class T>
T Player<T>::sumAttCards() const{
    return 0;
}

template<class T>
void Player<T>::addAttCards(int card) {}

template<class T>
bool Player<T>::getState() {
    return this->disqualified;
}

template<class T>
void Player<T>::report() {
    cout << this->GetName() << " the sum of your cards are: "
         << this->sumCards() << endl;
}

template<class T>
Player<T> Player<T>::operator&=(Player<T> &player) {
    this->name = player.name;
    this->cash = player.cash;
    return *this;
}

template<class T>
bool Player<T>::operator==(Player<T> &player) {
    if (this->sumCards() == player.sumCards()) return true;
    return false;
}

template<class T>
bool Player<T>::operator<(Player<T> &player) {
    if (this->sumCards() < player.sumCards()) return true;
    return false;
}

template<class T>
bool Player<T>::operator>(Player<T> &player) {
    if (this->sumCards() > player.sumCards()) return true;
    return false;
}

template<class T>
Player<T>::~Player() = default;

#endif //ASSIGNMENT1_PLAYER_H
