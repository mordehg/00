#ifndef EX2_TAXI_H
#define EX2_TAXI_H

#include <iostream>
#include "TripInfo.h"
#include <list>
using namespace std;

/**
 *class: Taxi
 * the "father" class for taxi.
 * all of the method are implementers except for moveOneStep
   that is different in different taxis.
 */
class Taxi {
protected:
    int ID;
    int kilometerSum;
    TripInfo currentTrip;
    char manufactuer;
    char color;
    int priceCoffcient;
    int carType;
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & ID;
        ar & kilometerSum;
        ar & currentTrip;
        ar & manufactuer;
        ar & color;
        ar & priceCoffcient;
        ar & carType;
    }
public:
    /**
     * default constructor
     */
    Taxi() { }
    /**
     * Constructor
     * @param the taxi's id, manufacture name, color, price coefficient and type,
       1 - for standard and 2 - for luxury.
     * @return the build taxi with the wanted values.
     */
    Taxi(int id, int type, char manu, char taxiColor);
    /**
     * destructor
     * deletes the point.
     */
    ~Taxi();
    /**
     * getTaxiID
     * @return the ID of the taxi
     */
    int getTaxiID() { return this->ID; }
    /**
     * getKilometerSum
     * @param the number of kilometers this taxi drove.
     */
    int getKilometerSum() { return this->kilometerSum; }
    /**
     * getCarManufactuer
     * @return the car's manufactuer
     */
    char getCarManufactuer() { return this->manufactuer; }
    /**
     * getColor
     * @return tha taxi's color.
     */
    char getColor() { return this->color; }
    /**
     * getPriceCofficent
     * @return the taxi coffiecent to add to the fina trip price
     */
    int getPriceCoeffcient() { return this->priceCoffcient; }
    /**
     * addKilometer
     * adding one to the kilometer sum of the taxi
     */
    void addKilometer() { this->kilometerSum++; }

    /**
     * updateTrip
     * @return a new trip and set the taxi's trip eith it
     */
    void updateTrip(TripInfo &newTrip) { this->currentTrip = newTrip; }
    /**
     * getTrip
     * @return the taxi's current trip
     */
    TripInfo getTrip() { return this->currentTrip; }
    /**
     * finalPrice
     * @return the final price: the final calculated price.
     */
    int finalPrice();

    /**
     * moveOnStep
     * @param the map of the game.
     * make the taxi moment, for a standard one moves 1
       block, for luxury one moves 2 blocks
     * @return 1 - the end of the trip, 0 - otherwisw
     */
    virtual int moveOneStep(Map map);

    /**
     * override the == operator for taxis
     */
    bool operator==(Taxi other);

    /**
     * setPrice
     * @return a new price for the taxi and set the current price
     */
    void setPrice(int price) { this->priceCoffcient = price; }

    /**
     * endOfTrip
     * change the current location of the taxi to
       the end of the trip
     */
    void endOfTrip();

};
#endif //EX2_TAXI_H
