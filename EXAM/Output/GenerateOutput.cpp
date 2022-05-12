#include <iostream>
#include <fstream>

int main()
{
    int largestnumber, number;

    std::ifstream inFile("input.txt", std::ios::in);
    
    if (!inFile)
    {
        std::cerr << "File input.txt could not be opened.\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Processing...\n";
    
    inFile >> number;
    largestnumber = number;

    while(!inFile.eof())
    {
        if (number > largestnumber)
            largestnumber = number;
        inFile >> number;
    }

    inFile.close();

    std::ofstream outFile("output.txt", std::ios::out);

    outFile << largestnumber;

    outFile.close();

    std::cout << "Processing is complete.\n";

    return 0;
}