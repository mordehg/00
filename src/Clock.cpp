#include "Clock.h"

Clock::Clock() {
    this->time = 0;
}

void Clock::timePassed() {
    this->time++;
}

int Clock::currentTime() {
    return this->time;
}