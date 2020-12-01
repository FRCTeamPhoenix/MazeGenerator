#pragma once

#include <vector>
#include <string>

const char WALL_CHAR = 'X';
const char EMPTY_CHAR = ' ';

class MazeGenerator{
public:
    //outputs the maze
    void displayMaze();

    //override to implement your generation algorithm
    virtual void generateMaze(int rows, int columns) = 0;

protected:
    //empties out and creates a solid block of wall chars that is x2 + 1 the specified size
    void createEmpty(int rows, int columns);

    std::vector<std::string> m_maze;
};