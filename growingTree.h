#pragma once

#include <vector>
#include <string>
#include "mazegenerator.h"

class GrowingTree: public MazeGenerator{
public:
    //outputs the maze
    void displayMaze();

    //override to implement your generation algorithm
    virtual void generateMaze(int rows, int columns) override;
private:
    std::vector<std::vector<char>> points;
protected:
    //empties out and creates a solid block of wall chars that is x2 + 1 the specified size
    void createEmpty(int rows, int columns);
};