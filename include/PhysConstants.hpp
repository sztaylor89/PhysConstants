/*
* Copyright S.V. Paulauskas 2012
* stanpaulauskas@gmail.com
* Distributed under GNU General Public Licence v3
*/

/*! \file PhysConstants.hpp
 *  \brief A class to handle physical constants
 *  \author S.V. Paulauskas
 *  \date 09 November 2012
 */
#include <map>
#include <string>

class Variable {
public:
    Variable(){};
    Variable(const double &value, const double &error, 
             const std::string &units);
    ~Variable(){};

    double GetValue(void) {return(value_);};
    double GetError(void) {return(error_);};
    std::string GetUnits(void) {return(units_);};
private:
    double value_, error_;
    std::string units_;
};

class PhysConstants {
public:
    PhysConstants() {Init();};
    ~PhysConstants(){};
    
    Variable GetConstant(const std::string &name);
private:
    void Init(void);
    void SetConstant(const std::string &name,  const double &val,
                     const double &error, const std::string &unit);

    std::map<std::string, Variable> consts_;
};//class PhysConstants

