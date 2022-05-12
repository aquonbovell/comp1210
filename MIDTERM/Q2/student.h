#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student{
    
private:
    std::string sName;
    int sID, years;
    double annualFees;
public:
    Student(const std::string &studentName ="Student", const int &studentID = 0, const int &studentYears = 0, const double &studentAnnualFees = 0);
    std::string getStudentName() const;
    int getStudentID() const;
    void setStudentYears(const int &studentYears);
    int getStudentYears() const;
    void setStudentAnnualFees(const double &studentAnnualFees);
    double getStudentAnnualFees() const;
    double calculateTotalFees() const;
};
#endif