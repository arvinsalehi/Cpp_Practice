//
// Created by arvin on 2023-03-15.
//

#ifndef ASSIGNMENT1_CARDGAMEADAPTER_H
#define ASSIGNMENT1_CARDGAMEADAPTER_H

class CardGameAdapter {
protected:
    const int MAX = 21;
    enum GameMode {
        lowDef, highDef
    } gameMode;
public:
    CardGameAdapter();
    virtual void setMode(int);
    virtual void run();
    virtual ~CardGameAdapter();
};

//CardGame is templated and is derived from CardGameAdapter and can be run through a pointer to CardGameAdapter.

//CardGame might have a factory function to generate one of two games. It might be implemented something like:


#endif //ASSIGNMENT1_CARDGAMEADAPTER_H
