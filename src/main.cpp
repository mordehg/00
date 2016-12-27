#include <iostream>
#include "MainFlow.h"

using namespace std;
int main(int ac, char* av[]) {
    MainFlow flow = MainFlow();
    flow.run();
    return 1;
}
