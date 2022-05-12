#include "overnightpackage.h"

OvernightPackage::OvernightPackage(const std::string &sendersName, const std::string &sendersAddress, const std::string &sendersCity, const std::string &sendersState, const std::string &sendersZipcode, const std::string &recipientsName, const std::string &recipientsAddress, const std::string &recipientsCity, const std::string &recipientsState, const std::string &recipientsZipcode, double weight, double costPerOunce, double overnightFee) : Package(sendersName, sendersAddress, sendersCity, sendersState, sendersZipcode, recipientsName, recipientsAddress, recipientsCity, recipientsState, recipientsZipcode, weight, costPerOunce)
{
    setFee(overnightFee);
}

void OvernightPackage::setFee(double overnightFee)
{
    fee = (overnightFee < 0.0) ? 0 : overnightFee;
}

double OvernightPackage::getFee() const
{
    return fee;
}

double OvernightPackage::calculateCost() const
{
    return (fee + Package::getCostPerOunce()) * Package::getWeight();
}