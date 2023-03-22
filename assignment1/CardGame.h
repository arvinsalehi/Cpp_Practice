//
// Created by arvin on 2023-03-15.
//

#ifndef ASSIGNMENT1_CARDGAME_H
#define ASSIGNMENT1_CARDGAME_H

#include <iostream>
#include "CardGameAdapter.h"
#include "PlayerYouth.h"
#include "PlayerAdult.h"

const int NUM = 2;

template<typename T>
class CardGame : public CardGameAdapter {
    Player<T> *player[NUM]{};

public:
    CardGame();

    void setMode(int mode) override;

    ~CardGame() override;

    void run() override;
};

CardGameAdapter *cardGame();
#endif //ASSIGNMENT1_CARDGAME_H
