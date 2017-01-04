#ifndef EX2_TAXIDRIVER_H
#define EX2_TAXIDRIVER_H

#include <iostream>
#include "Taxi.h"

/**
 * class: TaxiDriver
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
    /**
     * default constructor
     */
    TaxiDriver() { }
    /**
     * Constructor
     * @param the driver's id, age, status and exprience years
     * @return the build TaxiDriver with the wanted values
     */
    TaxiDriver(int id, int age, char driverS, int exp, int taxiID);
    /**
     * destructor
     * deletes the point.
     */
    ~TaxiDriver();

    /**
     * insertTaxi
     * @param newTaxi to add to the taxi
     */
    void insertTaxi(Taxi &newTaxi) { this->myTaxi = newTaxi; }

    /**
     * rankAvrage
     * @return the avrange rank of this driver
     */
    int rankAvrage();
    /**
     * driverAvailable
     * @return true if the driver is available and false otherwise
     */
    bool driverAvailable() { return this->available; }
    /**
     * getTaxiId
     * @return the taxi's ID
     */
    int getTaxiID() { return this->myTaxi.getTaxiID(); }
    /**
     * getDriverId
     * @return the driver's taxi's ID
     */
    int getDriverID() { return this->ID; }
    /**
     * getAge
     * @return the drivers age
     */
    int gatAge() { return this->age; }
    /**
     * getStatus
     * @return the drivers status
     */
    char getStatus() { return this->driverStatus; }
    /**
     * getExprience
     * @return the drivers exprience
     */
    int getExprience() { return  this->exprience; }
    /**
     * addRank
     * @param newRank to set the renk
     * adding the given rank to the rank sum of the driver
     */
    void addRank(int &newRank) { this->rankSum+=newRank; }
    /**
     * addCustomer
     * adding 1 to the drivers customer counter
     */
    void addCustomer();
    /**
    * endOfTrip
    * when the driver get to the and of the trip
       he is now available
    */
    void endOfTrip();

    /**
     * insertNewTrip
     * @param trip to insert to the taxi
     * insert the given trip to e the drivers current trip
     */
    void insertNewTrip(TripInfo &trip);
    /**
     * getLocation
     * getting the driver current location
     */
    Block getLocation();

    /**
    * moveTheTaxiOneStep
    * @param map of the gamw
    * @return 1 - if the trip get to an end
             0 - otherwise
    * moving the taxi one step
    */
    int moveTheTaxiOneStep(Map map);

    /**
     * getTripTime
     * @return the trip's time
     */
    int getTripTime();
};
#endif //EX2_TAXIDRIVER_H
