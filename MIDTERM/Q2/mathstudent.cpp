#include<stdexcept>
#include<iomanip>
#include<sstream>
#include "mathstudent.h"

MathStudent::MathStudent(const std::string &studentName, const int &studentID, const int &studentYears, const double &studentAnnualFees, const double &mathstudentTutorialFee) : Student(studentName,studentID,studentYears,studentAnnualFees) {
    setTutorialFee(tutorialFee);
}

void MathStudent::setTutorialFee(const double &mathstudentTutorialFee){
    if(mathstudentTutorialFee < 0)
        throw std::invalid_argument("Tutorial Fee must be >= 0");
    tutorialFee = {mathstudentTutorialFee};
}

double MathStudent::getTutorialFee() const{
    return tutorialFee;
}

double MathStudent::calculateTotalFees() const{
    return Student::getStudentYears() * (Student::getStudentAnnualFees() + getTutorialFee());
}

std::string MathStudent::toString() {
std::ostringstream output;
output << std::fixed << std::setprecision (2);
output << "*****************************************\n"
    << "MathStudent's name : " << getStudentName()<< "\n"
    << "MathStudent's ID : " << getStudentID()<< "\n"
    << "Amount of years at Uni : "<< getStudentYears() <<"\n"
    << "MathStudent's annual fee : " << getStudentAnnualFees() <<"\n"
    << "MathStudent's total fee : " <<calculateTotalFees()<<"\n"
    << "*****************************************\n";
return output.str();
}