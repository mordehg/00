#include <iostream>
#include "TaxiCenter.h"

/*class: TaxiCenter
 * center that holds the map and all of the drivers, taxis and passengers
 */

list<TripInfo> TaxiCenter::sortTripInfoList() {
    list<TripInfo> sortedTrips;
    list<TripInfo>::iterator it;
    int lastInsertID = -1;
    for(it = this->currnetTrips.begin(); it != this->currnetTrips.end(); it++) {
        list<TripInfo>::iterator it2;
        it2 = this->currnetTrips.begin();
        TripInfo minTrip = *it2;
        it2++;
        for (it2; it2 != this->currnetTrips.end(); it2++) {
            if (it2->getID() != lastInsertID) {
                if (it2->getTripTime() < minTrip.getTripTime())
                    minTrip = *it2;
            }
        }
        lastInsertID = minTrip.getID();
        sortedTrips.push_front(minTrip);
    }
    return sortedTrips;
}

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
 * returns a driver that is available and most close to the trip.
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

void TaxiCenter::assignAvaliableDriver(TripInfo &trip) {
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
    list<TaxiDriver>::iterator it2;
    for(it2 = this->drivers.begin(); it2 != this->drivers.end(); it2++) {
        if (minDisDriver.getDriverID() == it2->getDriverID()) {
            it2->insertNewTrip(trip);
            break;
        }
    }
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
    return TaxiDriver(-1, -1,'S',-1, -1);
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
 * attach each driver to a trip by the trip time and start location
 */
void TaxiCenter::assignTrips() {
    list<TripInfo> sortedListOfTheTrips = sortTripInfoList();
    list<TripInfo>::iterator it;
    for (it = sortedListOfTheTrips.begin(); it != sortedListOfTheTrips.end(); it++) {
        if (!it->hasADriver()) {
            TaxiDriver closestDriver = getAvaliableDriver(*it);
            closestDriver.insertNewTrip(*it);
        }
    }
}

TripInfo TaxiCenter::getTripByTime(int tripTime) {
    list<TripInfo>::iterator it;
    for (it = this->currnetTrips.begin(); it != this->currnetTrips.end(); it++) {
        if (it->getTripTime() == tripTime)
            return *it;
    }
    Block nab = Block(Point(-1,-1));
    return TripInfo(-1, nab, nab, -1,-1,-1);
}


void TaxiCenter::moveAllOneStep(Map map, Clock clock) {
    list<TaxiDriver>::iterator it;
    for(it = this->drivers.begin(); it != this->drivers.end(); it++) {
        if (clock.currentTime() - it->getTripTime() == 1) {
            it->moveTheTaxiOneStep(map);
        }
    }
}