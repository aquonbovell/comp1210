#include <iostream>
#include <iomanip>
#include <fstream>

using std::cerr, std::cout, std::ios, std::ifstream, std::ofstream, std::setprecision, std::string;

int main()
{
    int accountNumber, accountNum;
    double currentBalance, dollarAmount;
    bool found = false;
    string name;

    ifstream inOldMaster("oldmast.txt", ios::in), inTransaction("trans.txt", ios::in);
    ofstream outNewMaster("newmast.txt", ios::out);
    if (!inOldMaster)
    {
        cerr << "Unable to open oldmast.txt\n";
        exit(EXIT_FAILURE);
    }

    if (!inTransaction)
    {
        cerr << "Unable to open trans.txt\n";
        exit(EXIT_FAILURE);
    }

    if (!outNewMaster)
    {
        cerr << "Unable to open newmast.txt\n";
        exit(EXIT_FAILURE);
    }

    cout << "Processing...\n";
    inOldMaster >> accountNumber >> quoted(name) >> currentBalance;
    while(!inOldMaster.eof())
    {
        
        inTransaction >> accountNum >> dollarAmount;
        
        while (!inTransaction.eof())
        {
            
            if (accountNumber == accountNum)
                currentBalance+= dollarAmount;
            inTransaction >> accountNum >> dollarAmount;
            
        }

        outNewMaster << accountNumber <<' '<< quoted(name) <<' '<< std::fixed<< setprecision(2) << currentBalance << '\n';
        inTransaction.clear();
        inTransaction.seekg(ios::beg);
        inOldMaster >> accountNumber >> quoted(name) >> currentBalance;
    }
    outNewMaster.close();
    inOldMaster.close();
    inTransaction.close();

    inOldMaster.open("oldmast.txt", ios::in);
    inTransaction.open("trans.txt", ios::in);

    if (!inOldMaster)
    {
        cerr << "Unable to open oldmast.txt\n";
        exit(EXIT_FAILURE);
    }

    if (!inTransaction)
    {
        cerr << "Unable to open trans.txt\n";
        exit(EXIT_FAILURE);
    }

    inTransaction >> accountNum >> dollarAmount;
    while(!inTransaction.eof())
    {
        inOldMaster >> accountNumber >> quoted(name) >> currentBalance;
        
        while (!inOldMaster.eof() && !found)
        {
            found = {accountNum == accountNumber ? true : false};
            inOldMaster >> accountNumber >> quoted(name) >> currentBalance;
        }

        if (!found)
            cout << "Unmatched transaction record for account: " << accountNum << '\n';
        found = false;
        inOldMaster.clear();
        inOldMaster.seekg(ios::beg);
        inTransaction >> accountNum >> dollarAmount;
    }
    inTransaction.close();
    inOldMaster.close();
    cout << "Processing is complete.\n";
    return 0;
}