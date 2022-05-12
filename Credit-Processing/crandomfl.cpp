// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include "clientdata.h" // ClientData class definition

// int main()
// {
//     std::fstream outCredit{"credit.txt", std::ios::in | std::ios::out | std::ios::binary};
//     // exit program if fstream cannot open file
//     if (!outCredit)
//     {
//         std::cerr << "File could not be opened." << std::endl;
//         exit(EXIT_FAILURE);
//     }
    
//     std::cout << "Enter account number (1 to 100, 0 to end input)\n? ";
    
//     int accountNumber;
//     std::string lastName;
//     std::string firstName;
//     double balance;
    
//     std::cin >> accountNumber; // read account number
    
//     // user enters information, which is copied into file
//     while (accountNumber > 0 && accountNumber <= 100)
//     {
//         // user enters last name, first name and balance
//         std::cout << "Enter lastname, firstname and balance\n? ";
//         std::cin >> lastName;
//         std::cin >> firstName;
//         std::cin >> balance;
//         // create ClientData object
//         ClientData client(accountNumber, lastName, firstName, balance);
//         // seek position in file of user-specified record
//         outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));
//         // write user-specified information in file
//         outCredit.write( reinterpret_cast<const char *>(&client), sizeof(ClientData));
//         // enable user to enter another account
//         std::cout << "Enter account number\n? " ;
//         std::cin >> accountNumber;
//     }
//     return 0;
// }