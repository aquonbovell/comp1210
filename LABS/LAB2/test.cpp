#include <iostream>
#include <iomanip>
#include "twodaypackage.h"
#include "overnightpackage.h"

using std::cout, std::fixed;
using std::endl;
using std::setprecision;

int main()
{
    Package FedEx("John Doe", "123 Avenue", "Hanyesville", "St. James", "BB12345", "Jane Doe", "456 Avenue Gall Hill", "Oistins", "Christ Church", "BB234567", 8.5, 2.15);

    TwoDayPackage DHL("Pam Doe", "234 Avenue", "Road View", "St. Peter", "BB34567", "Jannette Doe", "567 Avenue Goodland", "Deacons", "St. Michael", "BB45678", 8.5, 2.15, 5.0);

    OvernightPackage UPS("Jannette Doe", "345 Avenue", "Waverly Cot", "St. George", "BB567891", "Caroline Doe", "678 Avenue River Road", "Six Roads", "St. Phillip", "BB678912", 8.5, 2.15, 2.5);

    cout << fixed << setprecision(2);
    // Base Package Class Test Code
    cout << "****************************************************************" << endl;
    cout << "Shipping a package with regular delivery through FedEx\n";
    cout << "The sender's name : " << FedEx.getSName() << "\n";
    cout << "The sender's address : \n";
    cout << " " << FedEx.getSAddress() << ", " << FedEx.getSCity() << "\n " << FedEx.getSState() << ", " << FedEx.getSZipcode() << "\n";
    cout << "The recipient's name : " << FedEx.getRName() << "\n";
    cout << "The recipient's address : \n";
    cout << " " << FedEx.getRAddress() << ", " << FedEx.getRCity() << "\n " << FedEx.getRState() << ", " << FedEx.getRZipcode() << "\n";
    cout << "The cost of shipping this package with FedEx is $ " << FedEx.calculateCost() << "\n";
    cout << "****************************************************************" << endl;
    cout << "\n\n";

    // TwoDayPackage Class Test Code
    cout << "****************************************************************" << endl;
    cout << "Shipping a package with two day delivery through DHL\n";
    cout << "The sender's name : " << DHL.getSName() << "\n";
    cout << "The sender's address : \n";
    cout << " " << DHL.getSAddress() << ", " << DHL.getSCity() << "\n " << DHL.getSState() << ", " << DHL.getSZipcode() << "\n";
    cout << "The recipient's name : " << DHL.getRName() << "\n";
    cout << "The recipient's address : \n";
    cout << " " << DHL.getRAddress() << ", " << DHL.getRCity() << "\n " << DHL.getRState() << ", " << DHL.getRZipcode() << "\n";
    cout << "The cost of shipping this package with DHL is $ " << DHL.calculateCost() << "\n";
    cout << "****************************************************************" << endl;
    cout << "\n\n";

    // OvernightPackage Class Test Code
    cout << "****************************************************************" << endl;
    cout << "Shipping a package with overnight delivery through UPS\n";
    cout << "The sender's name : " << UPS.getSName() << "\n";
    cout << "The sender's address : \n";
    cout << " " << UPS.getSAddress() << ", " << UPS.getSCity() << "\n " << UPS.getSState() << ", " << UPS.getSZipcode() << "\n";
    cout << "The recipient's name : " << UPS.getRName() << "\n";
    cout << "The recipient's address : \n";
    cout << " " << UPS.getRAddress() << ", " << UPS.getRCity() << "\n " << UPS.getRState() << ", " << UPS.getRZipcode() << "\n";
    cout << "The cost of shipping this package with UPS is $ " << UPS.calculateCost() << "\n";
    cout << "****************************************************************" << endl;
    cout << "\n\n";

    system("pause");
    return 0;
}