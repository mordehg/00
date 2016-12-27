#include "StandardTaxi.h"
/*
 * class: StandartdTaxi
 * this class inheritor from the Taxi class,
   it implements the moveOneStep method only
 */


/*
 * Constructor
 * gets the taxi's id, manufacture name, color, price coefficient
 * returns the build taxi with 1 as type, for luxury taxi.
 */
StandardTaxi::StandardTaxi(int id, char manu, char color) {
    this->ID = id;
    this->carType = 1;
    this->manufactuer = manu;
    this->color = color;
    this->kilometerSum = 0;
    //temp trip for flags:
    Block start = Block(Point(0,0));
    this->currentTrip = TripInfo(-1, start, start, 0, 0);
    this->currentTrip.currentUpdate(start);
}

/*
 * moveOnStep
 * make the taxi moment, for a standard one moves 1
   block, for luxury one moves 2 blocks
 */
void StandardTaxi::moveOneStep() {

}