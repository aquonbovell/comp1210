#include<stdexcept>
#include<iomanip>
#include<sstream>
#include "csstudent.h"

CSStudent::CSStudent(const std::string &studentName, const int &studentID, const int &studentYears, const double &studentAnnualFees, const double &csstudentLaptopFee) : Student(studentName,studentID,studentYears,studentAnnualFees){
    setLaptopFee(csstudentLaptopFee);
}

void CSStudent::setLaptopFee(const double &csstudentLaptopFee){
    if(csstudentLaptopFee < 0)
        throw std::invalid_argument("Laptop Fee must be >= 0");
    laptopfee = {csstudentLaptopFee};
}

double CSStudent::getLaptopFee() const{
    return laptopfee;
}

double CSStudent::calculateTotalFees() const{
    return Student::calculateTotalFees()+ getLaptopFee();
}

std::string CSStudent::toString() {
std::ostringstream output;
output << std::fixed << std::setprecision (2);
output << "*****************************************\n"
    << "CSStudent's name : " << getStudentName()<< "\n"
    << "CSStudent's ID : " << getStudentID()<< "\n"
    << "Amount of years at Uni : "<< getStudentYears() <<"\n"
    << "CSStudent's annual fee : " << getStudentAnnualFees() <<"\n"
    << "CSStudent's total fee : " <<calculateTotalFees()<<"\n"
    << "*****************************************\n";
return output.str();
}