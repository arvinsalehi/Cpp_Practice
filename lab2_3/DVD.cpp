//
// Created by arvin on 2023-02-06.
//
#include "DVD.h"

DVD::DVD() : GenericType() {}

DVD::DVD(const string &title, int numberOfAuthors, double price) : GenericType(
        title, numberOfAuthors, price) {}

double DVD::CalculateCost() {
    /// Calculate price if needed and return it
    // 13% of the price for the harmonized sales tax
    return GenericType::CalculateCost(.13);
}

void DVD::GetInfo() const {
    string message = "There is a 5% penalty for using plastic.";
    GenericType::GetInfo(message);
}

std::ostream &operator<<(ostream &out, DVD &dvd) {
    dvd.GetInfo();
    return out;
}

DVD::~DVD() = default;

