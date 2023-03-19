//
// Created by arvin on 2023-03-15.

#include "CardGameAdapter.h"


CardGameAdapter::CardGameAdapter() {
 gameMode = lowDef;
}

void CardGameAdapter::setMode(int mode) {
    switch (mode) {
        default:
        case 1:
            gameMode = lowDef;
            break;
        case 2:
            gameMode = highDef;
            break;
    }
}

void CardGameAdapter::run() {

}
CardGameAdapter::~CardGameAdapter() = default;

