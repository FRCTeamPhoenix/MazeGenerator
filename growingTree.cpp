#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "growingTree.h"

namespace lineThings {
    class line {
        public:
            int x, y, x2, y2;
            line(int x1, int y1, int x12, int y12) {
                x = x1;
                y = y1;
                x2 = x12;
                y2 = y12;
            }
            bool isLine(int x1, int y1, int x12, int y12) {
                if ((x == x1) && (y == y1) && (x2 == x12) && (y2 == y12)) {
                    return true;
                }
                else {
                    return false;
                }
            }
    };
    class point {
        public:
            int x, y;
            point(int x1, int y1) {
                x = x1;
                y = y1;
            }
    };
}

GrowingTree::GrowingTree() {
    
}

void GrowingTree::generateMaze(int rows, int columns) {
    srand (time(NULL));
    //http://weblog.jamisbuck.org/2011/1/27/maze-generation-growing-tree-algorithm
    MazeGenerator::createEmpty(rows, columns);
    
    std::vector<lineThings::line> lines;
    for (int i = 0; i < columns - 1; i++) {
        for (int j = 0; j < rows - 1; j++) {
            lines.emplace_back(lineThings::line(i, j, i + 1, j));
            lines.emplace_back(lineThings::line(i, j, i, j + 1));
        }
    }
    for (int i = 0; i < columns - 1; i++) {
        lines.emplace_back(lineThings::line(i, rows - 1, i + 1, rows - 1));
    }

    std::vector<lineThings::point> points;

    start:
    bool mazeIncomplete = true;
    int curX = rand() % columns;
    int curY = rand() % rows;
    int lastX;
    int lastY;
    while (mazeIncomplete) {
        int lastX = curX;
        int lastY = curY;

        std::vector<lineThings::point> pointsTemp;
        randomNeighbor:
        //random neighbor
        int tempX = 0;
        int tempY = 0;
        int randX = 0;
        int randY = 0;
        if (rand() % 2 < 1) {
            while (tempX == 0) {
                randX = rand() % 4;
                tempX = lastX + randX - 1;
            }
        }
        else {
            while (tempY == 0) {
                randY = rand() % 4;
                tempY = lastY + randY - 1;
            }
        }

        //is neighbor visited
        for (int i = 0; i < points.size(); i++) {
            if ((points[i].x == tempX) && (points[i].y == tempY)) {

                for (int j = 0; j < pointsTemp.size(); j++) {
                    if ((pointsTemp[j].x != tempX) && (pointsTemp[j].y != tempY)) {
                        pointsTemp.emplace_back(lineThings::point(tempX, tempY));
                    }
                }
                if (pointsTemp.size() >= 4) {
                    //this means there are no un-visted neighbors
                    goto start;
                }
                goto randomNeighbor;
            }
        }
        
        //Remove the line between the current and last
        curX = tempX;
        curY = tempY;

        if (randX != 0) {
            if (randX == -1) {
                //(x + 1, y, x + 1, y + 1)
                for (int i = 0; i < lines.size(); i++) {
                    if (lines[i].isLine(curX + 1, curY, curX + 1, curY + 1)) {
                        lines.erase(lines.begin() + i);
                    }
                }
            }
            else {
                //(x, y, x, y + 1)
                for (int i = 0; i < lines.size(); i++) {
                    if (lines[i].isLine(curX, curY, curX, curY + 1)) {
                        lines.erase(lines.begin() + i);
                    }
                }
            }
        }
        else {
            if (randY == -1) {
                //(x, y + 1, x + 1, y + 1)
                for (int i = 0; i < lines.size(); i++) {
                    if (lines[i].isLine(curX, curY + 1, curX + 1, curY + 1)) {
                        lines.erase(lines.begin() + i);
                    }
                }
            }
            else {
                //(x, y, x, y)
                for (int i = 0; i < lines.size(); i++) {
                    if (lines[i].isLine(curX, curY, curX, curY)) {
                        lines.erase(lines.begin() + i);
                    }
                }
            }
        }

        points.emplace_back(lineThings::point(curX, curY));
        if (points.size() >= columns*rows) {
            mazeIncomplete = false;
        }
    }

    /*for (int i = 0; i < columns * 2 + 1; i++) {
        for (int j = 0; j < rows * 2 + 1; j++) {

        }
    }*/
    std::vector<std::string> maze;
    for (int i = 0; i < columns - 1; i++) {
        std::string row = "";
        for (int j = 0; j < rows - 1; j++) {
            bool tempBool = true;
            for (int k = 0; k < lines.size(); k++) {
                if (lines[k].isLine(i, j, i, j + 1)) {
                    row += WALL_CHAR;
                    tempBool = false;
                }
            }
            if (tempBool) {
                row += EMPTY_CHAR;
            }

            tempBool = true;
            for (int k = 0; k < lines.size(); k++) {
                if (lines[k].isLine(i, j, i + 1, j)) {
                    row += WALL_CHAR;
                    tempBool = false;
                }
            }
            if (tempBool) {
                row += EMPTY_CHAR;
            }
            //lines.emplace_back(lineThings::line(i, j, i, j + 1));
            //lines.emplace_back(lineThings::line(i, j, i + 1, j));
        }
        row += WALL_CHAR;
        maze.emplace_back(row);
    }
    std::string row = "";
    for (int i = 0; i < columns - 1; i++) {
        row += WALL_CHAR;
    }
    maze.emplace_back(row);
    m_maze = maze;
}

void GrowingTree::displayMaze() {
    for (int i = 0; i < m_maze.size(); i++) {
        std::cout << m_maze[i] << std::endl;
    }
}