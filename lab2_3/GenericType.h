//
// Created by arvin on 2023-02-11.
//

#ifndef LAB2_3_GENERICTYPE_H
#define LAB2_3_GENERICTYPE_H

#include <iostream>
#include <string>
#include <list>


using namespace std;
class GenericType {
protected:
    std::string  _title;
    int _numAuthors;
    std::string* _authors{};
    double _price{};
public:
    GenericType();
    GenericType(const std::string& title, int numberOfAuthors, double price);
    double CalculateCost(double percentage);
    string GetAuthors() const;
    void GetInfo(const std::string& message="") const ;

    ~GenericType();

};

#endif //LAB2_3_GENERICTYPE_H
