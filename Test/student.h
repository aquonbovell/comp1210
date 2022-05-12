#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student{
    std::string sName;
    int sID, numOfYears;
    double annualfees;
public:
    Student(const std::string &studentName ="Student", const int &studentID = 0, const int &numberOfYears = 0, const double &annualFee = 0);
    void setStudentName(const std::string &studentName);
    std::string getStudentName() const;
    void setStudentID(const int &studentsID);
    int getStudentID() const;
    void setNumberOfYears(const int &numberOfYears);
    int getNumberOfYears() const;
    void setAnnualFee(const double &annualFee);
    double getAnnualFee() const;
    double calculateTotalFees() const;
};
#endif