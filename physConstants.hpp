#include <cmath>
#include <string>

class PhysConstants {
public:
    GetValue(std::string &name) {return (name.first()); };
    GetError(std::string &name) {return (name.second()); };
    GetUnit(std::string &name)  {return (name.??); };
private:
    //Some fundamental constants
    const double eleCharge = 1.6022e-19; // C
    const double speedOfLight = 299792458; // m/s
    const double plank = 4.135668e-21; // MeV*s
    const double hbar  = plank/(2*M_PI); // MeV*s
    const double mu0 = 4e-7*M_PI; // Wb/(A*m)
    const double epsilon0 = 1/(speedOfLight*mu0); // F/m
    const double fineStructure = pow(eleCharge,2)/(4*M_PI*hbar*speedOfLight);
    
    //Masses for some of our friends.
    const double electronMass = 0.510998928; // MeV/c**2
    const double protonMass = 938.272046; // MeV/c**2
    const double neutronMass = 939.565378; //MeV/c**2
};//class PhysConstants
