#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    std::array<float, 41> z = {100.2, 1.6, 82.6, 7.9, 74.6, 89.1, 83.5, 68.4, 18.0, 61.6, 15.6, 97.7, 6.2, 64.5,45263.9, 55, 19.9, 8.1, 3.561, 00.2, 1.6, 82.6, 7.9, 74.6, 89.1, 83.5, 68.4, 18.0, 61.6, 15.6, 97.7, 6.2, 64.5, 63.9, 55, 34.95, 19.9, 8.1, 4, 6, 68};

    std::sort(z.begin(), z.end());

    std::cout<<z.back();
    return 0;
}