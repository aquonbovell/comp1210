#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "package.h"

class TwoDayPackage : public Package
{
private:
    double fltFee;

public:
    TwoDayPackage(const std::string &sendersName, const std::string &sendersAddress, const std::string &sendersCity, const std::string &sendersState, const std::string &sendersZipcode, const std::string &recipientsName, const std::string &recipientsAddress, const std::string &recipientsCity, const std::string &recipientsState, const std::string &recipientsZipcode, double weight, double costPerOunce, double flatfee=0.0);
    void setFlatFee(double);
    double getFlatFee() const;
    double calculateCost() const;
};
#endif