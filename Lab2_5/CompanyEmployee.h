//
// Created by arvin on 2023-02-20.
//

#ifndef LAB2_5R_COMPANYEMPLOYEE_H
#define LAB2_5R_COMPANYEMPLOYEE_H
#include <vector>
#include "CompanyCommon.h"
class CompanyEmployee {
public:
    std::vector<StandardEmployee> standardEmployees{};

    CompanyEmployee();
    bool AddPersonnel(int num);

    bool FindPersonnel(const std::string& name, StandardEmployee& ref);
    int FindPersonnelIndex(const std::string& name);
    double CalculateSalary(const std::string& name);
    ~CompanyEmployee();
};
#endif //LAB2_5R_COMPANYEMPLOYEE_H
