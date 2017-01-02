#ifndef EX2_STANDARDTAXI_H
#define EX2_STANDARDTAXI_H

#include <iostream>
#include "Taxi.h"

/*
 * class: StandartdTaxi
 * this class inheritor from the Taxi class,
   it implements the moveOneStep method only
 */
class StandardTaxi : public Taxi {
public:
    /*
     * default constructor
     */
    StandardTaxi() { }
    /*
     * Constructor
     * gets the taxi's id, manufacture name, color, price coefficient
     * returns the build taxi with 1 as type, for luxury taxi.
     */
    StandardTaxi(int id, char manu, char color);
    /*
     * destructor
     * deletes the standard taxi.
     */
    ~StandardTaxi() { this->~Taxi(); }

    /*
     * moveOnStep
     * make the taxi moment, for a standard one moves 1
       block, for luxury one moves 2 blocks
     */
    void moveOneStep(Map map);
};
#endif //EX2_STANDARDTAXI_H
