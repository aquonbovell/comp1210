#ifndef MATHSTUDENT_H
#define MATHSTUDENT_H
#include "student.h"

class MathStudent : public Student{
    double tutorialfee;
public:
    MathStudent(const std::string &studentName ="MathStudent", const int &studentID = 0, const int &numberOfYears = 0, const double &annualFee = 0, const double &tutorialFee = 0);
    void setTutorialFee(const double &annualFee);
    double getTutorialFee() const;
    double calculateTotalFees() const;
};
#endif