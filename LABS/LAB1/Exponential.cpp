#include <iostream>

using std::cout, std::cin;

unsigned long long power(int, int);

int main()
{
    int base = 0, exponent = 0;

    cout << "Enter a base: ";
    cin >> base;
    cout << "Enter an exponent: ";
    cin >> exponent;

    cout <<(power(base, exponent));

    return 0;
}

unsigned long long power(int base, int exponent) {
    return exponent == 1 ? base : base * power(base, (exponent - 1));
}