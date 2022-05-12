#include <iostream>
#include <iomanip>
#include "Mansion.h"

int main(){
    Mansion mansion1("Waverley Cot, Saint George", 6, 54000.00, 20000.00, 16000.00);

    std::cout << std::fixed << std::setprecision (2)
            << "*****************************************\n"
            << "Mansion1's Address : " << mansion1.getHouseAddress()<< "\n"
            << "Mansion1 # of Floors : " << mansion1.getNumberOfFloors()<< "\n"
            << "Mansion1's Cost Per Floor : "<< mansion1.getCostPerFloor() <<"\n"
            << "Mansion1's Luxury Fee : " << mansion1.getLuxuryFee() <<"\n"
            << "Mansion1's Cost : " <<mansion1.calculatePrice()<<"\n"
            << "*****************************************\n";
    return 0;
}