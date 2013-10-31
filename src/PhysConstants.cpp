/*
* Copyright S.V. Paulauskas 2012
* stanpaulauskas@gmail.com
* Distributed under GNU General Public Licence v3
*/

/*! \file PhysConstants.cpp
 *  \brief A class to handle physical constants
 *  \author S.V. Paulauskas
 *  \date 09 November 2012
 */
#include <fstream>
#include <iostream>
#include <cmath>

#include "PhysConstants.hpp"

using namespace std;

Variable PhysConstants::GetConstant(const std::string &name){
    map<std::string, Variable>::iterator it = 
        consts_.find(name);
    
    if(it == consts_.end()) {
        cout << endl << "Couldn't find " << name << "." 
             << "Maybe you got the name wrong, or think about failing that." 
             << endl;
    }
    return((*consts_.find(name)).second);
}

void PhysConstants::SetConstant(const std::string &name,  const double &val,
                 const double &error, const std::string &unit) {
    consts_.insert(make_pair(name, Variable(val, error,unit)));
}

void PhysConstants::Init(void){
    //Conversions
    SetConstant("eVtoJ", 1.602176565e-19, 0.000000035e-19, "J");

    //masses
    SetConstant("alphaMass", 3727.379240, 0.000082, "MeV/c^2");
    SetConstant("deuteronMass", 1875.612859, 0.000041, "MeV/c^2");
    SetConstant("electronMass", 0.510998928, 0.000000011, "MeV/c^2");
    SetConstant("helionMass", 2808.391482, 0.000062, "MeV/c^2");
    SetConstant("muonMass", 105.6583715, 0.0000035, "MeV/c^2");
    SetConstant("neutronMass", 939.565379, 0.000021, "MeV/c^2");
    SetConstant("protonMass", 938.272046, 0.000021, "MeV");
    SetConstant("tauMass", 1776.82, 0.16 , "MeV/c^2");
    SetConstant("tritonMass", 2808.921005, 0.000062, "MeV/c^2");

    //General
    SetConstant("angstromStar",1.00001495e-10, 0.00000090e-10, "m");
    SetConstant("avogadroNumber", 6.02214129e23, 0.00000027e23, "1/mol");
    SetConstant("bohrMagneton", 927.400968e-26, 0.000020e-26, "J/T");
    SetConstant("bohrRadius", 0.52917721092e-10, 0.00000000017e-10, "m");
    SetConstant("boltzmann", 8.6173324e-5, 0.0000078e-5, "eV/K");
    SetConstant("c", 299792458, 0.0, "m/s");
    SetConstant("electronCharge", 1.602176565e-19, 3.5e-27,"C");
    SetConstant("epsilon0", 1/(299792458*4e-7*M_PI), 0.0, "F/m");
    SetConstant("faraday", 96485.3365, 0.0021, "C/mol");
    SetConstant("fermiCoupling", 1.166364e-5, 0.000005e-5, "GeV^-2");
    SetConstant("fineStructure", 7.2973525698e-3, 0.0000000024e-3, "none");
    SetConstant("g", 9.80665, 0.0, "m/s^2");
    SetConstant("G", 6.67384e-11, 0.00080e-11, "m^3*kg^-1*s^-2");
    SetConstant("h", 4.135667516e-15, 0.000000091e-15, "eV*s");
    SetConstant("hbar", 6.58211928e-16, 0.00000015e-16, "eV*s");
    SetConstant("josephson", 483597.870e9, 0.011e9, "Hz/V");
    SetConstant("mu0", 4e-7*M_PI, 0.0, "V*s/(A*m)");
    SetConstant("rydberg", 1.0973731568539e7, 0.0000000000055e-7, "1/m");
    SetConstant("stephan-boltzmann", 5.670373e-8, 0.000021e-8, "W*m^-2*K^-4");
}

Variable::Variable(const double &value, const double &error, 
                   const std::string &units){
    value_ = value;
    error_ = error;
    units_ = units;
}
