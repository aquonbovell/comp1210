#ifndef HOUSE_H
#define HOUSE_H
#include <string>

class House
{
public:
    House(const std::string &HouseAddress = "", const int &NumberOfFloors = 0, const double &CostPerFloor = 0.0);
    std::string getHouseAddress() const;
    void setNumberOfFloors(const int &numberofFloors);
    int getNumberOfFloors() const;
    void setCostPerFloor(const double &costPerFloor);
    double getCostPerFloor() const;
    double calculatePrice() const;
private:
    std::string address;
    int numoffloors;
    double costperfloor;
};
#endif