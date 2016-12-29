#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "MainFlow.h"
#include "Client.h"

using namespace boost;
/* insertDriver
 * receives the driver information in strings and translate it
   to a driver. adding the driver to the given taxi center
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

/*
 * insertDriver
 * receives the driver information in strings and translate it
   to a driver. adding the driver to the given taxi center
 */
void Client::insertDriver() {
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


int main() {
    /*Client c = Client();
    c.insertDriver();*/
    /*const char* ip_address = "127.0.0.1";
    const int port_no = 5678;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    char data[] = "hello";
    int data_len = sizeof(data);
    int sent_bytes = sendto(sock, data, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }
    cout << "The server sent: " << buffer << endl;
    close(sock);*/
    Point p = Point(1,2);
    string serial_str;
    iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    s.flush();
    oa << p;
    cout << serial_str << endl;

    Point p2 = Point ();
    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> p2;
    return 0;
}

