#include <iostream>
#include "iomanip"
#include "csstudent.h"
#include "mathstudent.h"

using std::cout; using std::endl;

int main(){

    CSStudent student1("Jason Lovelle", -234567, 1, 550.00 , 1500.00);

    MathStudent student2("Dane Boyce", 678913, 4, 650.00,40.00);
    
    cout << std::fixed<<std::setprecision(2);
    
    //CSStudent Object
    cout << "*****************************************\n";
    cout << "Student1's name : " << student1.getStudentName()<< "\n";
    cout << "Student1's ID : " <<student1.getStudentID()<< "\n";
    cout << "Amount of years spent at Uni : "<< student1.getNumberOfYears() <<"\n";
    cout << "Student1's annual fee : " << student1.getAnnualFee() <<"\n";
    cout << "Student1's total fee : " << student1.calculateTotalFees()<<"\n";
    cout << "*****************************************\n\n";
    
    //MathStudent Object
    cout << "*****************************************\n";
    cout << "Student2's name : " << student2.getStudentName()<< "\n";
    cout << "Student2's ID : " <<student2.getStudentID()<< "\n";
    cout << "Amount of years spent at Uni : "<< student2.getNumberOfYears() <<"\n";
    cout << "Student2's annual fee : " << student2.getAnnualFee() <<"\n";
    cout << "Student2's total fee : " << student2.calculateTotalFees()<<"\n";
    cout << "*****************************************\n";
    return 0;
}
