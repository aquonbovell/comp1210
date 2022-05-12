// Fig. 14.10: Fig14 10.cpp
// Creatingarandomly accessed file.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "clientdata.h" // ClientData class definition

int main()
{
    // std::fstream outfile{"credit.txt", std::ios::in | std::ios::binary};

    // ClientData blankClient;
    // if (!outfile)
    // {
    //     std::cerr << "File could not be opened." << std::endl;
    //     exit(EXIT_FAILURE);
    // }

    // outfile.read(reinterpret_cast<char *>(&blankClient), sizeof(blankClient));
    // std::cout<<blankClient.getLastName();

    std::ofstream outCredit("credit.txt", std::ios::out | std::ios::binary);
    // exit program if ofstream could not open file
    if (!outCredit)
    {
        std::cerr << "File could not be opened." << std::endl;
        exit(EXIT_FAILURE);
    }
    ClientData blankClient; // constructor zeros out each data member
    // output 100 blank records to file
    for (int i{0}; i < 100; ++i)
    {
        outCredit.write(
            reinterpret_cast<const char *>(&blankClient), sizeof(ClientData));
    }
    return 0;
}