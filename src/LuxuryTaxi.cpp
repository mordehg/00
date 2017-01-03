#include "LuxuryTaxi.h"

/**
 * Constructor
 * @param the taxi's id, manufacture name, color, price coefficient
 * @return the build taxi with 2 as type, for luxury taxi.
 */
LuxuryTaxi::LuxuryTaxi(int id, char manu, char color) {
    this->ID = id;
    this->carType = 2;
    this->manufactuer = manu;
    this->color = color;
    this->kilometerSum = 0;
    //temp trip for flags:
    Block start = Block(Point(0,0));
    this->currentTrip = TripInfo(-1, start, start, 0, 0, 0);
    this->currentTrip.currentUpdate(start);
}

/**
 * moveOnStep
 * @param the map of the game
 * make the taxi movment, for a standard one moves 1
   block, for luxury one moves 2 blocks
 */
void LuxuryTaxi::moveOneStep(Map map) {
    this->currentTrip.updateCurrentOneStep(2, map);
}