#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include "package.h"

class OvernightPackage : public Package
{
private:
    double fee;

public:
    OvernightPackage(const std::string &sendersName, const std::string &sendersAddress, const std::string &sendersCity, const std::string &sendersState, const std::string &sendersZipcode, const std::string &recipientsName, const std::string &recipientsAddress, const std::string &recipientsCity, const std::string &recipientsState, const std::string &recipientsZipcode, double weight, double costPerOunce, double overnightFee = 0.0);
    void setFee(double);
    double getFee() const;
    double calculateCost() const;
};
#endif