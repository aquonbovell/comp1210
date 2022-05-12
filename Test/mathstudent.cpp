#include "mathstudent.h"

MathStudent::MathStudent(const std::string &studentName, const int &studentID, const int &numberOfYears, const double &annualFee, const double &tutorialFee) : Student(studentName,studentID,numberOfYears,annualFee) {
    setTutorialFee(tutorialFee);
}

void MathStudent::setTutorialFee(const double &tutorialFee){
    if(tutorialFee >=0)
        tutorialfee = {tutorialFee};
    else
        tutorialfee = {0};
}

double MathStudent::getTutorialFee() const{
    return tutorialfee;
}

double MathStudent::calculateTotalFees() const{
    return Student::getNumberOfYears()*(Student::getAnnualFee()+ getTutorialFee());
}