#include<stdexcept>
#include<iostream>
#include "student.h"

Student::Student(const std::string &studentName, const int &studentID, const int &studentYears, const double &studentAnnualFees) : sName{studentName}, sID{studentID} {
    setStudentYears(studentYears);
    setStudentAnnualFees(studentAnnualFees);
};

std::string Student::getStudentName() const{
    return sName;
}

int Student::getStudentID() const{
    return sID;
}

void Student::setStudentYears(const int &studentYears) {
    if (studentYears <0)
        throw std::invalid_argument("Years must be >= 0");
    years = {studentYears};
}

int Student::getStudentYears() const{
    return years;
}

void Student::setStudentAnnualFees(const double &studentAnnualFees) {
    if (studentAnnualFees < 0.0)
        throw std::invalid_argument("student annual fees must be >= 0");
    annualFees = {studentAnnualFees};
}

double Student::getStudentAnnualFees() const{
    return annualFees;
}

double Student::calculateTotalFees() const{
    return getStudentAnnualFees()*getStudentYears();
}
