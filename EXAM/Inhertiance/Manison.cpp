#include <stdexcept>
#include "mansion.h"

Mansion::Mansion(const std::string &HouseAddress, const int &NumberOfFloors, const double &CostPerFloor, const double &LuxuryFee, const double &SwimmingPoolCost) : House(HouseAddress, NumberOfFloors, CostPerFloor)
{
    setLuxuryFee(LuxuryFee);
    setSwimmingPoolCost(SwimmingPoolCost);
};

void Mansion::setLuxuryFee(const double &LuxuryFee)
{
    if (LuxuryFee < 0.0)
        throw std::invalid_argument("Luxury Fee must be >= 0");
    luxfee = {LuxuryFee};
};

double Mansion::getLuxuryFee() const
{
    return luxfee;
};

void Mansion::setSwimmingPoolCost(const double &SwimmingPoolCost)
{
    if (SwimmingPoolCost < 0.0)
        throw std::invalid_argument("Cost of Swimming Pool must be >= 0");
    swimpoolcost = {SwimmingPoolCost};
};

double Mansion::getSwimmingPoolCost() const
{
    return swimpoolcost;
};

double Mansion::calculatePrice() const{
    return (getNumberOfFloors() * (getCostPerFloor() + getLuxuryFee())) + getSwimmingPoolCost();
}