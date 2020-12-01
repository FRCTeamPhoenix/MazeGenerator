#include <random>
#include <string>
#include "recursive.h"

Recursive::Recursive(){

}

void Recursive::run(){

}

void Recursive::generateMaze(int rows, int columns){
    int cx = rand() % columns;
    int startx = cx;
    int lastx = cx;
    int cy = rand() % rows;
    int starty = cy;
    int lasty = cy;
    while(true){ // loops for the whole maze
        while(true){ // loops for the current cell
            int dir = rand() % 4;
            if(cy > 1){ // if not at top of board
                if(dir == 0 && m_maze[cy - 2][cx] == WALL_CHAR){ // if looking up and the cell there is untouched
                    cy -= 2;
                    m_maze[cy - 1][cx] = EMPTY_CHAR;
                }
            }else if(cx < columns - 2){ // if not at right of board
                if(dir == 1 && m_maze[cy][cx + 2] == WALL_CHAR){ // if looking right and the cell there is untouched
                    cx += 2;
                    m_maze[cy][cx + 1] = EMPTY_CHAR;
                }
            }else if(cy < rows - 2){ // if not at bottom of board
                if(dir == 2 && m_maze[cy + 2][cx] == WALL_CHAR){ // if looking down and the cell there is untouched
                    cy += 2;
                    m_maze[cy + 1][cx] = EMPTY_CHAR;
                }
            }else if(cx > 1){ // if not at left of board
                if(dir == 3 && m_maze[cy][cx - 2] == WALL_CHAR){ // if looking left and the cell there is untouched
                    cx -= 2;
                    m_maze[cy][cx - 1] = EMPTY_CHAR;
                }
            }else{
                cx = lastx;
                cy = lasty;
            }
        }
    }
}