#include <random>
#include <string>
#include <vector>
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
        int dir = rand() % 4;
        bool adjacentEmpty = true;
        if(cy > 1){ // if not at top of board
            if(dir == 0 && m_maze[cy - 2][cx] == WALL_CHAR){ // if looking up and the cell there is untouched
                m_maze[cy - 1][cx] = EMPTY_CHAR;
                m_maze[cy - 2][cx] = EMPTY_CHAR;
                if(cx < columns - 2 && cy < rows - 2 && cx > 1){ // makes sure it won't step out of bounds when checking all adjacent cells
                    adjacentEmpty = !(m_maze[cy][cx + 2] == WALL_CHAR && m_maze[cy + 2][cx] == WALL_CHAR && m_maze[cy][cx - 2] == WALL_CHAR);
                }
                cy -= 2;
            }
        }else if(cx < columns - 2){ // if not at right of board
            if(dir == 1 && m_maze[cy][cx + 2] == WALL_CHAR){ // if looking right and the cell there is untouched
                m_maze[cy][cx + 1] = EMPTY_CHAR;
                m_maze[cy][cx + 2] = EMPTY_CHAR;
                if(cy > 1 && cy < rows - 2 && cx > 1){ // makes sure it won't step out of bounds when checking all adjacent cells
                    adjacentEmpty = !(m_maze[cy - 2][cx] == WALL_CHAR && m_maze[cy + 2][cx] == WALL_CHAR && m_maze[cy][cx - 2] == WALL_CHAR);
                }
                cx += 2;
            }
        }else if(cy < rows - 2){ // if not at bottom of board
            if(dir == 2 && m_maze[cy + 2][cx] == WALL_CHAR){ // if looking down and the cell there is untouched
                m_maze[cy + 1][cx] = EMPTY_CHAR;
                m_maze[cy + 2][cx] = EMPTY_CHAR;
                if(cy > 1 && cx < columns - 2 && cx > 1){ // makes sure it won't step out of bounds when checking all adjacent cells
                    adjacentEmpty = !(m_maze[cy - 2][cx] == WALL_CHAR && m_maze[cy][cx + 2] == WALL_CHAR && m_maze[cy][cx - 2] == WALL_CHAR);
                }
                cy += 2;
            }
        }else if(cx > 1){ // if not at left of board
            if(dir == 3 && m_maze[cy][cx - 2] == WALL_CHAR){ // if looking left and the cell there is untouched
                m_maze[cy][cx - 1] = EMPTY_CHAR;
                m_maze[cy][cx - 2] = EMPTY_CHAR;
                if(cy > 1 && cx < columns - 2 && cy < rows - 2){ // makes sure it won't step out of bounds when checking all adjacent cells
                    adjacentEmpty = !(m_maze[cy - 2][cx] == WALL_CHAR && m_maze[cy][cx + 2] == WALL_CHAR && m_maze[cy + 2][cx] == WALL_CHAR);
                }
                cx -= 2;
            }
        }else{
            cx = lastx;
            cy = lasty;
        }
        if(adjacentEmpty){
            lastx = cx;
            lasty = cy;
        }
        if(cx == startx && cy == starty){
            break;
        }
    }
}