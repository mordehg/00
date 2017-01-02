#include "TaxiDriver.h"
/*class: TaxiDriver
 * the objects taht holds the taxi, with a few identifying fileds
 */

/*
 * Constructor
 * gets the driver's id, age, status and exprience years
 * returns the build TaxiDriver with the wanted values
 */
TaxiDriver::TaxiDriver(int id, int age, char driverS, int exp, int taxiID){
    this->ID = id;
    this->age = age;
    this->driverStatus = driverS;
    this->exprience = exp;
    this->rankSum = 0;
    this->customerSum = 0;
    this->available = true;
    this->myTaxi = Taxi(taxiID, -1,'S',-1);
}
/*
 * destructor
 * deletes the point.
 */
TaxiDriver::~TaxiDriver() {
}
/*
 * rankAvrage
 * returns the avrange rank of this driver
 */
int TaxiDriver::rankAvrage() {
   return (this->rankSum / this->customerSum);
}
/*
 * addCustomer
 * adding 1 to the drivers customer counter
 */
void TaxiDriver::addCustomer() {
    this->customerSum++;
    this->available = false;
}

/*
 * insertNewTrip
 * insert the given trip to e the drivers current trip
 */
void TaxiDriver::insertNewTrip(TripInfo &trip) {
    trip.attachingADriver();
    this->myTaxi.updateTrip(trip);
    this->available = false;
}

/*
 * getLocation
 * getting the driver current location
 */
Block TaxiDriver::getLocation() {
    if (this->myTaxi.getTaxiID() == -1)
        return Block(Point(0,0));
    return this->myTaxi.getTrip().getCurrent();
}
/*
 * endOfTrip
 * changing the driver location to the end of it's trip
 */
void TaxiDriver::endOfTrip() {
    this->myTaxi.endOfTrip();
    this->available = true;
}

void TaxiDriver::moveTheTaxiOneStep(Map map) {
    this->myTaxi.moveOneStep(map);
}

int TaxiDriver::getTripTime() {
    return this->myTaxi.getTrip().getTripTime();
}