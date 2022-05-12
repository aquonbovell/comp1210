#ifndef MANSION_H
#define MANSION_H
#include "house.h"

class Mansion : public House
{
public:
    Mansion(const std::string &HouseAddress = "", const int &NumberOfFloors = 0, const double &CostPerFloor = 0, const double &LuxuryFee = 0, const double &SwimmingPoolCost = 0);
    void setLuxuryFee(const double &LuxuryFee);
    double getLuxuryFee() const;
    void setSwimmingPoolCost(const double &SwimmingPoolCost);
    double getSwimmingPoolCost() const;
    double calculatePrice() const;
private:
    double luxfee;
    double swimpoolcost;
};
#endif