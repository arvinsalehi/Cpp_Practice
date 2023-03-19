#include "House.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
House::House(){
	owner = nullptr;
	address = nullptr;
	rooms = 0.0;
	bathrooms = 0.0;
	price = 0.0;
}
House::House(const char* _owner, const char* _address, const double _rooms, const double _bathrooms, const double _price)
{
    int length = strlen(_owner) + 1;
    owner = new char[length];
    strcpy(owner, _owner);

    length = strlen(_address) + 1;
    address = new char[length];
    strcpy(address, _address);

    rooms = _rooms;
    bathrooms = _bathrooms;
    price = _price;
}



House::House(House&& house) noexcept{
    *this = std::move(house);
}

House& House::operator=(House&& house) noexcept
{
	if (this != &house) {//don't move to yourself
		//shallow copies
		owner = house.owner;
		address = house.address;
		
		//remove existing resource
		
		//take control of the resource on the rhs
		rooms = house.rooms;
		bathrooms = house.bathrooms;
		price = house.price;
		delete[] owner;
		delete[] address;
		//Put the rhs into an empty state
		
		rooms = 0;
		bathrooms = 0;
		price = 0;
	}

	return *this;
}

bool House::ChangePrice(double newPrice)
{
	price = newPrice;
	return true;
}

House& House::operator=(const House& house) {//copy assignment
	if (this != &house) {//don't copy to yourself
		//shallow copies
		

		owner = house.owner;
		address = house.address;
		rooms = house.rooms;
		bathrooms = house.bathrooms;
		price = house.price;

		delete[] owner;
		delete[] address;
		rooms = 0;
		bathrooms = 0;
		price = 0;
	}

	return *this;
}

bool ChangeOwner(char* newOwner) {
	this->owner = newOwner;
	return true;
}







