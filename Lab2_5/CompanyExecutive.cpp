//
// Created by arvin on 2023-02-20.
//
#include "CompanyExecutive.h"

CompanyExecutive::CompanyExecutive() = default;

bool CompanyExecutive::AddPersonnel(int num) {

    if (this->executiveEmployees.size() + num > MAX_SIZE) {
        return false;
    }

    for (int i = 0; i < num; ++i) {
        ExecutiveEmployee executiveEmployee;
        std::cout << "Enter the executive's name:" << std::endl;
        std::cin >> executiveEmployee.name;

        std::cout << "Enter the executive's position:" << std::endl;
        std::cin >> executiveEmployee.position;

        std::cout << "Enter the executive's base salary:" << std::endl;
        std::cin >> executiveEmployee.baseSalary;

        std::cout << "Enter the executive's annual stock option dividend:" << std::endl;
        std::cin >> executiveEmployee.stockOptionDividend;

        std::cout << "Enter the executive's annual perquisites:" << std::endl;
        std::cin >> executiveEmployee.perquisites;
        executiveEmployee.salary =
                executiveEmployee.baseSalary + executiveEmployee.stockOptionDividend + executiveEmployee.perquisites;
        this->executiveEmployees.emplace_back(executiveEmployee);
    }

    return true;
}
bool CompanyExecutive::FindPersonnel(const std::string &name, ExecutiveEmployee &ref) {
    for (auto & executiveEmployee : this->executiveEmployees) {
        if (executiveEmployee.name == name) {

            ref.name = name;
            ref.position = executiveEmployee.position;

            return true;
        }
    }
    return false;
}

int CompanyExecutive::FindPersonnelIndex(const std::string &name) {

    for (int i = 0;  i < this->executiveEmployees.size() ; ++i) {
        if (this->executiveEmployees[i].name == name) {
            return i;
        }
    }
    return -1;
}
double CompanyExecutive::CalculateSalary(const std::string &name) {
    int retVal = this->FindPersonnelIndex(name);
    if (retVal != -1) {
        return this->executiveEmployees[retVal].salary;
    }
    return 0.00;
}


CompanyExecutive::~CompanyExecutive() = default;

