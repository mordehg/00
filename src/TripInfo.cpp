#include <iostream>
#include <list>
#include "TripInfo.h"
using namespace std;

/**
 * class: TripInfo
 * the objects that holds all the important information for the trip
 */

/**
 * Constructor
 * @param the trip id, the start block, the end block, the tip's price
   and start time.
 * @return the build trip with the wanted values
 */
TripInfo::TripInfo(int id, Block &startB, Block &endB, int passNum, double price, int time) {
    this->ID = id;
    this->passengersNum = passNum;
    this->start = startB;
    this->end = endB;
    this->tariff = price;
    this->currentPoint = startB;
    this->tripTime = time;
    this->beenAttachToDriver = false;
}
/**
 * destructor
 * deletes the TripInfo.
 */
TripInfo::~TripInfo() {
}

/**
 * fullTrack
 * @return the fuul track of the trip, from start to end
 */
list<Point>* TripInfo::fullTrack() {
    return &(this->fullTrip);
}
/**
 * fullTrackLenght
 * @return the lenght of the full track
 */
int TripInfo::fullTrackLenght() {
    return this->fullTrip.size();
}
/**
 * trackAhead
 * @return the track from the current point to the end
 */
list<Point> TripInfo::tracklAhead() {
    list<Point> ahaed;
    list<Point>::iterator it;
    for (it = this->fullTrip.begin(); it != this->fullTrip.end(); it++) {
        if (*it == this->currentPoint.getValue())
            break;
    }
    for (it; it != this->fullTrip.end(); it++) {
        ahaed.push_back(*it);
    }
    return ahaed;
}
/**
 * tracklAheadLength
 * @return the length of the track ahead
 */
int TripInfo::tracklAheadLength() {
    return (int)(tracklAhead().size());
}
/**
 * trackBehaind
 * @return the track from the start to the currnet point
 */
list<Point> TripInfo::trackBehaind() {
    list <Point> behaind;
    list<Point>::iterator it;
    it = this->fullTrip.begin();
    while (it != this->fullTrip.end()) {
        if (*it == this->currentPoint.getValue())
            break;
        else
            behaind.push_front(*it);
    }
    return behaind;
}
/**
 * trackBehaindLength
 * @return the length of the trackbehaind
 */
int TripInfo::trackBehaindLength() {
    return (int)(trackBehaind().size());
}

/**
 * insertFullTrack
 * @param track to insert to the trip
 * inserting the givven track (list of point) to
   the trip information
 */
void TripInfo::insertFullTrack(list<Point> &track) {
    this->fullTrip = track;
}

/**
 * updateCurrentOneStep
 * @param taxiType 1 or 2 for the number of blocks to move
 * @param map of the game
 * @return 1 - the end of the trip, 0 - otherwisw
 * moving the current point one step
 */
int TripInfo::updateCurrentOneStep(int taxiType, Map map) {
    if (this->ID == -1)
        return 0;
    list<Point>::iterator it;
    for(it = this->fullTrip.begin(); it != this->fullTrip.end(); it++) {
        if (*it == this->currentPoint.getValue())
            break;
    }
    if (taxiType == 1) {
        it++;
        if (*it == *(this->fullTrip.end())) {
            return 1;
        }
        currentPoint = map.getBlock(*it);
    } else if (taxiType == 2 ){
        it++;
        if (*it == *(this->fullTrip.end())) {
            return 1;
        }
        currentPoint = map.getBlock(*it);
        it++;
        if (*it == *(this->fullTrip.end())) {
            return 1;
        }
        currentPoint = map.getBlock(*it);
    }
    return 0;
}

