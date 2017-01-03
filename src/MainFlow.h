#ifndef EX2_MAINFLOW_H
#define EX2_MAINFLOW_H

#include "TaxiCenter.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"
#include "Clock.h"
#include <vector>
#include <string>

/**
 * class: MainFlow
 * this class is use to control the input and
   use it correctly.
 */
class MainFlow {
public:
    /**
     * default constructor
     */
    MainFlow();
    /**
     * inputParser
     * receives the input and spared the input by "," and insert
       the strings to a list.
     * @return the list.
     */
    vector<string> inputParser();
    /**
     * obstacles
     * @param obstaclesNum number of obstacles
     * receives the obstacles input and translate it
       to a list of points
     * @return a list of point which is the obstacles
     */
    list<Point> obstacles(int obstaclesNum);
    /**
     * getDriverSendTaxi
     * @param tc the taxi center
     * receives the driver information from the client and adding the
       driver to the given taxi center.
     * sending the taxi to the client.
     */
    void getDriverSendTaxi(TaxiCenter& tc);
    /**
     * insertTrip
     * @param tc the taxi center
     * @param map the game's map
     * receives the trip information in strings and translate it
       to a trip. adding the trip to the given taxi center
     */
    void insertTrip(TaxiCenter& tc, Map &map);
    /**
     * insertTaxi
     * @param tc the taxi center
     * receives the taxi information in strings and translate it
       to a taxi. adding the taxi to the given taxi center
     */
    void insertTaxi(TaxiCenter& tc);
    /**
     * printOutDriver
     * @param tc the taxi center
     * gets an input for a driver id, and prints the
       driver's current location
     */
    void printOutDriverLocation(TaxiCenter &tc);
    /**
     * startDriving
     * @param tc the taxi center
     * move the drivers one step according to their
       trip.
     */
    void startDriving(TaxiCenter &tc);
    /**
     * run
     * responsible to control the input and call the
       needed method
     */
    void run();

};

#endif //EX2_MAINFLOW_H