//Customer.cpp - Function definitions for the customer

#include <string>
#include <utility>
#include "Customer.h"

using namespace std;

Customer::Customer(int number) {
    this->number = number;
    this->name = "";
    this->lastname = "";
    this->address = "";
    this->cell = 0;
}

Customer::Customer(std::string name, std::string lastname,std::string address, int number,long long int cell) {
    this->name = std::move(name);
    this->lastname = std::move(lastname);
    this->address = std::move(address);
    this->cell = cell;
    this->number = number;
}

std::string Customer::GetName() {
    return this->name;
}

std::string Customer::GetAddress() {
    return this->address;
}

int Customer::GetNumber() const {
    return this->number;
}

long long int Customer::GetCell() const {
    return this->cell;
}

void Customer::GetInfo() {
    cout << "Name:\t" << this->name << endl
         << "Address:\t" << this->address << endl
         << "Customer Number:" << this->number << endl
         << "Phone Number:\t" << this->cell <<endl;
}

Customer::Err_Status Customer::setName(string newName) {
    if (name.empty()) return Err_Status::Err_InvalidData;
    this->name = std::move(newName);

    return Err_Status::Err_Success;
}

Customer::Err_Status Customer::SetAddress(std::string newAddress) {
    if (address.empty()) return Err_Status::Err_InvalidData;
    this->address = std::move(newAddress);

    return Err_Status::Err_Success;
}

Customer::Err_Status Customer::SetNumber(long long int newNumber) {
    if (newNumber < 0 || newNumber > 9999999999) return Err_Status::Err_InvalidData;
    this->cell = newNumber;
    return Err_Status::Err_Success;
}

void Customer::ZeroData() {
    this->name = "";
    this->address = "";
    this->cell = 0;
    this->number = 0;
}

Customer::Customer() = default;

Customer::~Customer() = default;