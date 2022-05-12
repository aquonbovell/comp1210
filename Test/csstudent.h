#ifndef CSSTUDENT_H
#define CSSTUDENT_H
#include "student.h"

class CSStudent : public Student{
    double laptopfee;
public:
    CSStudent(const std::string &studentName ="CSStudent", const int &studentID = 0, const int &numberOfYears = 0, const double &annualFee = 0, const double &laptopFee = 0);
    void setLaptopFee(const double &annualFee);
    double getLaptopFee() const;
    double calculateTotalFees() const;
};
#endif