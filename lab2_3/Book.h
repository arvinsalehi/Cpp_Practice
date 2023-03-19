//
// Created by arvin on 2023-02-06.
//

#ifndef LAB2_3_BOOK_H
#define LAB2_3_BOOK_H

#include <iostream>
#include <string>
#include <list>
#include "GenericType.h"

using namespace std;
class Book : GenericType {
private:
    std::string  _title;
    static int _numAuthors;
    std::string* _authors{};
    double _price{};

public:
    Book();
    Book(const std::string& title, int numberOfAuthors, double price);
    double CalculateCost();
    void GetInfo() const;
    friend std::ostream& operator<<(std::ostream& out, Book& book);
    ~Book();
};
#endif //LAB2_3_BOOK_H
