//CustomerBase.cpp - The main function for a map of customers

#include <map>
#include <cstdio>
#include "Customer.h"

using namespace std;

int main() {
    map<long long int, Customer> customerMap;
    char firstname[] = "Aaaa";
    char lastname[] = "Bbbb";
    int streetNo = 0;
    char streetname[] = "Cccc";
    long long int phoneNo = 1111111110;

    //Build a database of 160,000 entries
    for (int i = 0; i < 20; ++i) {
        ++firstname[0];
        ++lastname[0];
        ++streetname[0];
        firstname[1] = 'a';
        lastname[1] = 'b';
        streetname[1] = 'c';
        for (int j = 0; j < 20; ++j) {
            ++firstname[1];
            ++lastname[1];
            ++streetname[1];
            firstname[2] = 'a';
            lastname[2] = 'b';
            streetname[2] = 'c';
            for (int k = 0; k < 20; ++k) {
                ++firstname[2];
                ++lastname[2];
                ++streetname[2];
                ++streetNo;
                firstname[3] = 'a';
                lastname[3] = 'b';
                streetname[3] = 'c';
                for (int l = 0; l < 20; ++l) {
                    ++firstname[3];
                    ++lastname[3];
                    ++streetname[3];
                    ++phoneNo;
                    char name[16];
                    char addr[32];
                    std::snprintf(name, 16, "%s %s", firstname, lastname);
                    std::snprintf(addr, 32, "%d %s Drive", streetNo, streetname);
//					cout << name << " " << addr << " " << phoneNo << endl;
                    Customer customer = Customer(firstname, lastname, streetname, i + j + k + l, phoneNo);
                    customerMap[phoneNo] = customer;
                }
            }
        }
    }


    auto it = customerMap.find(1111112222);
    if (it != customerMap.end()) {
        customerMap[1111112222].GetInfo();
        customerMap.insert({9051112222, it->second});
        customerMap[9051112222].setName("Darryl Smith");
        customerMap[9051112222].SetNumber(9051112222);
        customerMap[9051112222].SetAddress("1 Bloor Street");
        customerMap.erase(it);
        customerMap[9051112222].GetInfo();
    } else cout << " : Not found" << endl;

    it = customerMap.find(1111112222);
    if (it == customerMap.end()) cout << "Cannot find the customer" << endl;

    // Get an iterator pointing to the first element in the map
    it = customerMap.begin();

    // Iterate through the map and print the elements
    while (it != customerMap.end()) {
        it->second.ZeroData();
        ++it;
    }

    it = customerMap.find(1111112222);
    if (it == customerMap.end()) cout << "Cannot find the customer" << endl;

    return 0;
}
