#include "Block.h"
/**
 * Class: Block
 * Block keep his Point value, an array of his
   neighbours and number of neighbours.
 */

/**
 * Constructor
 * @param the point value
 * @return the build Block with the wanted values.
 */
Block::Block(Point p) {
    this->value = p;
    this->obstacle = false;
}

/**
 * destructor
 * deletes the Block.
 */
Block::~Block() {
}

/**
 * insertNeighbour
 * @param an index and a Block.
 * inserts the given block's value in to the neighbours list in the index place.
 */
void Block::insertNeighbour(int index, Block neighbour) {
    this->neighbours[index] = neighbour.getValue();
}

/**
 * override the == operator for blocks
 */
const bool Block::operator== (const Block &other) {
    if (this->value == other.getValue()) {
        return true;
    }
    return false;
}

/**
 * getNeighbour
 * @param the wanted neighbour's index
 * @return the Point that is the wanted neighbour
 */
Point Block::getNeighbour(int i) {
    return this->neighbours[i];
}
