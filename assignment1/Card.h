//
// Created by arvin on 2023-03-10.
//

#ifndef ASSIGNMENT1_CARD_H
#define ASSIGNMENT1_CARD_H

template<class T>
class Card {
protected:
    T value;
public:
    Card() {
        if (std::is_same<T, int>::value) {
            value = 0;
        } else {
            value = 0.00;
        }
    }

    virtual T genCard(int range_s, int range_e);
    virtual T drawCard() = 0;
};

template<class T>
T Card<T>::genCard(int range_s, int range_e) {
    return nullptr;
}

#endif //ASSIGNMENT1_CARD_H
