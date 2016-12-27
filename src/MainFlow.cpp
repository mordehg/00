#include "MainFlow.h"
#include "StandardTaxi.h"
#include "LuxuryTaxi.h"

using namespace std;

/*
 * default constructor
 */
MainFlow::MainFlow() {}

/*
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
    int command;
    do {
        cin >> command;
        if (command == 1)
            insertDriver(taxiCenter);
        else if (command == 2)
            insertTrip(taxiCenter, map);
        else if (command == 3)
            insertTaxi(taxiCenter);
        else if (command == 4)
            printOutDriverLocation(taxiCenter);
        else if (command == 6)
            startDriving(taxiCenter);
        else
            break;
    } while (command != 7);
    return;
}

/*
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

/*
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

/*
 * insertDriver
 * receives the driver information in strings and translate it
   to a driver. adding the driver to the given taxi center
 */
void MainFlow::insertDriver(TaxiCenter& tc) {
    //all the driver's given information will be in a
    //string's vector:
    vector<string> driver_data = inputParser();

    //getting the taxi id for the current driver and saving it:
    string str_vehicle_id = driver_data.back();
    int vehicle_id = atoi(str_vehicle_id.c_str());
    driver_data.pop_back();

    //getting the driver experience and saving it:
    string str_driver_experience = driver_data.back();
    int driver_experience = atoi(str_driver_experience.c_str());
    driver_data.pop_back();

    //getting the driver status and saving it:
    string str_driver_status = driver_data.back();
    const char* statusBuffer = str_driver_status.c_str();
    driver_data.pop_back();

    //getting the drivers age and saving it:
    string str_driver_age = driver_data.back();
    int driver_age = atoi(str_driver_age.c_str());
    driver_data.pop_back();

    //getting the drivers id, and saving it:
    string str_driver_id = driver_data.back();
    int driver_id = atoi(str_driver_id.c_str());
    driver_data.pop_back();

    TaxiDriver new_driver = TaxiDriver(driver_id,driver_age,statusBuffer[0],driver_experience);
    Taxi driversTaxi = tc.getTaxi(vehicle_id);
    new_driver.insertTaxi(driversTaxi);
    tc.addDriver(new_driver);
}

/*
 * insertTrip
 * receives the trip information in strings and translate it
   to a trip. adding the trip to the given taxi center
 */
void MainFlow::insertTrip(TaxiCenter &tc, Map &map) {
    //all the trip's given information will be in a
    //string's vector:
    vector<string> tripData = inputParser();

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
    TripInfo new_trip = TripInfo(trip_id, start, end, numOfPassengers, tariff);
    tc.addTrip(new_trip);
}

/*
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

/*
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

/*
 * startDriving
 * attach a trip to each driver
 * move the drivers to the end of it's trip
 */
void MainFlow::startDriving(TaxiCenter &tc) {
    tc.assignTrips();
    tc.moveAllToend();
}