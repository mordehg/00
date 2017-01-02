#ifndef EX2_MAINFLOW_H
#define EX2_MAINFLOW_H

#include "TaxiCenter.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"
#include "Clock.h"

#include <vector>
#include <string>

/*
 * class: MainFlow
 * this class is use to control the input and
   use it correctly.
 */
class MainFlow {
public:
    /*
     * default constructor
     */
    MainFlow();
    /*
     * inputParser
     * receives the input and spared the input by "," and insert
       the strings to a list.
     * returns the list.
     */
    vector<string> inputParser();
    /*
     * obstacles
     * receives the obstacles input and translate it
       to a list of points
     * returns a list of point which is the obstacles
     */
    list<Point> obstacles(int obstaclesNum);
    /*
     * insertDriver
     * receives the driver information in strings and translate it
       to a driver. adding the driver to the given taxi center
     */
    void getDriverSendTaxi(TaxiCenter& tc);
    /*
     * insertTrip
     * receives the trip information in strings and translate it
       to a trip. adding the trip to the given taxi center
     */
    void insertTrip(TaxiCenter& tc, Map &map);
    /*
     * insertTaxi
     * receives the taxi information in strings and translate it
       to a taxi. adding the taxi to the given taxi center
     */
    void insertTaxi(TaxiCenter& tc);
    /*
     * printOutDriver
     * gets an input for a driver id, and prints the
       driver's current location
     */
    void printOutDriverLocation(TaxiCenter &tc);
    /*
     * startDriving
     * attach a trip to each driver
     * move the drivers to the end of it's trip
     */
    void startDriving(TaxiCenter &tc);
    /*
     * run
     * responsible to control the input and call the
       needed method
     */
    void run();

};

#endif //EX2_MAINFLOW_H