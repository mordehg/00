cmake_minimum_required(VERSION 3.6)
project(ex3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES src/MainFlow.cpp src/MainFlow.h src/main.cpp src/Point.h src/Point.cpp src/Block.h src/Block.cpp src/Map.h src/Map.cpp src/TaxiDriver.h src/Taxi.h src/Passenger.h src/Passenger.cpp src/TripInfo.h src/TaxiDriver.cpp src/Taxi.cpp src/TripInfo.cpp src/TaxiCenter.h src/TaxiCenter.cpp src/StandardTaxi.h src/StandardTaxi.cpp src/LuxuryTaxi.h src/LuxuryTaxi.cpp Tests/TestPoint.cpp Tests/TestBlock.cpp Tests/TestPassenger.cpp Tests/TestMap.cpp Tests/TestTripInfo.cpp Tests/TestTaxiDriver.cpp Tests/TestTaxi.cpp Tests/TestTaxiCenter.cpp)
add_executable(ex3 ${SOURCE_FILES})
target_link_libraries(ex3 gtest gtest_main)