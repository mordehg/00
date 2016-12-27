#include <iostream>
#include "MainFlow.h"
#include <gtest/gtest.h>
#include "Map.h"
#include "TaxiCenter.h"
#include "LuxuryTaxi.h"

using namespace std;
int main(int ac, char* av[]) {
    MainFlow flow = MainFlow();
    flow.run();
    return 1;
}
