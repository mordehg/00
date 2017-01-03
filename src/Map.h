#ifndef EX2_MAP_H
#define EX2_MAP_H

#include <iostream>
#include <list>
#include "Block.h"
using namespace std;

/** Class: Map
 * this is the class that holds all the block of the program.
 * all the taxi moves on this block
 */
class Map {
private:
    int numOfBlocks;
    list<Block> blocks;
public:
    /**
     * default constructor
     */
    Map() {}
    /**
     * Constructor
     * @param the sizes of the wanted map
     * build all the block
     * @return the build map with the wanted values.
     */
    Map(int width, int high);

    /**
     * Constructor
     * @param the sizes of the wanted map and a list
       the obstacles in the creating map.
     * build all the block and defining the obstacles ones.
     * @return the build map with the wanted values.
     */
    Map(int width, int high, list<Point> obstacle);
    /**
     * destructor
     * deletes the Map.
     */
    ~Map();
    /**
     * getBlock
     * @param the point value of the wanted Bloack.
     * @return the block with the given value.
     */
    Block getBlock(Point value);
    /**
     * getIndex
     * @param the block we want his index.
     * @return the index of the block in the map.
     */
    int getIndex(Block block);
    /**
     * getIndex
     * @param the point value of the wanted block.
     * @return the index of the block in the map.
     */
    int getIndex(Point blockPoint);
    /**
     * size
     * @return the number of blocks in the map.
     */
    int size() const { return this->numOfBlocks; }
    /**
     * addNeighboursOfCurBlock
     * @param the Block we want to add neighbours to.
     * add all of the block's neighbours who is'nt an
       obstacle to the block.
     * @return the number of neighbours added.
     */
    int addNeighboursOfCurBlock(Block &currentBlock);
    /**
     * BFS
     * @param two Blocks objects, the start one and the target,
     * @return the minimum track from the start to the target, using Breadth-first search.
     */
    list<Point> BFS(Block &start, Block &end);

    /**
     * distanse
     * @return the size of the trip between two blocks
     */
    int distanse(Block &b1, Block &b2);
};
#endif //EX2_MAP_H
