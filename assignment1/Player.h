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
    char *name{};
    double cash{};
    list<int> dependentCards;
public:
    explicit Player(const string& name="", double cash=1000);
    Player(Player const &player);
    virtual void setName(const string &newName);
    virtual string GetName();
    virtual void addDepCard(int card);
    virtual void addDepCards(const list<int> &card);
    virtual int sumDepCards();
    virtual void addCash(double newCash);
    virtual bool getCash(double newCash);
    virtual Player operator&=(Player &player);
    friend  bool operator == (const Player &player1,const Player &player2);
    friend  bool operator < (const Player &player1,const Player &player2);
    friend  bool operator > (const Player &player1,const Player &player2);
    virtual ~Player();

};




#endif //ASSIGNMENT1_PLAYER_H
