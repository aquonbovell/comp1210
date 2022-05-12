#include<iostream>
#include "csstudent.h"
#include "mathstudent.h"

using std::cout;

int main(){

    CSStudent csstudent("Jason Lovelle", 234567, 1, 550.00 , 1500.00);

    MathStudent mathstudent("Dane Boyce", 678913, 4, 650.00,40.00);
    
    //CSStudent Object
    cout << csstudent.toString();
    
    //MathStudent Object
    cout << mathstudent.toString();
    return 0;
}