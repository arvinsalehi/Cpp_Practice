//
// Created by arvin on 2023-02-06.
//

#ifndef LAB2_3_DIGITALMUSIC_H
#define LAB2_3_DIGITALMUSIC_H
#include <iostream>
#include <string>
#include <list>
#include "GenericType.h"


using namespace std;
class DigitalMusic : GenericType {

public:
    DigitalMusic();
    DigitalMusic(const std::string& title, int numberOfAuthors, double price);
    double CalculateCost();
    void GetInfo() const;
    friend std::ostream& operator<<(std::ostream& out, DigitalMusic& digitalMusic);
    ~DigitalMusic();
};
#endif //LAB2_3_DIGITALMUSIC_H
