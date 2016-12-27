cmake_minimum_required(VERSION 3.6)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(SOURCE_FILES src/MainFlow.cpp src/MainFlow.h src/main.cpp src/Point.h src/Point.cpp src/Block.h src/Block.cpp src/Map.h src/Map.cpp src/TaxiDriver.h src/Taxi.h src/Passenger.h src/Passenger.cpp src/TripInfo.h src/TaxiDriver.cpp src/Taxi.cpp src/TripInfo.cpp src/TaxiCenter.h src/TaxiCenter.cpp src/StandardTaxi.h src/StandardTaxi.cpp src/LuxuryTaxi.h src/LuxuryTaxi.cpp)
add_executable(ex4 ${SOURCE_FILES})
