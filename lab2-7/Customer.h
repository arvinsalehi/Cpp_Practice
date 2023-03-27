//Customer.h - Class declaration for the customer

#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>

class Customer {
    std::string name;
    std::string lastname;
    std::string address;
    int number{};
    long long int cell{};

public:
    enum class Err_Status {
        Err_Success,
        Err_InvalidData,
        Err_ResourceNotAvailable
    };

    explicit Customer(int number);

    explicit Customer(std::string name, std::string lastname, std::string address, int number, long long int cell);

    std::string GetName();

    std::string GetAddress();

    int GetNumber() const;

    long long int GetCell() const;

    void GetInfo();

    Err_Status setName(std::string name);

    Err_Status SetAddress(std::string address);

    Err_Status SetNumber(long long int number);

    void ZeroData();

    ~Customer();

    Customer();
};

#endif// _CUSTOMER_H_