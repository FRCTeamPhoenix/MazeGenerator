#include <vector>
#include <string>
#include <vector>
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
}

GrowingTree::GrowingTree() {
    //http://weblog.jamisbuck.org/2011/1/27/maze-generation-growing-tree-algorithm
    std::vector<lineThings::line> lines;
    //doesn't do across the bottom
    for (int i = 0; i < columnss - 1; i++) {
        for (int j = 0; j < rowss - 1; j++) {
            lines.emplace_back(lineThings::line(i, j, i + 1, j));
            lines.emplace_back(lineThings::line(i, j, i, j + 1));
        }
    }
    for (int i = 0; i < columnss - 1; i++) {
        lines.emplace_back(lineThings::line(i, rowss - 1, i + 1, rowss - 1));
    }
}

void GrowingTree::generateMaze(int rows, int columns) {
    MazeGenerator::createEmpty(rows, columns);
    rowss = rows;
    columnss = columns;
}