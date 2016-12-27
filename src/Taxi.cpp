#include "Taxi.h"
#include "LuxuryTaxi.h"

/*
 *class: Taxi
 * the "father" class for taxi.
 * all of the method are implementers except for moveOneStep
   that is different in different taxis.
 */

/*
 * Constructor
 * gets the taxi's id, manufacture name, color, price coefficient and type,
   1 - for standard and 2 - for luxury.
 * returns the build taxi with the wanted values.
 */
Taxi::Taxi(int id, int type, char manu, char taxiColor) {
    this->ID = id;
    this->manufactuer = manu;
    this->color = taxiColor;
    this->carType = type;
    this->kilometerSum = 0;
    Block start = Block(Point(0,0));
    this->currentTrip = TripInfo(-1, start, start, 0, 0);
    this->currentTrip.currentUpdate(start);
}

/*
 * destructor
 * deletes the point.
 */
Taxi::~Taxi() {
}

/*
 * finalPrice
 * returns the final price: the final calculated price.
 */
int Taxi::finalPrice() {
    return (this->priceCoffcient * this->currentTrip.getPrice());
}
/*
 * override the == operator for taxis
 */
bool Taxi::operator==(Taxi other) {
    if (this->ID == other.getTaxiID())
        return true;
    return false;
}

/*
 * endOfTrip
 * change the current location of the taxi to
   the end of the trip
 */
void Taxi::endOfTrip() {
    this->currentTrip.currentUpdate(this->currentTrip.getEndPoint());
}

/*
 * moveOnStep
 * make the taxi moment, for a standard one moves 1
   block, for luxury one moves 2 blocks
 * not implemented, the sons will implement as needed.
 */
void Taxi::moveOneStep() {

}