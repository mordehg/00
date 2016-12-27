#include <iostream>
#include "TaxiCenter.h"

/*class: TaxiCenter
 * center that holds the map and all of the drivers, taxis and passengers
 */

/*
 * Constructor
 * gets the map.
 * returns: the build taxi center with the wanted map.
 */
TaxiCenter::TaxiCenter(Map inputMap) {
    this->map = inputMap;
}
/*
 * destructor
 * deletes the TaxiCenter.
 */
TaxiCenter::~TaxiCenter() {
}

/*
 * getAvaliableDriver
 * returns a driver that is available for the trip.
 */
TaxiDriver TaxiCenter::getAvaliableDriver(TripInfo &trip) {
    Block tripStsrt = trip.getStartPoint();
    list<TaxiDriver>::iterator it;
    TaxiDriver minDisDriver;
    it = this->drivers.begin();
    minDisDriver = *it;
    it++;
    for (it; it != this->drivers.end(); it++) {
        Block itLocation = it->getLocation();
        Block minLocation = minDisDriver.getLocation();
        int currentDistace = this->map.distanse(itLocation, tripStsrt);
        int minDis = this->map.distanse(minLocation, tripStsrt);
        if (it->driverAvailable() && (currentDistace < minDis)) {
            minDisDriver = *it;
        }
    }
    return minDisDriver;
}
/*
 * getTaxiDriver
 * returns the taxi with the given ID
 */
TaxiDriver TaxiCenter::getTaxiDriver(int driverID) {
    std::list<TaxiDriver>::iterator it;
    for(it = this->drivers.begin(); it != this->drivers.end(); it++) {
        if (driverID == it->getDriverID()) {
            return *it;
        }
    }
    return TaxiDriver(-1, -1,'S',-1);
}
/*
 * getTaxi
 * returns the drivet with tha given ID
 */
Taxi TaxiCenter::getTaxi(int taxiID) {
    std::list<Taxi>::iterator it;
    for(it = this->taxis.begin(); it != this->taxis.end(); it++) {
        if (taxiID == it->getTaxiID()) {
            return *it;
        }
    }
    return Taxi(-1,-1 ,'H','R');
}

/*
 * addDriver
 * adding the given driver to the center
 */
void TaxiCenter::addDriver(TaxiDriver &driver) {
    this->drivers.push_front(driver);
}
/*
 * addTaxi
 * adding the given taxi to the center
 */
void TaxiCenter::addTaxi(Taxi &taxi) {
    this->taxis.push_front(taxi);
}

/*
 * addTrip
 * adding the given trip to the center
 */
void TaxiCenter::addTrip(TripInfo &trip) {
    Block start = trip.getStartPoint();
    Block end = trip.getEndPoint();
    //adding the trip track (in BFS order):
    list<Point> track = this->map.BFS(start, end);
    trip.insertFullTrack(track);
    this->currnetTrips.push_front(trip);
}

/*
 * moveAllToend
 * changind the current location of each driver to the end
 * of it's trip
 */
void TaxiCenter::moveAllToend() {
    list<TaxiDriver>::iterator it;
    for(it = this->drivers.begin(); it != this->drivers.end(); it++) {
        it->endOfTrip();
    }
}

/*
 * assignTrips
 * attach each driver to a trip
 */
void TaxiCenter::assignTrips() {
    list<TaxiDriver>::iterator driverIt;
    list<TripInfo>::iterator tripIt;
    driverIt = this->drivers.begin();
    tripIt = this->currnetTrips.begin();
    for(; driverIt != this->drivers.end() && tripIt != this->currnetTrips.end(); driverIt++, tripIt++) {
        driverIt->insertNewTrip(*tripIt);
    }
}