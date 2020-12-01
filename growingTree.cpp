#include <vector>
#include <string>
#include <vector>
#include "growingTree.h"

namespace pointThings {
    class point {
        public:
            int x;
            int y;
            std::vector<int[2]> points;
            point::point(int x1, int y1) {
                x = x1;
                y = y1;
            }
    };
}

GrowingTree::GrowingTree() {
    //http://weblog.jamisbuck.org/2011/1/27/maze-generation-growing-tree-algorithm
}

void GrowingTree::generateMaze(int rows, int columns) {
    MazeGenerator::createEmpty(rows, columns);
    std::vector<pointThings::point>
}