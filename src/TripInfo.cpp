#include <iostream>
#include <list>
#include "TripInfo.h"
using namespace std;

/*class: TripInfo
 * the objects that holds all the important information for the trip
 */

/*
 * Constructor
 * gets the trip id, the start block, the end block and the tip's price
 * returns the build trip with the wanted values
 */
TripInfo::TripInfo(int id, Block &startB, Block &endB, int passNum, double price) {
    this->ID = id;
    this->passengersNum = passNum;
    this->start = startB;
    this->end = endB;
    this->tariff = price;
    this->currentPoint = startB;
}
/*
 * destructor
 * deletes the TripInfo.
 */
TripInfo::~TripInfo() {
}

/*
 * fullTrack
 * returns the full track of the trip, from start to end
 */
list<Point>* TripInfo::fullTrack() {
    return &(this->fullTrip);
}
/*
 * fullTrackLenght
 * returns the lenght of the full track
 */
int TripInfo::fullTrackLenght() {
    return this->fullTrip.size();
}
/*
 * trackAhead
 * returns the track from the current point to the end
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
/*
 * tracklAheadLength
 * returns the length of the track ahead
 */
int TripInfo::tracklAheadLength() {
    return (int)(tracklAhead().size());
}
/*
 * trackBehaind
 * returns the track from the start to the currnet point
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
/*
 * trackBehaindLength
 * returns the length of the trackbehaind
 */
int TripInfo::trackBehaindLength() {
    return (int)(trackBehaind().size());
}

void TripInfo::insertFullTrack(list<Point> &track) {
    this->fullTrip = track;
}

