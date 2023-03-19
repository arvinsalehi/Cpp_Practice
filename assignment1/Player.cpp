//
// Created by arvin on 2023-03-09.
//
#include "Player.h"
#include <utility>
#include <iostream>

template<class T>
Player<T>::Player(const string& name, double cash) {
    this->name = name;
    this->cash = cash;
}

template<class T>
Player<T>::Player(const Player &player) {
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
    return 0;
}

template<class T>
void Player<T>::addCash(double newCash) {
    this->cash += cash;
    cout << "Your bank is:\t" << this->cash << endl;
}

template<class T>
bool Player<T>::getCash(double newCash) {
    bool retVal = false;

    if (this->cash < newCash) {
        return retVal;
    }
    this->cash -= cash;
    retVal = true;
    return retVal;
}

template<class T>
void Player<T>::addDepCard(int card) {
    this->dependentCards.push_back(card);
}

template<class T>
void Player<T>::addDepCards(const list<int> &card) {
    for (const int & i : card) {
        this->dependentCards.push_back(i);
    }
}

template<class T>
Player<T> Player<T>::operator&=(Player<T> &player) {
    this->name = player.name;
    this->cash = player.cash;
    return *this;
}

template<class T>
bool operator==(const Player<T> &player1, const Player<T> &player2) {
    if (player1.cash == player2.cash) return true;
    return false;
}

template<class T>
bool operator<(const Player<T> &player1, const Player<T> &player2) {
    if (player1.cash < player2.cash) return true;
    return false;
}

template<class T>
bool operator>(const Player<T> &player1, const Player<T> &player2) {
    if (player1.cash > player2.cash) return true;
    return false;
}

template<class T>
Player<T>::~Player() = default;





/// This is something to work on later
//    bool retVal = false;
//    if (is_same<T, int>::value) {
//        this->dependentCards.push_back(card);
//    } else {
//
//    }
//    return retVal;