#include <iostream>

#include "mazeprogram.h"
#include "huntandkill.h"

int main(){
    MazeProgram maze;
    HuntAndKill huntandkill;
    maze.addGenerator("huntandkill", &huntandkill);
    maze.run();
}