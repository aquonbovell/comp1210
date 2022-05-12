#ifndef MATHSTUDENT_H
#define MATHSTUDENT_H
#include "student.h"

class MathStudent : public Student{
private:
    double tutorialFee;
public:
    MathStudent(const std::string &studentName ="MathStudent", const int &studentID = 0, const int &studentYears = 0, const double &studentAnnualFees = 0.0, const double &mathstudentTutorialFee = 0.0);
    void setTutorialFee(const double &mathstudentTutorialFee);
    double getTutorialFee() const;
    double calculateTotalFees() const;
    std::string toString();
};
#endif