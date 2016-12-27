#ifndef EX2_POINT_H
#define EX2_POINT_H

/* Class: Point
 * a simple point class, that holds a x any y values
 */
class Point {
private:
    int x;
    int y;
public:
    /*
     * default constructor
     */
    Point() {}
    /*
     * Constructor
     * gets two integers: the x value
                          the y value
     * returns: the build point with the wanted values.
     */
    Point(int inputX, int inputY);
    /*
     * destructor
     * deletes the point.
     */
    ~Point() {}

    /*
     * getX
     * returns an integer, the x value
     */
    int getX() const{ return this->x; }
    /*
     * getY
     * returns an integer, the y value
     */
    int getY() const{ return  this->y; }

    /*
     * isNeighbours
     * gets a point, return true if the tow neighbours
       and false otherwise.
     */
    bool isNeighbours(Point other);
    /*
     * override the == operator for points
     */
    const bool operator== (const Point &other);
    //void printPoint();

    void printPoint();
};

#endif //EX2_POINT_H
