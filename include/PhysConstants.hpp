#include <map>
#include <string>

class Constant {
public:
    Constant(){};
    Constant(double value, double error, std::string units);
    ~Constant(){};

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
    
    Constant GetConstant(const std::string &name);
private:
    void Init(void);
    void SetConstant(const std::string &name,  const double &val,
                     const double &error, const std::string &unit);

    std::map<std::string, Constant> consts_;
};//class PhysConstants

