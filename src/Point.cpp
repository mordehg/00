#include <iostream>
#include "Point.h"

/* Class: Point
 * a simple point class, that holds a x any y values
 */

/*
 * Constructor
 * gets two integers: the x value
                      the y value
 * returns: the build point with the wanted values.
 */
Point::Point(int inputX, int inputY) {
    this->x = inputX;
    this->y = inputY;
}

/*
 * override the == operator for points
 */
const bool Point::operator==(const Point &other) {
    if (this->x == other.getX() && this->y == other.getY()) {
        return true;
    }
    return false;
}

/*
 * isNeighbours
 * gets a point, return true if the tow neighbours
   and false otherwise.
 */
bool Point::isNeighbours(Point other) {
    if ((this->x - other.getX() == 1) || (other.getX() - this->x == 1)) {
        if (this->y == other.getY())
            return true;
    } else {
        if ((this->y - other.getY() == 1) || (other.getY() - this->y == 1)) {
            if (this->x == other.getX())
                return true;
        }
    }
    return false;
}


void Point::printPoint() {
    cout << "(" << this->x << "," << this->y << ")" << endl;
}
