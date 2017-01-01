#ifndef EX2_TRIPINFO_H
#define EX2_TRIPINFO_H

#include <iostream>
#include "Map.h"
#include <list>
#include <boost/serialization/list.hpp>
using namespace std;

/*class: TripInfo
 * the objects that holds all the important information for the trip
 */
class TripInfo {
private:
    int ID;
    int passengersNum;
    Block currentPoint;
    list<Point> fullTrip;
    Block start;
    Block end;
    double tariff;
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & ID;
        ar & passengersNum;
        ar & currentPoint;
        ar & fullTrip;
        ar & start;
        ar & end;
        ar & tariff;
    }
public:
    /*
     * default constructor
     */
    TripInfo() { }
    /*
     * Constructor
     * gets the trip id, the start block, the end block and the tip's price
     * returns the build trip with the wanted values
     */
    TripInfo(int id, Block &startB, Block &endB, int passNum, double price);
    /*
     * destructor
     * deletes the TripInfo.
     */
    ~TripInfo();
    /*
     * fullTrack
     * returns the fuul track of the trip, from start to end
     */
    list<Point>* fullTrack();
    /*
     * fullTrackLenght
     * returns the lenght of the full track
     */
    int fullTrackLenght();
    /*
     * trackAhead
     * returns the track from the current point to the end
     */
    list<Point> tracklAhead();
    /*
     * tracklAheadLength
     * returns the length of the track ahead
     */
    int tracklAheadLength();
    /*
     * trackBehaind
     * returns the track from the start to the currnet point
     */
    list<Point> trackBehaind();
    /*
     * trackBehaindLength
     * returns the length of the trackbehaind
     */
    int trackBehaindLength();
    /*
     * getID
     * returns the ID of the trip
     */
    int getID() { return this->ID; };
    /*
     * getStartPoint
     * returns the start Block
     */
    Block getStartPoint() { return this->start; }
    /*
     * getEndPoint
     * returns the end Block
     */
    Block getEndPoint() { return this->end; }
    /*
     * getPrice
     * returns the trip's price
     */
    int getPrice() { return this->tariff; }
    /*
     * getCurrent
     * returns the current point of the trip
     */
    Block getCurrent() { return  this->currentPoint; }
    /*
     * currentUpdate
     * updates the current point with the given block
     */
    void currentUpdate(Block current) { this->currentPoint = current; }
    /*
     * setPrice
     * sets the trip's price with the given new price
     */
    void setPrice(int newPrice) { this->tariff = newPrice; }

    void insertFullTrack(list<Point> &track);
};
#endif //EX2_TRIPINFO_H
