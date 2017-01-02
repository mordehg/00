#ifndef EX2_TAXICENTER_H
#define EX2_TAXICENTER_H

#include <iostream>
#include "Map.h"
#include "Taxi.h"
#include "TaxiDriver.h"
#include "Passenger.h"
#include <list>
using namespace std;

/*class: TaxiCenter
 * center that holds the map and all of the drivers, taxis and passengers
 */
class TaxiCenter{
private:
    Map map;
    list<TaxiDriver> drivers;
    list<Taxi> taxis;
    list<TripInfo> currnetTrips;

    list<TripInfo> sortTripInfoList();
public:
    /*
     * default constructor
     */
    TaxiCenter() { }
    /*
     * Constructor
     * gets the map.
     * returns: the build taxi center with the wanted map.
     */
    TaxiCenter(Map inputMap);
    /*
     * destructor
     * deletes the TaxiCenter.
     */
    ~TaxiCenter();
    /*
     * getAvaliableDriver
     * returns a driver that is available for the trip the
       given passenger wants.
     */

    /*
     * assignTrips
     * attach each driver to a trip
     */
    void assignTrips();

    /*
     * moveAllToend
     * changind the current location of each driver to the end
     * of it's trip
     */
    void moveAllToend();

    TaxiDriver getAvaliableDriver(TripInfo &trip);
    /*
     * getTaxiDriver
     * returns the taxi with the given ID
     */
    TaxiDriver getTaxiDriver(int driverID);
    /*
     * getTaxi
     * returns the drivet with tha given ID
     */
    Taxi getTaxi(int taxiID);
    /*
     * numOfDrivers
     * returns the number of drivers in the center
     */
    int numOfDriver() { return this->drivers.size(); }
    /*
     * numOfTaxis
     * returns the number of taxis in the center
     */
    int numOfTaxis() { return this->taxis.size(); }
    /*
     * addDriver
     * adding the given driver to the center
     */
    void addDriver(TaxiDriver &driver);
    /*
     * addTaxi
     * adding the given taxi to the center
     */
    void addTaxi(Taxi &taxi);
    /*
     * addTrip
     * adding the given trip to the center
     */
    void addTrip(TripInfo &trip);

    void moveAllOneStep(Map map);

    TripInfo getTripByTime(int tripTime);

};
#endif //EX2_TAXICENTER_H
