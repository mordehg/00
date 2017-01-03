#ifndef EX4_CLOCK_H
#define EX4_CLOCK_H

/** Class: Clock
 * a simple point class, that holds a x any y values
 */
class Clock {
private:
    int time;
public:
    /**
     * default constructor
     * set the time counter to zero
     */
    Clock();

    /**
     * timePassed
     * adding one to the time counter, one unit
       of time has passed.
     */
    void timePassed();

    /**
     * currentTime
     * @return the current time fram
     */
    int currentTime();
};


#endif //EX4_CLOCK_H
