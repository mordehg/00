#include "Map.h"
#include <queue>
#include <stack>
using namespace std;

/* Class: Map
 * this is the class that holds all the block of the program.
 * all the taxi moves on this block
 */

/*
 * Constructor
 * gets the sizes of the wanted map
 * build all the block
 * returns: the build map with the wanted values.
 */
Map::Map(int width, int high) {
    this->numOfBlocks = width * high;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < high; j++) {
            Point value = Point(i,j);
            Block block = Block(value);
            this->blocks.push_back(block);
        }
    }
    std::list<Block>::iterator it;
    for (it = this->blocks.begin(); it != this->blocks.end(); it++) {
        it->setNeighboursNum(addNeighboursOfCurBlock(*it));
    }
}

Map::Map(int width, int high, list<Point> obstacle) {
    this->numOfBlocks = width * high;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < high; j++) {
            Point value = Point(i,j);
            Block block = Block(value);
            list<Point>::iterator it;
            for(it = obstacle.begin(); it != obstacle.end(); it++) {
                if (value == *it)
                    block.setIsObstacles(true);
            }
            this->blocks.push_back(block);
        }
    }
    std::list<Block>::iterator it;
    for (it = this->blocks.begin(); it != this->blocks.end(); it++) {
        it->setNeighboursNum(addNeighboursOfCurBlock(*it));
    }
}

/*
 * destructor
 * deletes the Map.
 */
Map::~Map() {
}

/*
 * getBlock
 * gets the point value of the wanted Bloack.
 * returns the block with the given value.
 */
Block Map::getBlock(Point value){
    std::list<Block>::iterator it;
    for(it = this->blocks.begin(); it != this->blocks.end(); it++) {
        if (value == it->getValue()) {
            return *it;
        }
    }
    return Block(Point(-1,-1));
}

/*
 * getIndex
 * gets the block we want his index.
 * returns the index of the block in the map.
 */
int Map::getIndex(Block block) {
    //go throw all the vertices
    std::list<Block>::iterator it;
    int i = 0;
    for (it = this->blocks.begin(); it != this->blocks.end(); ++it,i++) {
        if (block == *it) {
            //if the current one values matches to the given values, return the current's  index
            return i;

        }
    }
    //if there is not a vertex like that, return -1 as a flag.
    return -1;
}

/*
 * getIndex
 * gets the point value of the wanted block.
 * returns the index of the block in the map.
 */
int Map::getIndex(Point blockPoint) {
    std::list<Block>::iterator it;
    int i = 0;
    for (it = this->blocks.begin(); it != this->blocks.end(); ++it,i++) {
        if (blockPoint == it->getValue()) {
            //if the current one values matches to the given values, return the current's  index
            return i;

        }
    }
    //if there is not a vertex like that, return -1 as a flag.
    return -1;
}

/*
 * addNeighboursOfCurBlock
 * gets the Block we want to add neighbours to.
 * add all of the block's neighbours who is'nt an
   obstacle to the block.
 * returns the number of neighbours added.
 */
int Map::addNeighboursOfCurBlock(Block& currentBlock) {
    //the current block values.
    int x = currentBlock.getValue().getX();
    int y = currentBlock.getValue().getY();

    //getting all the block's neighbours
    Block leftNeighb = this->getBlock(Point(x-1,y));
    Block rightNeighb = this->getBlock(Point(x+1,y));
    Block neighbAbove = this->getBlock(Point(x,y+1));
    Block neighbBeneath = this->getBlock(Point(x,y-1));

    //keep a counter that counts the number of the neighbours
    int number = 0;

    /* adding neighbour in the requested order (9, 12, 3, 6): */

    //if the left neighbour exists add it to the block's neighbour array
    //and add 1 to the counter
    if (leftNeighb.getValue().getX() != -1 && !leftNeighb.isObstacles()) {
        currentBlock.insertNeighbour(number, leftNeighb);
        number++;
    }

    //if the neighbour above exists add it to the block's neighbour array
    //and add 1 to the counter
    if (neighbAbove.getValue().getX() != -1 && !neighbAbove.isObstacles()) {
        currentBlock.insertNeighbour(number, neighbAbove);
        number++;
    }

    //if the right neighbour exists add it to the block's neighbour array
    //and add 1 to the counter
    if (rightNeighb.getValue().getX() != -1 && !rightNeighb.isObstacles()) {
        currentBlock.insertNeighbour(number, rightNeighb);
        number++;
    }

    //if the neighbour beneath exists add it to the block's neighbour array
    //and add 1 to the counter
    if (neighbBeneath.getValue().getX() != -1 && !neighbBeneath.isObstacles()) {
        currentBlock.insertNeighbour(number, neighbBeneath);
        number++;
    }

    //return the number of neighbours added.
    return number;
}

/*
 * distanse
 * returns the size of the trip between two blocks
 */
int Map::distanse(Block &b1, Block &b2) {
    return BFS(b1,b2).size() - 1;
}

/* BFS
 * gets two Blocks objects, the start one and the target,
 * returns the minimum track from the start to the target, using Breadth-first search.
 */
list<Point> Map::BFS(Block& start, Block& end) {
    //creating an array that it's indexes will matches to the
    //block ones. each value in the array will represent a flag
    //true - being visited already, false - was not
    bool visit[this->numOfBlocks];
    for (int i = 0; i < this->numOfBlocks; i++) {
        //starting with no block being visited
        visit[i] = false;
    }

    //creating an array that it's indexes will matches to the
    //blocks ones. each Point in the array will represent the
    //parent of the matches index block parent.
    Point parents[this->numOfBlocks];

    int currentX, currentY;
    Block current, currentNeighbour;

    //building a queue for the bfs algorithm:
    std::queue<Block> BFSqueue;

    //pushing the start to the queue:
    BFSqueue.push(start);
    //changing the start flag for being visited:
    visit[this->getIndex(start)] = true;
    //sets the start parent in the parents array
    parents[this->getIndex(start)] = start.getValue();
    while (!BFSqueue.empty()) { //while the queue isn't empty, continue with the algorithm
        //work on the top of the queue and take it out of the queue:
        current = BFSqueue.front();
        BFSqueue.pop();
        currentX = current.getValue().getX();
        currentY = current.getValue().getY();

        //going over all of the current neighbours:
        for (int i = 0; i < current.getNeighboursNum(); i++) {
            currentNeighbour = this->getBlock(current.getNeighbour(i));

            //if this block has not being visited
            if (!visit[this->getIndex(currentNeighbour)]) {
                //chang the current neighbour flag for being visited:
                visit[this->getIndex(currentNeighbour)] = true;
                //set the current neighbour parent:
                parents[this->getIndex(currentNeighbour)] = Point(currentX, currentY);
                //pushing the current neighbour to the queue:
                BFSqueue.push(currentNeighbour);
            }
        }
    }
    /*end of the BFS algorithm*/

    /*start of the returning algorithm*/
    stack<Point> printStack;
    printStack.push(end.getValue());
    while (!(printStack.top() == start.getValue())) {
        printStack.push(parents[this->getIndex(printStack.top())]);
    }
    list<Point> returnList;
    while (!printStack.empty()) {
        returnList.push_back(printStack.top());
        printStack.pop();
    }
    return returnList;
}