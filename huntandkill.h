#pragma once

#include "mazegenerator.h"

class HuntAndKill: public MazeGenerator{
public:
    //outputs the maze
    void displayMaze();

    //override to implement your generation algorithm
    virtual void generateMaze(int rows, int columns) = 0;

protected:
    //empties out and creates a solid block of wall chars that is x2 + 1 the specified size
    void createEmpty(int rows, int columns);
}; 