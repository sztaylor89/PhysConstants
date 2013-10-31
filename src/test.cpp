#include <iostream>

#include "PhysConstants.hpp"

using namespace std;

int main () {
    PhysConstants constants;
    Variable electronCharge = constants.GetConstant("electronCharge");

    double chg = constants.GetConstant("electronCharge").GetValue();

    cout << chg << " " << endl;
    std::cout << electronCharge.GetValue() << " " << electronCharge.GetError() 
              <<  " " << electronCharge.GetUnits() << endl;
}
