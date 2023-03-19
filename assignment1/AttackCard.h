//
// Created by arvin on 2023-03-15.
//

#ifndef ASSIGNMENT1_ATTACKCARD_H
#define ASSIGNMENT1_ATTACKCARD_H

#include "Card.h"

template<class T>
class AttackCard: Card<T> {
public:
    AttackCard();
    T genCard();
    T drawCard();
    ~AttackCard() = default;
};

template<class T>
AttackCard<T>::AttackCard() : Card<T>() {}

template<class T>
T AttackCard<T>::genCard() {
    return Card<T>().genCard();
}

template<class T>
T AttackCard<T>::drawCard() {
    return Card<T>().drawCard();
}



#endif //ASSIGNMENT1_ATTACKCARD_H
