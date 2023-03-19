//
// Created by arvin on 2023-02-06.
//
#include "DigitalMusic.h"

DigitalMusic::DigitalMusic() : GenericType() {}

DigitalMusic::DigitalMusic(const string &title, int numberOfAuthors, double price) : GenericType(
        title, numberOfAuthors, price) {}

double DigitalMusic::CalculateCost() {
    /// Calculate price if needed and return it
    // 13% of the price for the harmonized sales tax
    return GenericType::CalculateCost(.13);
}

void DigitalMusic::GetInfo() const {
    GenericType::GetInfo();
}

std::ostream &operator<<(ostream &out, DigitalMusic &digitalMusic) {
    digitalMusic.GetInfo();
    return out;
}

DigitalMusic::~DigitalMusic() = default;

