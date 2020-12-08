#include <iostream>
#include <string>

#include "mazeprogram.h"
#include "recursive.h"

int main(){
    MazeProgram maze;
    Recursive recursive;
    maze.addGenerator("recursive", &recursive);
    maze.run();
}