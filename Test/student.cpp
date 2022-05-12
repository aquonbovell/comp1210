#include "student.h"

Student::Student(const std::string &studentName, const int &studentID, const int &numberOfYears, const double &annualFee) {
    setStudentName(studentName);
    setStudentID(studentID);
    setNumberOfYears(numberOfYears);
    setAnnualFee(annualFee);
};

void Student::setStudentName(const std::string &studentName) {
    sName = {studentName};
}

std::string Student::getStudentName() const{
    return sName;
}

void Student::setStudentID(const int &studentID) {
    if (studentID <0)
        sID = studentID *-1;
}

int Student::getStudentID() const{
    return sID;
}

void Student::setNumberOfYears(const int &numberOfYears) {
    if (numberOfYears >=0)
        numOfYears = {numberOfYears};
    else
        numOfYears = {0};
}

int Student::getNumberOfYears() const{
    return numOfYears;
}

void Student::setAnnualFee(const double &annualFee) {
    if (annualFee>=0)
        annualfees = {annualFee};
    else
        annualfees = {0};
}

double Student::getAnnualFee() const{
    return annualfees;
}

double Student::calculateTotalFees() const{
    return annualfees*numOfYears;
}