#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "MainFlow.h"
#include "Client.h"
#include "../sockets/Udp.h"
#include "boost/serialization/export.hpp"
BOOST_CLASS_EXPORT_GUID(StandardTaxi,"StandardTaxi");
BOOST_CLASS_EXPORT_GUID(LuxuryTaxi,"LuxuryTaxi");

using namespace boost;
/**
 * inputParser
 * receives the input and spared the input by "," and insert
   the strings to a list.
 * @return the list.
 */
vector<string> Client::inputParser() {
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
* createDriver
* receives the driver information in strings and translate it
  to a driver.
*/
void Client::createDriver() {
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

    TaxiDriver new_driver = TaxiDriver(driver_id,driver_age,statusBuffer[0],driver_experience,vehicle_id);
    this->driver = new_driver;
}

/**
 * the client's main methode
 */
int main() {
    //first, getting the driver from the console and creating it
    Client c = Client();
    c.createDriver();

    char buffer[4096];
    Socket* socket = new Udp(false,5008);
    socket->initialize();

    //serial the driver:
    string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    TaxiDriver driver_to_send = c.getDriver();
    oa << driver_to_send;
    s.flush();
    //send the driver
    socket->sendData(serial_str);

    //getting the taxi from the server
    int dataSize = socket->reciveData(buffer, 4096);
    Taxi taxi;
    boost::iostreams::basic_array_source<char> device(buffer, dataSize);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> taxi;
    c.getDriver().insertTaxi(taxi);

    delete(socket);
    return 0;
}
