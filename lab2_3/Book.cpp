//
// Created by arvin on 2023-02-06.
//
#include "Book.h"

Book::Book() : GenericType() {}

Book::Book(const string &title, int numberOfAuthors, double price) : GenericType(
        title, numberOfAuthors, price) {}

double Book::CalculateCost(){
    /// Calculate price if needed and return it
    //  book will add a 10% penalty to the price for using paper
    //  and 13% of the price for the harmonized sales tax
    return GenericType::CalculateCost(.23);;
}

void Book::GetInfo() const {
    string message = "There is a 10% penalty for using paper.";
    GenericType::GetInfo(message);
}

std::ostream &operator<<(ostream &out, Book &book) {
    book.GetInfo();
    return out;
}

Book::~Book() = default;


