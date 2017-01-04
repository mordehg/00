#include <iostream>
#include "TaxiCenter.h"

/**
 * class: TaxiCenter
 * center that holds the map and all of the drivers, taxis and passengers
 */

/**
 * Constructor
 * @param the map.
 * @return the build taxi center with the wanted map.
 */
TaxiCenter::TaxiCenter(Map inputMap) {
    this->map = inputMap;
}
/**
 * destructor
 * deletes the TaxiCenter.
 */
TaxiCenter::~TaxiCenter() {
}

/**
 * getAvaliableDriver
 * @param trip that needs a driver
 * @return a driver that is available for the trip.
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

/**
 * assignAvaliableDriver
 * @param trip that needs a driver
 * assigning the driver to the trip using avaliableDriver
   to find the driver
 */
void TaxiCenter::assignAvaliableDriver(TripInfo &trip) {
    list<TaxiDriver>::iterator it;
    for (it = this->drivers.begin(); it != this->drivers.end(); it++) {
        if (it->driverAvailable() && (trip.getCurrent() == it->getLocation())) {
            it->insertNewTrip(trip);
        }
    }
}
/**
 * getTaxiDriver
 * @param driverID that we want to get.
 * @return the taxi with the given ID
 */
TaxiDriver TaxiCenter::getTaxiDriver(int driverID) {
    std::list<TaxiDriver>::iterator it;
    for(it = this->drivers.begin(); it != this->drivers.end(); it++) {
        if (driverID == it->getDriverID()) {
            return *it;
        }
    }
    return TaxiDriver(-1, -1,'S',-1, -1);
}
/**
 * getTaxi
 * @param taxiID that we want to get.
 * @return the drivet with tha given ID
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

/**
 * addDriver
 * @param driver to add
 * adding the given driver to the center
 */
void TaxiCenter::addDriver(TaxiDriver &driver) {
    this->drivers.push_front(driver);
}
/**
 * addTaxi
 * @param taxi to add
 * adding the given taxi to the center
 */
void TaxiCenter::addTaxi(Taxi &taxi) {
    this->taxis.push_front(taxi);
}

/**
 * addTrip
 * @param trip to add
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

/**
 * moveAllOneStep
 * @param the map of the game.
 * @param the clock for the current time
 * moving all of the druvers in the center one step.
 */
void TaxiCenter::moveAllToend() {
    list<TaxiDriver>::iterator it;
    for(it = this->drivers.begin(); it != this->drivers.end(); it++) {
        it->endOfTrip();
    }
}

/**
 * getTripByTime
 * @param tripTime the time the trip need to start
 * @return returns a trip with this start time
 */
TripInfo TaxiCenter::getTripByTime(int tripTime) {
    list<TripInfo>::iterator it;
    for (it = this->currnetTrips.begin(); it != this->currnetTrips.end(); it++) {
        if (it->getTripTime() == tripTime)
            return *it;
    }
    Block nab = Block(Point(-1,-1));
    return TripInfo(-1, nab, nab, -1,-1,-1);
}

/**
 * moveAllOneStep
 * @param the map of the game.
 * @param the clock for the current time
 * moving all of the druvers in the center one step.
 */
void TaxiCenter::moveAllOneStep(Map map, Clock clock) {
    list<TaxiDriver>::iterator it;
    for(it = this->drivers.begin(); it != this->drivers.end(); it++) {
        if (clock.currentTime() > it->getTripTime()) {
            int end = it->moveTheTaxiOneStep(map);
            if (end == 1)
                it->endOfTrip();
        }
    }
}