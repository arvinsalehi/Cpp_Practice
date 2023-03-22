//
// Created by arvin on 2023-03-15.
//

#include "CardGame.h"
#include "PlayerAdult.h"
#include "PlayerYouth.h"

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


    bool gameOver = false;
    do {
        // Prompt the players for the amount they want to bet. It has to be between $10 and $300
        // If they enter a value below $10, set the amount to $10
        // If they enter a value above $300, set the amount to $300

        cout << endl;
        for (int i = 0; i < NUM; ++i) {
            // Prompt the player for the number of dependent cards

            // Prompt the player for the number of attack cards

            // Report the player's name and the sum of the player's cards

            // Ask the player if (s)he wishes to add a dependent card to the existing list of dependent cards

            // Report the player's name and the sum of the player's cards

            // Ask the player if (s)he wishes to add an attack card to the existing list of attack cards

            // Report the player's name and the sum of the player's cards

            cout << endl;
        }

        //Report the name and points for each player

        cout << endl;

        //Determine a winner

        // If a player has a sum over the limit of 21, the player is disqualified. Print the player's name,
        // the sum of the player's cards, and a message that states this is over the limit.
        // Apply this test to both players

        // If both players are disqualified, print that both players are over the limit and have been disqualified.

        // If just player 1 is disqualified, print player 1's name and a message that (s)he has been disqualified
        // for going over the limit. Print player 2's name and indicate that (s)he has won.
        // Move the amount that was bet away from player 1 and towards player 2 using the << and >> operators.

        // If just player 2 is disqualified, print player 2's name and a message that (s)he has been disqualified
        // for going over the limit. Print player 1's name and indicate that (s)he has won.
        // Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.

        // If player 1 and player 2 are tied, print that both players drew the same number of points and that
        // there is no winner. In doing this comparison, use the == operator.

        // If player 1 has more points than player 2, then print the name of player 1 and that (s)he has won.
        // Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.
        // In doing this comparison, use the > operator

        // If player 2 has more points than player 1, then print the name of player 2 and that (s)he has won.
        // Move the amount that was bet away from player 1 and towards player 2 using the << and >> operators.
        // In doing this comparison, use the < operator

        cout << endl;

        //Report the name and cash for each

        cout << endl;

        // Determine whether it is time to quit by checking to see if one player has run out of cash.
    } while (!gameOver);

    cout << "The game is over." << endl;

    // Print out the final report for each player. Give the player's name and the player's cash.
    // Be sure to print the cash to two decimal places.
    // Be sure to clean up before finishing the program.


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