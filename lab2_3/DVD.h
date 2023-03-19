//
// Created by arvin on 2023-02-06.
//

#ifndef LAB2_3_DVD_H
#define LAB2_3_DVD_H
#include <iostream>
#include <string>
#include <list>
#include "GenericType.h"


using namespace std;
class DVD : GenericType {

public:
    DVD();
    DVD(const std::string& title, int numberOfAuthors, double price);
    double CalculateCost();
    void GetInfo() const;
    friend std::ostream& operator<<(std::ostream& out, DVD& dvd);
    ~DVD();
};
#endif //LAB2_3_DVD_H
