#include <iostream>

int main()
{
    float w[20] = {100.2, 1.6, 82.6, 7.9, 74.6, 89.1, 83.5, 68.4, 18.0, 61.6, 15.6, 97.7, 6.2, 64.5, 63.9, 55, 34.95, 19.9, 8.1, 3.56};
    float smallest = w[0];
    float largest = w[0];

    for (auto const element : w)
    {
        if (element < smallest)
        {
            smallest = element;
        }
        else if (element > largest)
        {
            largest = element;
        }
    }
    std::cout << "The smallest value of the array is : " << smallest << "\nThe largest value of the array is : " << largest;
}