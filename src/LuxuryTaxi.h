#ifndef EX2_LUXURYTAXY_H
#define EX2_LUXURYTAXY_H

#include <iostream>
#include "Taxi.h"
#include <fstream>

/**
 * class: LuxuryTaxi
 * this class inheritor from the Taxi class,
   it implements the moveOneStep method only
 */
class LuxuryTaxi : public Taxi {
public:
    /**
     * default constructor
     */
    LuxuryTaxi() { }
    /**
     * Constructor
     * @param the taxi's id, manufacture name, color, price coefficient
     * @return the build taxi with 2 as type, for luxury taxi.
     */
    LuxuryTaxi(int id, char manu, char color);
    /**
     * destructor
     * deletes the luxury taxi.
     */
    ~LuxuryTaxi() { this->~Taxi(); }

    /**
     * moveOnStep
     * @param the map of the game
     * make the taxi movment, for a standard one moves 1
       block, for luxury one moves 2 blocks
     */
    void moveOneStep(Map map);
};
#endif //EX2_LUXURYTAXY_H
