#include <iostream>
#include <iomanip>

unsigned long long int factorial(int number);

int main()
{
    std::cout << "20! = "<< factorial(20) << std::endl;
    return 0;
}
// iterative factorial using while loop
// unsigned long long int factorial(int number)
// {
//     unsigned long long int result = 1;
//     while (number >= 1)
//     {
//         // std::cout<< "number = "<<number<<std::endl;
//         result *= number;
//         --number;
//     }
//     return result;
// }

// iterative factorial using for loop
unsigned long long int factorial(int number)
{
    unsigned long long int result = 1;
    for (int i = number; i >= 1; --i)
    {
        // std::cout<< "number = "<<number<<std::endl;
        result *= i;
    }
    return result;
}

//recursive factorial
// unsigned long long int factorial(int number){
//     return number ==1 ? 1: number * factorial(--number);
// }