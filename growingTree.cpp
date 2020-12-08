#include <vector>
#include <string>
#include "growingTree.h"

namespace lineThings {
    class line {
        public:
            int x, y, x2, y2;
            line::line(int x1, int y1, int x12, int y12) {
                x = x1;
                y = y1;
                x2 = x12;
                y2 = y12;
            }
    };
    class point {
        public:
            int x, y;
            point::point(int x1, int y1) {
                x = x1;
                y = y1;
            }
    };
}

GrowingTree::GrowingTree() {
    
}

void GrowingTree::generateMaze(int rows, int columns) {
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
        while (true) {
            std::vector<lineThings::point> pointsTemp;
            randomNeighbor:
            //random neighbor
            int tempX = 0;
            while (tempX == 0) {
                tempX = lastX + (rand() % 4) - 1;
            }
            int tempY = 0;
            while (tempY == 0) {
                tempY = lastY + (rand() % 4) - 1;
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
            
            //
        }
        points.emplace_back(lineThings::point(curX, curY));
    }

    /*for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {

        }
    }*/
}