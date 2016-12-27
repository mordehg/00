cmake_minimum_required(VERSION 3.6)
project(ex4)

set(core_sockets ../ex4/sockets/Socket.cpp ../ex4/sockets/Udp.cpp ../ex4/sockets/Socket.h ../ex4/sockets/Udp.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(SOURCE_FILES_SERVER src/Server.cpp src/MainFlow.cpp src/MainFlow.h src/Point.h src/Point.cpp src/Block.h src/Block.cpp src/Map.h src/Map.cpp src/TaxiDriver.h src/Taxi.h src/Passenger.h src/Passenger.cpp src/TripInfo.h src/TaxiDriver.cpp src/Taxi.cpp src/TripInfo.cpp src/TaxiCenter.h src/TaxiCenter.cpp src/StandardTaxi.h src/StandardTaxi.cpp src/LuxuryTaxi.h src/LuxuryTaxi.cpp src/Server.cpp)
set(SOURCE_FILES_CLIENT src/Client.cpp src/MainFlow.cpp src/MainFlow.h src/Point.h src/Point.cpp src/Block.h src/Block.cpp src/Map.h src/Map.cpp src/TaxiDriver.h src/Taxi.h src/Passenger.h src/Passenger.cpp src/TripInfo.h src/TaxiDriver.cpp src/Taxi.cpp src/TripInfo.cpp src/TaxiCenter.h src/TaxiCenter.cpp src/StandardTaxi.h src/StandardTaxi.cpp src/LuxuryTaxi.h src/LuxuryTaxi.cpp src/Server.cpp)

add_library(sockets ${core_sockets})

add_executable(server ${SOURCE_FILES_SERVER})
add_executable(client ${SOURCE_FILES_CLIENT})

target_link_libraries(server sockets)
target_link_libraries(client sockets)