#include<iostream>
//#include<iomanip>
#include<sstream>

std::string firstName = "sue";
std::string lastName = "jones";
std::string socialSecurityNumber = "246-242-8537";
double grossSales = 1300;
double commissionRate = .06;

std::string toString();
int main(){
    std::cout<<toString();
    return 0;
}
std::string toString() {
std::ostringstream output;
//output << std::fixed << std::setprecision (2); // two digits of precision
output << "commission employee: "<< firstName << " " << lastName
<< "\nsocial security number: " << socialSecurityNumber
<< "\ngross sales: " << 5611
<< "\ncommission rate: "<< commissionRate;
return output.str();
}

