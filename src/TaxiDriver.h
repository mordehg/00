#ifndef EX2_TAXIDRIVER_H
#define EX2_TAXIDRIVER_H

#include <iostream>
#include "Taxi.h"


/*class: TaxiDriver
 * the objects taht holds the taxi, with a few identifying fileds
 */
class TaxiDriver {
    int ID;
    int age;
    char driverStatus;
    int exprience;
    int rankSum;
    Taxi myTaxi;
    int customerSum;
    bool available;
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & ID;
        ar & age;
        ar & driverStatus;
        ar & exprience;
        ar & rankSum;
        ar & myTaxi;
        ar & customerSum;
        ar & available;
    }
public:
    /*
     * default constructor
     */
    TaxiDriver() { }
    /*
     * Constructor
     * gets the driver's id, age, status and exprience years
     * returns the build TaxiDriver with the wanted values
     */
    TaxiDriver(int id, int age, char driverS, int exp, int taxiID);
    /*
     * destructor
     * deletes the point.
     */
    ~TaxiDriver();

    void insertTaxi(Taxi &newTaxi) { this->myTaxi = newTaxi; }

    /*
     * rankAvrage
     * returns the avrange rank of this driver
     */
    int rankAvrage();
    /*
     * driverAvailable
     * returns true if the driver is available and false otherwise
     */
    bool driverAvailable() { return this->available; }
    /*
     * getTaxiId
     * returns the taxi's ID
     */
    int getTaxiID() { return this->myTaxi.getTaxiID(); }
    /*
     * getDriverId
     * returns the driver's taxi's ID
     */
    int getDriverID() { return this->ID; }
    /*
     * getAge
     * returns the drivers age
     */
    int gatAge() { return this->age; }
    /*
     * getStatus
     * returns the drivers status
     */
    char getStatus() { return this->driverStatus; }
    /*
     * getExprience
     * returns the drivers exprience
     */
    int getExprience() { return  this->exprience; }
    /*
     * addRank
     * adding the given rank to the rank sum of the driver
     */
    void addRank(int &newRank) { this->rankSum+=newRank; }
    /*
     * addCustomer
     * adding 1 to the drivers customer counter
     */
    void addCustomer();
    /*
     * endOfTrip
     * changing the driver location to the end of it's trip
     */
    void endOfTrip();

    /*
     * insertNewTrip
     * insert the given trip to e the drivers current trip
     */
    void insertNewTrip(TripInfo &trip);
    /*
     * getLocation
     * getting the driver current location
     */
    Block getLocation();

};
#endif //EX2_TAXIDRIVER_H
