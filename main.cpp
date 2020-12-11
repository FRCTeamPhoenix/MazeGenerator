#include <iostream>

#include "growingTree.h"
#include "mazeprogram.h"

int main(){
    MazeProgram maze;
    GrowingTree growingTree;
    //maze.addGenerator("growingTree", &growingTree);
    while (true) {
        growingTree.generateMaze(6, 6);
        growingTree.displayMaze();
        for (int i = 0; i < 99999999; i++) {
            int x = 5;
            x++;
        }
        std::cout << std::endl << std::endl;
    }
    maze.run();
}