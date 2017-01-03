#ifndef EX2_TAXICENTER_H
#define EX2_TAXICENTER_H

#include <iostream>
#include "Map.h"
#include "Taxi.h"
#include "TaxiDriver.h"
#include "Clock.h"
#include <list>
using namespace std;

/**
  * class: TaxiCenter
  * center that holds the map and all of the drivers, taxis and passengers
  */
class TaxiCenter{
private:
    Map map;
    list<TaxiDriver> drivers;
    list<Taxi> taxis;
    list<TripInfo> currnetTrips;
public:
    /**
     * default constructor
     */
    TaxiCenter() { }
    /**
     * Constructor
     * @param the map.
     * @return the build taxi center with the wanted map.
     */
    TaxiCenter(Map inputMap);
    /**
     * destructor
     * deletes the TaxiCenter.
     */
    ~TaxiCenter();
    /**
     * assignTrips
     * attach each driver to a trip
     */
    void assignTrips();

    /**
     * moveAllToend
     * changind the current location of each driver to the end
     * of it's trip
     */
    void moveAllToend();

    /**
     * getAvaliableDriver
     * @param trip that needs a driver
     * @return a driver that is available for the trip.
     */
    TaxiDriver getAvaliableDriver(TripInfo &trip);
    /**
     * getTaxiDriver
     * @param driverID that we want to get.
     * @return the taxi with the given ID
     */
    TaxiDriver getTaxiDriver(int driverID);
    /**
     * getTaxi
     * @param taxiID that we want to get.
     * @return the drivet with tha given ID
     */
    Taxi getTaxi(int taxiID);
    /**
     * numOfDrivers
     * @return the number of drivers in the center
     */
    int numOfDriver() { return this->drivers.size(); }
    /**
     * numOfTaxis
     * @return the number of taxis in the center
     */
    int numOfTaxis() { return this->taxis.size(); }
    /**
     * addDriver
     * @param driver to add
     * adding the given driver to the center
     */
    void addDriver(TaxiDriver &driver);
    /**
     * addTaxi
     * @param taxi to add
     * adding the given taxi to the center
     */
    void addTaxi(Taxi &taxi);
    /**
     * addTrip
     * @param trip to add
     * adding the given trip to the center
     */
    void addTrip(TripInfo &trip);

    /**
     * moveAllOneStep
     * @param the map of the game.
     * @param the clock for the current time
     * moving all of the druvers in the center one step.
     */
    void moveAllOneStep(Map map, Clock clock);

    /**
     * getTripByTime
     * @param tripTime the time the trip need to start
     * @return returns a trip with this start time
     */
    TripInfo getTripByTime(int tripTime);

    /**
     * assignAvaliableDriver
     * @param trip that needs a driver
     * assigning the driver to the trip using avaliableDriver
       to find the driver
     */
    void assignAvaliableDriver(TripInfo &trip);

};
#endif //EX2_TAXICENTER_H
