//
// Created by arvin on 2023-02-21.
//
#include "CompanyEmployee.h"

CompanyEmployee::CompanyEmployee() = default;;

bool CompanyEmployee::AddPersonnel(int num) {
    if (this->standardEmployees.size() + num > MAX_SIZE || num == 0) {
        return false;
    }

    for (int i = 0; i < num; ++i) {

        StandardEmployee standardEmployee;
        std::cout << "Enter the employee's name:" << std::endl;
        std::cin >> standardEmployee.name;

        std::cout << "Enter the employee's position:" << std::endl;
        std::cin >> standardEmployee.position;

        std::cout << "Enter the employee's base salary:" << std::endl;
        std::cin >> standardEmployee.baseSalary;

        std::cout << "Enter the employee's annual stock option dividend:" << std::endl;
        std::cin >> standardEmployee.profitSharing;

        std::cout << "Enter the employee's annual perquisites:" << std::endl;
        std::cin >> standardEmployee.performanceBonus;
        standardEmployee.salary =
                standardEmployee.baseSalary + standardEmployee.profitSharing + standardEmployee.performanceBonus;
        this->standardEmployees.emplace_back(standardEmployee);

    }
    return true;
}

bool CompanyEmployee::FindPersonnel(const std::string &name, StandardEmployee& ref) {
    for (auto & standardEmployee : this->standardEmployees) {
        if (standardEmployee.name == name) {

            ref.name = name;
            ref.position = standardEmployee.position;

            return true;
        }
    }
    return false;
}
int CompanyEmployee::FindPersonnelIndex(const std::string &name) {

    for (int i = 0;  i < this->standardEmployees.size() ; ++i) {
        if (this->standardEmployees[i].name == name) {
            return i;
        }
    }
    return -1;
}
double CompanyEmployee::CalculateSalary(const std::string &name) {
    int retVal = this->FindPersonnelIndex(name);
    if (retVal != -1) {
        return this->standardEmployees[retVal].salary;
    }
    return 0.00;
}




CompanyEmployee::~CompanyEmployee() = default;

