#include "mazegenerator.h"

#include <iostream>

using namespace std;

void MazeGenerator::displayMaze(){
    //iterate through all rows
    for(int i = 0; i < m_maze.size(); i++){
        cout << m_maze[i] << endl;
    }
}

void MazeGenerator::createEmpty(int rows, int columns){
    //create a solid block of wall tiles that is x2 + 1 the paramters to allow a grid pattern
    for(int y = 0; y < rows * 2 + 1; y++){
        string row = "";

        for(int x = 0; x < columns * 2 + 1; x++){

            row += WALL_CHAR;
        }

        m_maze.push_back(row);
    }
}