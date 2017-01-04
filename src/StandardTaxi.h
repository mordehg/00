#ifndef EX2_STANDARDTAXI_H
#define EX2_STANDARDTAXI_H

#include <iostream>
#include "Taxi.h"

/**
 * class: StandartdTaxi
 * this class inheritor from the Taxi class,
   it implements the moveOneStep method only
 */
class StandardTaxi : public Taxi {
public:
    /**
     * default constructor
     */
    StandardTaxi() { }
    /**
     * Constructor
     * @param the taxi's id, manufacture name, color, price coefficient
     * @return the build taxi with 1 as type, for luxury taxi.
     */
    StandardTaxi(int id, char manu, char color);
    /**
     * destructor
     * deletes the standard taxi.
     */
    ~StandardTaxi() { this->~Taxi(); }

    /**
     * moveOnStep
     * @param the map of the game.
     * make the taxi moment, for a standard one moves 1
       block, for luxury one moves 2 blocks
     * @return 1 - if the trip get to an end
               0 - otherwise
     */
    int moveOneStep(Map map);
};
#endif //EX2_STANDARDTAXI_H
