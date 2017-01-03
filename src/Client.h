#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H

#include "TaxiDriver.h"
#include <vector>

using namespace std;
class Client {
private:
    TaxiDriver driver;
public:
    /**
     * inputParser
     * receives the input and spared the input by "," and insert
       the strings to a list.
     * @return the list.
     */
    vector<string> inputParser();

    /**
    * createDriver
    * receives the driver information in strings and translate it
      to a driver.
    */
    void createDriver();

    /**
     * getDriver
     * @return the driver we created from the input
     */
    TaxiDriver getDriver() { return this->driver; }
};
#endif //EX4_CLIENT_H
