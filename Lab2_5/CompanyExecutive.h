//
// Created by arvin on 2023-02-20.
//

#ifndef LAB2_5R_COMPANYEXECUTIVE_H
#define LAB2_5R_COMPANYEXECUTIVE_H

#include <vector>
#include "CompanyCommon.h"
class CompanyExecutive {
    std::vector<ExecutiveEmployee> executiveEmployees;
public:
    CompanyExecutive();
    bool AddPersonnel(int num);
    bool FindPersonnel(const std::string& name, ExecutiveEmployee& ref);
    int FindPersonnelIndex(const std::string& name);
    double CalculateSalary(const std::string& name);
    ~CompanyExecutive();
};
#endif //LAB2_5R_COMPANYEXECUTIVE_H
