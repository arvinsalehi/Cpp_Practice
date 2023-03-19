#include "House.h"
#include <iostream>
#include <cstring>
#include <iomanip>

#define CRT_SECURE_NO_WARNINGS

House::House() {
    owner = nullptr;
    address = nullptr;
    rooms = 0.0;
    bathrooms = 0.0;
    price = 0.0;
}

House::House(const char *_owner, const char *_address, const double _rooms, const double _bathrooms,
             const double _price) {

    owner = strdup(_owner);
    address = strdup(_address);
    rooms = _rooms;
    bathrooms = _bathrooms;
    price = _price;
}


House::House(House&& house) noexcept {
    *this = house;
    house.owner = strdup("none");
    house.address = strdup("none");
    house.rooms = 0;
    house.bathrooms = 0.0;
    house.price = 0.0;
}

House &House::operator=(House&& house) noexcept {
    if (this != &house) {//don't move to yourself
        //shallow copies
        owner = house.owner;
        address = house.address;

        //take control of the resource on the rhs
        rooms = house.rooms;
        bathrooms = house.bathrooms;
        price = house.price;

        house.owner = strdup("none");
        house.address = strdup("none");
        house.rooms = 0;
        house.bathrooms = 0.0;
        house.price = 0.0;
    }

    return *this;
}

bool House::ChangePrice(double newPrice) {
    bool val = false;
    if (newPrice > 0.0) {
        this->price = newPrice;
        val = true;
    }
    return val;
}


House &House::operator=(const House &house) {//copy assignment
    if (this != &house) {//don't copy to yourself
        //shallow copies

        owner = house.owner;
        address = house.address;
        rooms = house.rooms;
        bathrooms = house.bathrooms;
        price = house.price;
    }

    return *this;
}

bool House::ChangeOwner(char *newOwner) {
    bool val = false;
    if (newOwner != nullptr) {
        this->owner = newOwner;
        val = true;
    }
    return val;
}

House::House(const House &house) {
    if (this != &house) {//don't copy to yourself
        //shallow copies

        owner = house.owner;
        address = house.address;
        rooms = house.rooms;
        bathrooms = house.bathrooms;
        price = house.price;

    }
}

void House::DisplayInfo() const {
    std::cout << "Owner:\t" << owner << std::endl << "Address:\t"
              << address << std::endl << "Rooms:\t" << this->rooms << std::endl << "Bathrooms:\t"
              << this->bathrooms
              << std::endl << "Price:\t" <<  std::fixed << std::setprecision(2) <<this->price << std::endl << "------------------------------------"
              << std::endl;
}

void House::operator+=(double amount) {
    this->price += amount;
}

bool House::operator==(const House &house2) {
    bool val = false;
    if (this->owner == house2.owner) {
        val = true;
    }
    return val;
}

void House::operator>>(House& house) {
    house = *this;//will invoke the move assignment
    this->owner = strdup("none");
    this->address = strdup("none");
    this->rooms = 0;
    this->bathrooms = 0.0;
    this->price = 0.0;
}




House::~House() = default;




