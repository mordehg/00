#ifndef EX2_PASSENGER_H
#define EX2_PASSENGER_H

#include <iostream>
#include "Block.h"
#include <list>

/*
 * class: Passenger
 * a start and an end point represent a passenger
 */
class Passenger{
private:
    Block start;
    Block end;
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & start;
        ar & end;
    }
public:
    /*
     * default constructor
     */
    Passenger() { }
    /*
     * Constructor
     * gets a block for start and a block for end
     * returns: the build Passenger with the wanted values.
     */
    Passenger(Block start, Block end);
    /*
     * destructor
     * deletes the Map.
     */
    ~Passenger();
    /*
     * getRank
     * returns a random number from 1 to 5 to
       rank the taxi's driver
     */
    int getRank();
    /*
     * getStart
     * return ths start block
     */
    Block getStart() { return this->start; }
    /*
     * getEnd
     * return the end block
     */
    Block getEnd() { return this->end; }
};
#endif //EX2_PASSENGER_H
