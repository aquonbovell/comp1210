#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
class Package
{
private:
    std::string sName, sAddress, sCity, sState, sZipcode, rName, rAddress, rCity, rState, rZipcode;
    double wt, costPO;

public:
    Package(const std::string &sendersName, const std::string &sendersAddress, const std::string &sendersCity, const std::string &sendersState, const std::string &sendersZipcode, const std::string &recipientsName, const std::string &recipientsAddress, const std::string &recipientsCity, const std::string &recipientsState, const std::string &recipientsZipcode, double weight=0.0, double costPerOunce=0.0);

    void setSName(const std::string &);

    std::string getSName() const;

    void setSAddress(const std::string &);

    std::string getSAddress() const;

    void setSCity(const std::string &);

    std::string getSCity() const;

    void setSState(const std::string &);

    std::string getSState() const;

    void setSZipcode(const std::string &);

    std::string getSZipcode() const;

    void setRAddress(const std::string &);

    std::string getRAddress() const;

    void setRName(const std::string &);

    std::string getRName() const;

    void setRCity(const std::string &);

    std::string getRCity() const;

    void setRState(const std::string &);

    std::string getRState() const;

    void setRZipcode(const std::string &);

    std::string getRZipcode() const;

    void setWeight(double);

    double getWeight() const;

    void setCostPerOunce(double);

    double getCostPerOunce() const;

    double calculateCost() const;
};
#endif