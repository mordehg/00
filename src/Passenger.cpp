#include "Passenger.h"

/*
 * class: Passenger
 * a start and an end point represent a passenger
 */

/*
 * Constructor
 * gets a block for start and a block for end
 * returns: the build Passenger with the wanted values.
 */
Passenger::Passenger(Block start, Block end) {
    this->start = start;
    this->end = end;
}
/*
 * destructor
 * deletes the Map.
 */
Passenger::~Passenger() {
}

/*
 * getRank
 * returns a random number from 1 to 5 to
   rank the taxi's driver
 */
int Passenger::getRank() {
    return rand() % 5 + 1;
}
