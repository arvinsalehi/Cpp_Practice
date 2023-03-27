//
// Created by arvin on 2023-03-15.
//

#ifndef ASSIGNMENT1_CARDGAME_H
#define ASSIGNMENT1_CARDGAME_H

#include <iostream>
#include <iomanip>
#include "CardGameAdapter.h"
#include "PlayerYouth.h"
#include "PlayerAdult.h"
#include "utilities.h"

const int NUM = 2;

template<typename T>
class CardGame : public CardGameAdapter {
    Player<T> *player[NUM]{};

public:
    CardGame();

    void setMode(int mode) override;

    int bettingStage();

    ~CardGame() override;

    void run() override;
};

template<typename T>
int CardGame<T>::bettingStage() {
    int betAmount = 0;
    bool betStage = true;
    cout << "How much do you both want to bet (min$10, max $300)? $";
    cin >> betAmount;
    betAmount = betVal(betAmount);
    for (int i = 0; i < NUM - 1; ++i) {
        char addMoney;
        double cash;
        if (this->player[i]->getCash() > betAmount && this->player[i + 1]->getCash() > betAmount) break;
        if (this->player[i]->getCash() < betAmount) {

            cout << this->player[i]->GetName() << " don't have the money" << endl;
            std::cout << "Do you want to deposit more money? [Y/N] ";
            std::cin >> addMoney;

            if (addMoney == 'Y' || addMoney == 'y') {
                cout << "Enter the amount of deposit: ";
                cin >> cash;
                this->player[i]->addCash(cash);
            } else {
                break;
            }
        };
        if (this->player[i + 1]->getCash() < betAmount) {

            cout << this->player[i + 1]->GetName() << " don't have the money" << endl;
            std::cout << "Do you want to deposit more money? [Y/N] ";
            std::cin >> addMoney;

            if (addMoney == 'Y' || addMoney == 'y') {
                cout << "Enter the amount of deposit: ";
                cin >> cash;
                this->player[i + 1]->addCash(cash);
            } else {
                break;
            }
        }
    }
    return betAmount;
}

template<class T>
CardGame<T>::CardGame() : CardGameAdapter() {
    this->player[0] = new PlayerYouth<T>("Noah");
    this->player[1] = new PlayerAdult<T>("Kenneth");
}

template<typename T>
void CardGame<T>::setMode(int mode) {
    CardGameAdapter().setMode(mode);
}


template<typename T>
void CardGame<T>::run() {
    const int MAX = 21;
    int betAmount = 0;
    int pot = 0;

    bool gameOver = false;
    do {
        betAmount = bettingStage();
        for (int i = 0; i < NUM; ++i) {
            int depCard = 0;
            T attCard = 0;


            pot += betAmount;
            // Prompt the player for the number of dependent cards

            this->player[i]->addCash(-betAmount);
            cout << this->player[i]->GetName() << " Enter the number of dependent cards: ";
            cin >> depCard;
            this->player[i]->addDepCards(depCard);

            // Prompt the player for the number of attack cards

            cout << this->player[i]->GetName() << " Enter the number of attack cards: ";
            cin >> attCard;
            this->player[i]->addAttCards(attCard);


            // Report the player's name and the sum of the player's cards
            this->player[i]->report();
            // Ask the player if (s)he wishes to add a dependent card to the existing list of dependent cards
            char addCard;
            std::cout << this->player[i]->GetName() << " Do you want more dependant card? [Y/N] ";
            std::cin >> addCard;

            if (addCard == 'Y' || addCard == 'y') {
                cout << "Enter the number of dependent cards: ";
                cin >> depCard;
                this->player[i]->addDepCards(depCard);
            }
            // Report the player's name and the sum of the player's cards
            this->player[i]->report();
            // Ask the player if (s)he wishes to add an attack card to the existing list of attack cards
            std::cout << this->player[i]->GetName() << " Do you want more attack card? [Y/N]  ";
            std::cin >> addCard;
            if (addCard == 'Y' || addCard == 'y') {
                cout << "Enter the number of attack cards: ";
                cin >> attCard;
                this->player[i]->addAttCards(attCard);
            }
            // Report the player's name and the sum of the player's cards
            this->player[i]->report();

            cout << endl;
        }

        //Determine a winner

        // If a player has a sum over the limit of 21, the player is disqualified. Print the player's name,
        // the sum of the player's cards, and a message that states this is over the limit.
        // Apply this test to both players

        for (auto &p: this->player) {
            p->report();
            if (p->sumCards() > 21) {
                p->setState(true);
            }
        }
        cout << endl;

        for (int i = 0; i < NUM - 1; i++) {
            // If both players are disqualified, print that both players are over the limit and have been disqualified.
            // If just player 1 is disqualified, print player 1's name and a message that (s)he has been disqualified
            // for going over the limit. Print player 2's name and indicate that (s)he has won.
            // Move the amount that was bet away from player 1 and towards player 2. Or vice versa

            if (this->player[i]->getState() == true && this->player[i + 1]->getState() == true) {
                cout << "both players are over the limit and have been disqualified." << endl;
            } else if (this->player[i]->getState() == true && this->player[i + 1]->getState() == false) {
                cout << this->player[i]->GetName() << " is over the limit and have been disqualified." << endl;
                cout << this->player[i + 1]->GetName() << " has won." << endl;
                this->player[i + 1]->addCash(pot);
            } else if (this->player[i]->getState() == false && this->player[i + 1]->getState() == true) {
                cout << this->player[i + 1]->GetName() << " is over the limit and have been disqualified." << endl;
                cout << this->player[i]->GetName() << " has won." << endl;
                this->player[i]->addCash(pot);
            } else if (this->player[i] == this->player[i + 1]) {
                cout << "both players drew the same number of points and there is no winner" << endl;
                this->player[i]->addCash(betAmount);
                this->player[i + 1]->addCash(betAmount);
            } else if (this->player[i] > this->player[i + 1]) {
                cout << this->player[i]->GetName() << " has won with more points." << endl;
                this->player[i]->addCash(pot);
            } else if (this->player[i] < this->player[i + 1]) {
                cout << this->player[i + 1]->GetName() << " has won with more points." << endl;
                this->player[i + 1]->addCash(pot);
            }
        }

        cout << endl;

        char again;
        std::cout << "Would you like to play again? [Y/N] ";
        cin >> again;
        if (again == 'N' || again == 'n') {
          gameOver = true;
        }

        // Determine whether it is time to quit by checking to see if one player has run out of cash.
    } while (!gameOver);

    cout << "The game is over." << endl;

    // Print out the final report for each player. Give the player's name and the player's cash.
    for (auto &p: this->player) {
        cout << p->GetName() << " has " << "$" << std::fixed << std::setprecision(2) << p->getCash() << endl;
    }
    // Be sure to print the cash to two decimal places.
    // Be sure to clean up before finishing the program.
    delete this->player[0];
    delete this->player[1];


}

template<typename T>
CardGame<T>::~CardGame() = default;

CardGameAdapter *cardGame() {
    char ldMode;
    std::cout << "Would you like to play in low definition mode? [Y/N] ";
    std::cin >> ldMode;

    CardGameAdapter *cardGame;//MW: Note that CardGameAdapter is not templated but CardGame is
    if (ldMode == 'Y' || ldMode == 'y') {
        cardGame = new CardGame<int>();
        cardGame->setMode(1);//MW: You might need to set a mode flag when you come to run the game.
        //    It is best to use an enumeration for this, not a magic number as I have here
    } else {
        std::cout << "You will be playing in high definition mode." << std::endl;
        cardGame = new CardGame<double>();
        cardGame->setMode(2);//MW: You might need to set a mode flag when you come to run the game.
        //    It is best to use an enumeration for this, not a magic number as I have here
    }
    return cardGame;
}

#endif //ASSIGNMENT1_CARDGAME_H
