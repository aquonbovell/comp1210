#include<iostream>

unsigned long long int power(int base, int exp);

int main (){
    std::cout<<"pow(2,4) = "<<power(3,4);
    return 0;
}

//iterative power using for loop
// unsigned long long int power(int base, int exp){
//     unsigned long long int result =1;
//     for (unsigned int i = exp; i > 0; --i){
//         result *= base;
//     }
//     return result;
// }

//iterative power using while loop 
// unsigned long long int power(int base, int exp){
//     unsigned long long int result =1;
//     while (exp > 0){
//         result *= base;
//         --exp;
//     }
//     return result;
// }

//resursive power
unsigned long long int power(int base, int exp){
    return exp == 1 ? base: base * power(base,(--exp));
}