#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Server.h"
#include "MainFlow.h"
#include "../sockets/Udp.h"
using namespace std;

/**
 * default constructor
 */
MainFlow::MainFlow() {}

/**
 * run
 * responsible to control the input and call the
   needed method
 */
void MainFlow::run() {
    int size_x;
    int size_y;
    //the first input the map size:
    cin >> size_x;
    cin >> size_y;

    //second input - number of obstacles:
    int obstaclesNum;
    cin >> obstaclesNum;

    Clock clock = Clock();
    TaxiCenter taxiCenter;
    Map map;
    if (!obstaclesNum) {
        //if there is no obstacles:
        map = Map(size_x, size_y);
        taxiCenter = TaxiCenter(map);
    } else {
        //if there is obstacles:
        //build a point list with the given obstacles:
        list<Point> obstacleList = obstacles(obstaclesNum);
        map = Map(size_x, size_y, obstacleList);
        taxiCenter = TaxiCenter(map);
    }

    //getting a number for different actions :
    int command, driversNum = 0;
    do {
        cin >> command;
        if (command == 1) {
            cin >> driversNum;
            for (int i = 0; i < driversNum; i++) {
                getDriverSendTaxi(taxiCenter);
            }
        }
        else if (command == 2)
            insertTrip(taxiCenter, map);
        else if (command == 3)
            insertTaxi(taxiCenter);
        else if (command == 4)
            printOutDriverLocation(taxiCenter);
        else if (command == 6)
            startDriving(taxiCenter);
        else if (command == 9) {
            clock.timePassed();
            TripInfo thisTimeTrip = taxiCenter.getTripByTime(clock.currentTime());
            if (thisTimeTrip.getID() != -1) {
                taxiCenter.assignAvaliableDriver(thisTimeTrip);
            }
            taxiCenter.moveAllOneStep(map, clock);
            cout << taxiCenter.getTaxiDriver(0).driverAvailable();
        }
        else
            break;
    } while (command != 7);
    return;
}

/**
 * inputParser
 * receives the input and spared the input by "," and insert
   the strings to a list.
 * returns the list.
 */
vector<string> MainFlow::inputParser() {
    vector<string> data;
    string input;
    cin >> input;
    int startPos = 0;
    int i = 0;
    string current_str;
    while (input.length() != i) {
        if (input[i] == ',') {
            int len = i-startPos;
            current_str = input.substr(startPos,len);
            data.push_back(current_str);
            startPos = i+1;
        }
        i++;
    }
    current_str = input.substr(startPos,i-startPos+1);
    data.push_back(current_str);
    return data;
}

/**
 * obstacles
 * receives the obstacles input and translate it
   to a list of points
 * returns a list of point which is the obstacles
 */
list<Point> MainFlow::obstacles(int obstaclesNum) {
    list <Point> returnList;
    for (int i = 0; i < obstaclesNum; i++) {
        vector<string> obstacle_data = inputParser();
        string strY = obstacle_data.back();
        int y = atoi(strY.c_str());
        obstacle_data.pop_back();
        string strX = obstacle_data.back();
        int x = atoi(strX.c_str());
        obstacle_data.pop_back();
        Point point = Point(x, y);
        returnList.push_back(point);
    }
    return returnList;
}

/**
 * insertDriver
 * receives the driver information in strings and translate it
   to a driver. adding the driver to the given taxi center
 */
void MainFlow::getDriverSendTaxi(TaxiCenter& tc) {
    char buffer[4096];
    Socket* socket = new Udp(true,5008);
    socket->initialize();

    //getting the driver from the client
    int dataSize = socket->reciveData(buffer, 4096);
    TaxiDriver driver;
    boost::iostreams::basic_array_source<char> device(buffer, dataSize);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> driver;
    Taxi driversTaxi = tc.getTaxi(driver.getTaxiID());
    driver.insertTaxi(driversTaxi);
    tc.addDriver(driver);

    //serial the taxi:
    string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << driversTaxi;
    s.flush();
    //send the taxi:
    socket->sendData(serial_str);

    delete(socket);
}

/**
 * insertTrip
 * receives the trip information in strings and translate it
   to a trip. adding the trip to the given taxi center
 */
void MainFlow::insertTrip(TaxiCenter &tc, Map &map) {
    //all the trip's given information will be in a
    //string's vector:
    vector<string> tripData = inputParser();

    //getting the trip's time to start:
    string str_time = tripData.back();
    int time = atoi(str_time.c_str());
    tripData.pop_back();

    //getting the tariff and saving it:
    string str_tariff = tripData.back();
    int tariff = atoi(str_tariff.c_str());
    tripData.pop_back();

    //getting the number of passengers and saving it:
    string str_numOfPassengers = tripData.back();
    int numOfPassengers = atoi(str_numOfPassengers.c_str());
    tripData.pop_back();

    //getting the end point information and saving it:
    string str_endY = tripData.back();
    int endY = atoi(str_endY.c_str());
    tripData.pop_back();
    string str_endX = tripData.back();
    int endX = atoi(str_endX.c_str());
    tripData.pop_back();
    Point end_point = Point(endX, endY);

    //getting the start point information and saving it:
    string str_startY = tripData.back();
    int startY = atoi(str_startY.c_str());
    tripData.pop_back();
    string str_startX = tripData.back();
    int startX = atoi(str_startX.c_str());
    tripData.pop_back();
    Point start_point = Point(startX, startY);

    //getting the trip id and saving it:
    string str_trip_id = tripData.back();
    int trip_id = atoi(str_trip_id.c_str());
    tripData.pop_back();

    Block start = map.getBlock(start_point);
    Block end = map.getBlock(end_point);
    TripInfo new_trip = TripInfo(trip_id, start, end, numOfPassengers, tariff, time);
    tc.addTrip(new_trip);
}

/**
 * insertTaxi
 * receives the taxi information in strings and translate it
   to a taxi. adding the taxi to the given taxi center
 */
void MainFlow::insertTaxi(TaxiCenter &tc) {
    //all the taxi's given information will be in a
    //string's vector:
    vector<string> taxiData = inputParser();

    //getting the taxi color and saving it:
    string str_taxi_color = taxiData.back();
    const char* color_buffer = str_taxi_color.c_str();
    taxiData.pop_back();

    //getting the taxi manufacture and saving it:
    string str_taxi_manu = taxiData.back();
    const char* manu_buffer = str_taxi_manu.c_str();
    taxiData.pop_back();

    //getting the taxi type and saving it:
    string str_taxi_type = taxiData.back();
    int taxi_type = atoi(str_taxi_type.c_str());
    taxiData.pop_back();

    //getting the taxi id and saving it:
    string str_taxi_id = taxiData.back();
    int taxi_id = atoi(str_taxi_id.c_str());
    taxiData.pop_back();

    if (taxi_type == 1) {
        StandardTaxi taxi = StandardTaxi(taxi_id, manu_buffer[0], color_buffer[0]);
        tc.addTaxi(taxi);
    } else{
        LuxuryTaxi taxi = LuxuryTaxi(taxi_id, manu_buffer[0], color_buffer[0]);
        tc.addTaxi(taxi);
    }
}

/**
 * printOutDriver
 * gets an input for a driver id, and prints the
   driver's current location
 */
void MainFlow::printOutDriverLocation(TaxiCenter &tc) {
    string driverID;
    cin >> driverID;
    int id = atoi(driverID.c_str());

    tc.getTaxiDriver(id).getLocation().getValue().printPoint();
}

/**
 * startDriving
 * attach a trip to each driver
 * move the drivers to the end of it's trip
 */
void MainFlow::startDriving(TaxiCenter &tc) {
    tc.assignTrips();
    tc.moveAllToend();
}