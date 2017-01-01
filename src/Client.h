#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H

#include "TaxiDriver.h"
#include <vector>

using namespace std;
class Client {
private:
    TaxiDriver driver;
public:
    /*
     * inputParser
     * receives the input and spared the input by "," and insert
       the strings to a list.
     * returns the list.
     */
    vector<string> inputParser();

    /*
    * insertDriver
    * receives the driver information in strings and translate it
      to a driver. adding the driver to the given taxi center
    */
    void createDriver();

    TaxiDriver getDriver() { return this->driver; }

    string serlizeDriver();
};
#endif //EX4_CLIENT_H
