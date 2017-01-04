#include "TaxiDriver.h"
/**
 * class: TaxiDriver
 * the objects taht holds the taxi, with a few identifying fileds
 */

/**
 * Constructor
 * @param the driver's id, age, status and exprience years
 * @return the build TaxiDriver with the wanted values
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
/**
 * destructor
 * deletes the point.
 */
TaxiDriver::~TaxiDriver() {
}
/**
 * rankAvrage
 * @return the avrange rank of this driver
 */
int TaxiDriver::rankAvrage() {
   return (this->rankSum / this->customerSum);
}
/**
 * addCustomer
 * adding 1 to the drivers customer counter
 */
void TaxiDriver::addCustomer() {
    this->customerSum++;
    this->available = false;
}

/**
 * insertNewTrip
 * @param trip to insert to the taxi
 * insert the given trip to e the drivers current trip
 */
void TaxiDriver::insertNewTrip(TripInfo &trip) {
    trip.attachingADriver();
    this->myTaxi.updateTrip(trip);
    this->available = false;
}

/**
 * getLocation
 * getting the driver current location
 */
Block TaxiDriver::getLocation() {
    return this->myTaxi.getTrip().getCurrent();
}
/**
 * endOfTrip
 * when the driver get to the and of the trip
   he is now available
 */
void TaxiDriver::endOfTrip() {
    this->available = true;
}

/**
 * moveTheTaxiOneStep
 * @param map of the gamw
 * @return 1 - if the trip get to an end
           0 - otherwise
 * moving the taxi one step
 */
int TaxiDriver::moveTheTaxiOneStep(Map map) {
    return this->myTaxi.moveOneStep(map);
}

/**
 * getTripTime
 * @return the trip's time
 */
int TaxiDriver::getTripTime() {
    return this->myTaxi.getTrip().getTripTime();
}