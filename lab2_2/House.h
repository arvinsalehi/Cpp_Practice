//House.h - class declaration for a house

#include <iosfwd>

#ifndef _HOUSE_H_
#define _HOUSE_H_
#define CRT_SECURE_NO_WARNINGS


class House {
    char *owner{};
    char *address{};
    double rooms{};
    double bathrooms{};
    double price{};
public:
    House();//Default constructor
    House(const char *_owner, const char *_address, double _rooms, double _bathrooms,
          double _price);//Data for the house object
    House(const House &house);//Copy constructor
    House &operator=(const House &house);//Copy assignment
    House(House &&house) noexcept;//Move constructor
    House &operator=(House &&house) noexcept;//Move assignment
    bool ChangeOwner(char *newOwner); //Change the owner
    bool ChangePrice(double newPrice);//Change the price

    void operator+=(double amount);//increment/decrement the price of the house

    bool operator==(const House &house2);//Do the two houses have the same owner?

    void operator>>(House& house);//Move contents from the house1 object to the house2 object

    void DisplayInfo() const;//Display the owner, address, rooms, bathrooms, and price

    ~House();//Destructor
};


#endif// _HOUSE_H_//
// Created by arvin on 2023-02-01.
//

#ifndef LAB2_2_HOUSE_H
#define LAB2_2_HOUSE_H

#endif //LAB2_2_HOUSE_H
