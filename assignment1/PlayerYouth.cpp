//
// Created by arvin on 2023-03-15.
//
#include "PlayerYouth.h"

#include <utility>
#include <cstring>

template<class T>
PlayerYouth<T>::PlayerYouth(): Player<T>() {}

template<class T>
PlayerYouth<T>::PlayerYouth(string name) : Player<T>(std::move(name)) {}

template<class T>
PlayerYouth<T>::PlayerYouth(const PlayerYouth &player) {
    this->name = player.name;
    this->attackCard = player.attackCard;
}

template<class T>
void PlayerYouth<T>::setName(string newName) {
    Player<T>::setName(newName);
}

template<class T>
string PlayerYouth<T>::GetName() {
    return Player<T>::GetName();
}

template<class T>
void PlayerYouth<T>::addDepCard(int card) {
    Player<T>::addDepCard(card);
}

template<class T>
void PlayerYouth<T>::addDepCards(const list<int> &card) {
    Player<T>::addDepCards(card);
}

template<class T>
void PlayerYouth<T>::addAttCard(int card) {
    this->attackCard.push_back(card);
}

template<class T>
void PlayerYouth<T>::addAttCards(const list<T> &card) {
    for (const int & i : card) {
        this->attackCard.push_back(i);
    }
}

template<class T>
PlayerYouth<T> PlayerYouth<T>::operator&=(PlayerYouth &player) {
    strcpy(this->name, player.name);
    this->dependentCards = player.dependentCards;
    this->attackCard = player.attackCard;
    return *this;
}

template<class T>
int PlayerYouth<T>::sumDepCards() {
    return Player<T>::sumDepCards();
}

template<class T>
void PlayerYouth<T>::addCash(double newCash) {
    Player<T>::addCash(newCash);
}

template<class T>
bool PlayerYouth<T>::getCash(double newCash) {
    return Player<T>::getCash(newCash);
}

template<class T>
PlayerYouth<T>::~PlayerYouth() = default;

