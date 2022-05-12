#ifndef CSSTUDENT_H
#define CSSTUDENT_H
#include "student.h"

class CSStudent : public Student{
private:
    double laptopfee;
public:
    CSStudent(const std::string &studentName ="CSStudent", const int &studentID = 0, const int &studentYears = 0, const double &studentAnnualFees = 0, const double &csstudentLaptopFee = 0);
    void setLaptopFee(const double &csstudentLaptopFee);
    double getLaptopFee() const;
    double calculateTotalFees() const;
    std::string toString();
};
#endif