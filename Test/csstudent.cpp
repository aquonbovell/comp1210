#include "csstudent.h"

CSStudent::CSStudent(const std::string &studentName, const int &studentID, const int &numberOfYears, const double &annualFee, const double &laptopFee) : Student(studentName,studentID,numberOfYears,annualFee){
    setLaptopFee(laptopFee);
}

void CSStudent::setLaptopFee(const double &laptopFee){
    if(laptopFee >=0)
        laptopfee = {laptopFee};
    else
        laptopfee = {0};
}

double CSStudent::getLaptopFee() const{
    return laptopfee;
}

double CSStudent::calculateTotalFees() const{
    return Student::calculateTotalFees()+ getLaptopFee();
}