//
// Created by arvin on 2023-03-09.
//

#ifndef ASSIGNMENT1_PLAYER_H
#define ASSIGNMENT1_PLAYER_H

#include <string>
#include <list>
#include "Card.h"

using namespace std;

template<class T>
class Player {
protected:
    string *name{};
    double cash{};
    list<int> dependentCards;
public:
    explicit Player(const string& name="", double cash=1000);
    Player(Player<T> const &player);
    virtual void setName(const string &newName);
    virtual string GetName();
    virtual void addDepCard(int card);
    virtual void addDepCards(const list<int> &card);
    virtual int sumDepCards();
    virtual void addCash(double newCash);
    virtual bool getCash(double newCash);
    virtual Player operator&=(Player<T> &player);
    bool operator == (const Player<T> &player1);
    bool operator < (const Player<T> &player1);
    bool operator > (const Player<T> &player1);
    virtual ~Player();

};




#endif //ASSIGNMENT1_PLAYER_H
