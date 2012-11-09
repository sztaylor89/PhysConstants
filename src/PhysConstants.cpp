#include <fstream>
#include <iostream>
#include <cmath>

#include "PhysConstants.hpp"

using namespace std;

Constant PhysConstants::GetConstant(const std::string &name){
    map<std::string, Constant>::iterator it = 
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
    consts_.insert(make_pair(name, Constant(val, error,unit)));
}



void PhysConstants::Init(void){
    SetConstant("alphaParticleMass", 6.64465675e-27, 0.00000029e-27, "kg");
    SetConstant("alphaParticleMassEnergy", 3727.379240, 0.000082, "MeV");
    SetConstant("angstromStar",1.00001495e-10, 0.00000090e-10, "m");
    SetConstant("avogadroNumber", 6.02214129e23, 0.00000027e23, "1/mol");
    SetConstant("bohrMagneton", 927.400968e-26, 0.000020e-26, "J/T");
    SetConstant("bohrRadius", 0.52917721092e-10, 0.00000000017e-10, "m");
    SetConstant("boltzmann", 8.6173324e-5, 0.0000078e-5, "eV/K");
    SetConstant("c", 299792458, 0.0, "m/s");
    SetConstant("deuteronMass", 1875.612859, 0.000041, "MeV");
    SetConstant("electronCharge", 1.602176565e-19, 3.5e-27,"C");
    SetConstant("electronMass", 0.510998928, 0.000000011, "MeV");
    SetConstant("faraday", 96485.3365, 0.0021, "C/mol");
    SetConstant("fermiCoupling", 1.166364e-5, 0.000005e-5, "GeV^-2");
    SetConstant("fineStructure", 7.2973525698e-3, 0.0000000024e-3, "none");
    SetConstant("helionMass" 2808.391482, 0.000062, "MeV");
    SetConstant("josephson", 483597.870e9, 0.011e9, "Hz/V");
    SetConstant("muonMass", 105.6583715, 0.0000035, "MeV");

    //Conversions
    SetConstant("eVtoJ", 1.602176565e-19, 0.000000035e-19, "J");
    

    
    //    const double plank = 4.135668e-21; // MeV*s
//     const double hbar  = plank/(2*M_PI); // MeV*s
//     const double mu0 = 4e-7*M_PI; // Wb/(A*m)
//     const double epsilon0 = 1/(speedOfLight*mu0); // F/m
//     const double fineStructure = pow(eleCharge,2)/(4*M_PI*hbar*speedOfLight);
    
//     //Masses for some of our friends.
//     const double electronMass = 0.510998928; // MeV/c**2
//     const double protonMass = 938.272046; // MeV/c**2
//     const double neutronMass = 939.565378; //MeV/c**2
}

Constant::Constant(double value, double error, std::string units) {
    value_ = value;
    error_ = error;
    units_ = units;
}
