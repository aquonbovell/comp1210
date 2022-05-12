#include "package.h"

Package::Package(const std::string &sendersName, const std::string &sendersAddress, const std::string &sendersCity, const std::string &sendersState, const std::string &sendersZipcode, const std::string &recipientsName, const std::string &recipientsAddress, const std::string &recipientsCity, const std::string &recipientsState, const std::string &recipientsZipcode, double weight, double costPerOunce) : sName{sendersName}, sAddress{sendersAddress}, sCity{sendersCity},sState{sendersState}, sZipcode{sendersZipcode}, rName{recipientsName}, rAddress{recipientsAddress},rCity{recipientsCity}, rState{recipientsState}, rZipcode{recipientsZipcode}
{
    setWeight(weight);
    setCostPerOunce(costPerOunce);
}

void Package::setSName(const std::string &sendersName)
{
    sName = sendersName;
}
std::string Package::getSName() const
{
    return sName;
}
void Package::setSAddress(const std::string &sendersAddress)
{
    sAddress = sendersAddress;
}
std::string Package::getSAddress() const
{
    return sAddress;
}
void Package::setSCity(const std::string &sendersCity)
{
    sCity = sendersCity;
}
std::string Package::getSCity() const
{
    return sCity;
}
void Package::setSState(const std::string &sendersState)
{
    sState = sendersState;
}
std::string Package::getSState() const
{
    return sState;
}
void Package::setSZipcode(const std::string &sendersZipcode)
{
    sZipcode = sendersZipcode;
}
std::string Package::getSZipcode() const
{
    return sZipcode;
}
void Package::setRName(const std::string &recipientsName)
{
    rName = recipientsName;
}
std::string Package::getRName() const
{
    return rName;
}
void Package::setRAddress(const std::string &recipientsAddress)
{
    rAddress = recipientsAddress;
}
std::string Package::getRAddress() const
{
    return rAddress;
}
void Package::setRCity(const std::string &recipientsCity)
{
    rCity = recipientsCity;
}
std::string Package::getRCity() const
{
    return rCity;
}
void Package::setRState(const std::string &recipientsState)
{
    rState = recipientsState;
}
std::string Package::getRState() const
{
    return rState;
}
void Package::setRZipcode(const std::string &recipientsZipcode)
{
    rZipcode = recipientsZipcode;
}
std::string Package::getRZipcode() const
{
    return rZipcode;
}
void Package::setWeight(double weight)
{
    wt = (weight < 0.0) ? 0.0 : weight;
}
double Package::getWeight() const
{
    return wt;
}
void Package::setCostPerOunce(double costPerOunce)
{
    costPO = (costPerOunce < 0.0) ? 0.0 : costPerOunce;
}
double Package::getCostPerOunce() const
{
    return costPO;
}
double Package::calculateCost() const
{
    return wt * costPO;
}