//
// Created by arvin on 2023-03-15.
//
#include "PlayerAdult.h"

#include <utility>
#include <cstring>

template<class T>
PlayerAdult<T>::PlayerAdult():Player<T>() {}

template<class T>
PlayerAdult<T>::PlayerAdult(string name) : Player<T>(std::move(name)) {}

template<class T>
PlayerAdult<T>::PlayerAdult(const PlayerAdult &player) {
    this->name = player.name;
    this->attackCard = player.attackCard;
}
template<class T>
void PlayerAdult<T>::setName(string newName) {
    Player<T>::setName(newName);
}

template<class T>
string PlayerAdult<T>::GetName() {
    return Player<T>::GetName();
}

template<class T>
void PlayerAdult<T>::addDepCard(int card) {
    Player<T>::addDepCard(card);
}

template<class T>
void PlayerAdult<T>::addDepCards(const list<int> &card) {
    Player<T>::addDepCards(card);
}

template<class T>
void PlayerAdult<T>::addAttCard(int card) {
    this->attackCard.push_back(card);
}

template<class T>
void PlayerAdult<T>::addAttCards(const list<int> &card) {
    for (const int & i : card) {
        this->attackCard.push_back(i);
    }
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
void PlayerAdult<T>::addCash(double newCash) {
    Player<T>::addCash(newCash);
}

template<class T>
bool PlayerAdult<T>::getCash(double newCash) {
    return Player<T>::getCash(newCash);
}

template<class T>
PlayerAdult<T>::~PlayerAdult() = default;

