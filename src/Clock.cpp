#include "Clock.h"

/** Class: Clock
 * a simple point class, that holds a x any y values
 */

/**
 * default constructor
 * set the time counter to zero
 */
Clock::Clock() {
    this->time = 0;
}

/**
 * timePassed
 * adding one to the time counter, one unit
   of time has passed.
 */
void Clock::timePassed() {
    this->time++;
}

/**
 * currentTime
 * @return the current time fram
 */
int Clock::currentTime() {
    return this->time;
}