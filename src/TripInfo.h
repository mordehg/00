#ifndef EX2_TRIPINFO_H
#define EX2_TRIPINFO_H

#include <iostream>
#include "Map.h"
#include <list>
#include <boost/serialization/list.hpp>
using namespace std;

/**
 * class: TripInfo
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
    int tripTime;
    bool beenAttachToDriver;
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
        ar & tripTime;
    }
public:
    /**
     * default constructor
     */
    TripInfo() { }
    /**
     * Constructor
     * @param the trip id, the start block, the end block, the tip's price
       and start time.
     * @return the build trip with the wanted values
     */
    TripInfo(int id, Block &startB, Block &endB, int passNum, double price, int time);
    /**
     * destructor
     * deletes the TripInfo.
     */
    ~TripInfo();
    /**
     * fullTrack
     * @return the fuul track of the trip, from start to end
     */
    list<Point>* fullTrack();
    /**
     * fullTrackLenght
     * @return the lenght of the full track
     */
    int fullTrackLenght();
    /**
     * trackAhead
     * @return the track from the current point to the end
     */
    list<Point> tracklAhead();
    /**
     * tracklAheadLength
     * @return the length of the track ahead
     */
    int tracklAheadLength();
    /**
     * trackBehaind
     * @return the track from the start to the currnet point
     */
    list<Point> trackBehaind();
    /**
     * trackBehaindLength
     * @return the length of the trackbehaind
     */
    int trackBehaindLength();
    /**
     * getID
     * @return the ID of the trip
     */
    int getID() { return this->ID; };
    /**
     * getStartPoint
     * @return the start Block
     */
    Block getStartPoint() { return this->start; }
    /**
     * getEndPoint
     * @return the end Block
     */
    Block getEndPoint() { return this->end; }
    /**
     * getPrice
     * @return the trip's price
     */
    int getPrice() { return this->tariff; }
    /**
     * getCurrent
     * @return the current point of the trip
     */
    Block getCurrent() { return  this->currentPoint; }
    /**
     * currentUpdate
     * @param current Block to update
     * updates the current point with the given block
     */
    void currentUpdate(Block current) { this->currentPoint = current; }
    /**
     * setPrice
     * @param newPrice to update the price
     * sets the trip's price with the given new price
     */
    void setPrice(int newPrice) { this->tariff = newPrice; }
    /**
     * insertFullTrack
     * @param track to insert to the trip
     * inserting the givven track (list of point) to
       the trip information
     */
    void insertFullTrack(list<Point> &track);

    /**
     * getTripTime
     * @return the start time of the trip
     */
    int getTripTime() { return this->tripTime; }

    /**
     * hasADriver
     * @return true if the trip has a driver and false
       otherwise
     */
    bool hasADriver() { return this->beenAttachToDriver; }

    /**
     * attachingADriver
     * stting the has a driver flag
     */
    void attachingADriver() { this->beenAttachToDriver = true; }

    /**
     * updateCurrentOneStep
     * @param taxiType 1 or 2 for the number of blocks to move
     * @param map of the game
     * @return 1 - the end of the trip, 0 - otherwisw
     * moving the current point one step
     */
    int updateCurrentOneStep(int taxiType, Map map);
};
#endif //EX2_TRIPINFO_H
