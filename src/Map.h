#ifndef EX2_MAP_H
#define EX2_MAP_H

#include <iostream>
#include <list>
#include "Block.h"
using namespace std;

/* Class: Map
 * this is the class that holds all the block of the program.
 * all the taxi moves on this block
 */
class Map {
private:
    int numOfBlocks;
    list<Block> blocks;
public:
    /*
     * default constructor
     */
    Map() {}
    /*
     * Constructor
     * gets the sizes of the wanted map
     * build all the block
     * returns: the build map with the wanted values.
     */
    Map(int width, int high);

    Map(int width, int high, list<Point> obstacle);
    /*
     * destructor
     * deletes the Map.
     */
    ~Map();
    /*
     * getBlock
     * gets the point value of the wanted Bloack.
     * returns the block with the given value.
     */
    Block getBlock(Point value);
    /*
     * getIndex
     * gets the block we want his index.
     * returns the index of the block in the map.
     */
    int getIndex(Block block);
    /*
     * getIndex
     * gets the point value of the wanted block.
     * returns the index of the block in the map.
     */
    int getIndex(Point blockPoint);
    /*
     * size
     * returns the number of blocks in the map.
     */
    int size() const { return this->numOfBlocks; }
    /*
     * addNeighboursOfCurBlock
     * gets the Block we want to add neighbours to.
     * add all of the block's neighbours who is'nt an
       obstacle to the block.
     * returns the number of neighbours added.
     */
    int addNeighboursOfCurBlock(Block &currentBlock);
    /* BFS
     * gets two Blocks objects, the start one and the target,
     * returns the minimum track from the start to the target, using Breadth-first search.
     */
    list<Point> BFS(Block &start, Block &end);

    /*
     * distanse
     * returns the size of the trip between two blocks
     */
    int distanse(Block &b1, Block &b2);
};
#endif //EX2_MAP_H
