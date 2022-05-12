// Fig. 14.9: ClientData.cpp
// Class Client Data stores customer's credit information.
#include <string>
#include <stdexcept>
#include "clientdata.h"

// default ClientData constructor
ClientData::ClientData(double balanceValue, const std::string &lastName, const std::string &firstName ,int accountNumberValue)
    : accountNumber(accountNumberValue), balance(balanceValue)
{
    setLastName(lastName);
    setFirstName(firstName);
}

// get account-number value
int ClientData::getAccountNumber() const { return accountNumber; }

// set account-number value
void ClientData::setAccountNumber(int accountNumberValue)
{
    if (accountNumberValue < 0.0)
        throw std::invalid_argument("Account Number must be >= 0");
    accountNumber = {accountNumberValue}; // should validate
}

// get last-name value
std::string ClientData::getLastName() const { return lastName; }

// set last-name value
void ClientData::setLastName(const std::string &lastNameString)
{
    // copy at most 15 characters from string to lastName
    size_t length(lastNameString.size());
    length = (length < 15 ? length : 14);
    lastNameString.copy(lastName, length);
    lastName[length] = '\0'; // append null character to lastName
}

// get first-name value
std::string ClientData::getFirstName() const { return firstName; }

// set first-name value
void ClientData::setFirstName(const std::string &firstNameString)
{
    // copy at most 10 characters from string to firstName
    size_t length{firstNameString.size()};
    length = (length < 10 ? length : 9);
    firstNameString.copy(firstName, length);
    firstName[length] = '\0'; // append null character to firstName
}

// get balance value
double ClientData::getBalance() const { return balance; }

// set balance value
void ClientData::setBalance(double balanceValue) { balance = balanceValue; }