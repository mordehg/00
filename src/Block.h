#ifndef EX2_BLOCK_H
#define EX2_BLOCK_H

#include "Point.h"

/* Class: Block
 *  Block keep his Point value, an array of his
    neighbours and number of neighbours.
 */
class Block {
private:
    Point value;
    Point neighbours[4];
    int neighboursNum;
    bool obstacle;
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & value;
        ar & neighbours;
        ar & obstacle;
    }
public:
    /*
     * default constructor
     */
    Block() { }
    /*
     * Constructor
     * gets the point value
     * returns: the build Block with the wanted values.
     */
    Block(Point p);

    /*
     * destructor
     * deletes the Block.
     */
    ~Block();

    bool isObstacles() { return this->obstacle; }

    void setIsObstacles(bool flag) {this->obstacle = flag; }

    /*
     * getValue
     * return the Point value of the Block*/
    Point getValue() const{ return this->value; }
    /*
     * getNeighboursNum
     * returns number of neighbours
     */
    int getNeighboursNum() { return this->neighboursNum; }
    /*
     * settNeighboursNum
     * get a new neighbours number and sets the neighboursNum field.
     */
    void setNeighboursNum(int newNum) { this->neighboursNum = newNum; }
    /*
     * getNeighbour
     * get the wanted neighbour's index
     * returns the Point that is the wanted neighbour
     */
    Point getNeighbour(int i);
    /*
     * insertNeighbour
     * get an index and a Block.
     * inserts the given block's value in to the neighbours list in the index place.
     */
    void insertNeighbour(int index, Block neighbour);
     /*
      * override the == operator for blocks
      */
    const bool operator== (const Block &other);

};
#endif //EX2_BLOCK_H
