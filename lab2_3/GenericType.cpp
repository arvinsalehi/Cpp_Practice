//
// Created by arvin on 2023-02-11.
//
#include "GenericType.h"
#include <iomanip>

GenericType::GenericType() {
    _title = "";
    _authors = nullptr;
    _numAuthors = 0;
    _price = 0.00;
}

GenericType::GenericType(const string &title, int numberOfAuthors, double price) {
    this->_title = title;
    GenericType::_numAuthors = numberOfAuthors;
    this->_authors = new std::string[numberOfAuthors];
    this->_price = price;
}

double GenericType::CalculateCost(double percentage)  {
    /// Calculate price if needed and return it
    this->_price += this->_price * percentage; //
    return this->_price;
}

string GenericType::GetAuthors() const {
    string authorsList;
    for (int i = 0; i < _numAuthors ; ++i) {
        authorsList = _authors[i] + ",";
    }
    return authorsList;
}


void GenericType::GetInfo(const std::string &message) const {
    cout <<  endl << "title:\t" << this->_title<<
    endl << "number of authors:\t" << GenericType::_numAuthors <<
    endl << "authors: \t" << this->GetAuthors() <<
    endl << "price:\t" << _price <<
    endl << message << endl;
}



GenericType::~GenericType() = default;

