//CompanyCommon.h - structures and functions for the company database

#ifndef _COMPANYBASE_H_
#define _COMPANYBASE_H_

#include <iostream>
#include <string>

struct StandardEmployee {
    std::string name;
    std::string position;
    double baseSalary;
    double profitSharing;
    double performanceBonus;
    double salary;
};

struct ExecutiveEmployee {
    std::string name;
    std::string position;
    double baseSalary;
    double stockOptionDividend;
    double perquisites;//Executive perquisites or "perks" constitute additional compensation for senior executives which are not available to other salaried employees.
    double salary;
};

//Implement the functions AddPersonnel(), FindPersonnel() and CalculateSalary() here.
template <typename T> bool AddPersonnel(T& database, int num) {
    return database.AddPersonnel(num);
}

template <typename T, typename U> bool FindPersonnel(T database, std::string name, U& ref) {
    return database.FindPersonnel(name, ref);
}
template <typename T> double CalculateSalary(T database, std::string name) {
    return database.CalculateSalary(name);
}
const int MAX_SIZE = 1000;
//These should work for either type of database.


#endif// _COMPANYBASE_H_