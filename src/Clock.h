//
// Created by gili on 29/12/16.
//

#ifndef EX4_CLOCK_H
#define EX4_CLOCK_H


class Clock {
private:
    int time;
public:
    Clock();
    void timePassed();
    int currentTime();
    bool Go();
};


#endif //EX4_CLOCK_H
