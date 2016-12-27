#ifndef EX2_LUXURYTAXY_H
#define EX2_LUXURYTAXY_H

#include <iostream>
#include "Taxi.h"

/*
 * class: LuxuryTaxi
 * this class inheritor from the Taxi class,
   it implements the moveOneStep method only
 */
class LuxuryTaxi : public Taxi {
public:
    /*
     * default constructor
     */
    LuxuryTaxi() { }
    /*
     * Constructor
     * gets the taxi's id, manufacture name, color, price coefficient
     * returns the build taxi with 2 as type, for luxury taxi.
     */
    LuxuryTaxi(int id, char manu, char color);
    /*
     * destructor
     * deletes the luxury taxi.
     */
    ~LuxuryTaxi() { this->~Taxi(); }

    /*
     * moveOnStep
     * make the taxi moment, for a standard one moves 1
       block, for luxury one moves 2 blocks
     */
    void moveOneStep();
};
#endif //EX2_LUXURYTAXY_H
