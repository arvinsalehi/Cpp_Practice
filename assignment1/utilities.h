//
// Created by arvin on 2023-03-24.
//

#ifndef ASSIGNMENT1_UTILITIES_H
#define ASSIGNMENT1_UTILITIES_H
#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <random>

template<typename T>
T generateRandomNumber(T min, T max, bool floatNumber = false) {
    if (floatNumber) {
        float randomFloat = (min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min))));
        return static_cast<T>(randomFloat);
    } else {
        return static_cast<T>(min + (rand() % static_cast<int>(max - min + 1)));
    }
}


int betVal(int val) {
    int minVal = 10;
    int maxVal = 300;

    if (val < minVal) return minVal;
    else if (val > maxVal) return maxVal;
    return val;
}
#endif //ASSIGNMENT1_UTILITIES_H
