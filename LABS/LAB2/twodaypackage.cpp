#include "twodaypackage.h"

TwoDayPackage::TwoDayPackage(const std::string &sendersName, const std::string &sendersAddress, const std::string &sendersCity, const std::string &sendersState, const std::string &sendersZipcode, const std::string &recipientsName, const std::string &recipientsAddress, const std::string &recipientsCity, const std::string &recipientsState, const std::string &recipientsZipcode, double weight, double costPerOunce, double flatfee) : Package(sendersName, sendersAddress, sendersCity, sendersState, sendersZipcode, recipientsName, recipientsAddress, recipientsCity, recipientsState, recipientsZipcode, weight, costPerOunce)
{
    setFlatFee(flatfee);
}

void TwoDayPackage::setFlatFee(double fltfee)
{
    fltFee = (fltfee < 0) ? 0.0 : fltfee;
}

double TwoDayPackage::getFlatFee() const
{
    return fltFee;
}

double TwoDayPackage::calculateCost() const
{
    return fltFee + Package::calculateCost();
}
