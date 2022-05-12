#include <stdexcept>
#include<iostream>
#include "house.h"

House::House(const std::string &HouseAddress, const int &NumberOfFloors, const double &CostPerFloor) : address{HouseAddress}
{
    setNumberOfFloors(NumberOfFloors);
    setCostPerFloor(CostPerFloor);
};

std::string House::getHouseAddress() const
{
    return address;
};

void House::setNumberOfFloors(const int &NumberOfFloors)
{
    if (NumberOfFloors < 0)
        throw std::invalid_argument("Number of floors must be >= 0");
    numoffloors = {NumberOfFloors};
};

int House::getNumberOfFloors() const
{
    return numoffloors;
};

void House::setCostPerFloor(const double &CostPerFloor)
{
    if (CostPerFloor < 0.0)
        throw std::invalid_argument("Cost Per Floor must be >= 0");
    costperfloor = {CostPerFloor};
};

double House::getCostPerFloor() const
{
    return costperfloor;
};

double House::calculatePrice() const
{
    return getNumberOfFloors() * getCostPerFloor();
};
