#include <random>
#include <string>
#include <vector>
#include <iostream>
#include "recursive.h"
using namespace std;

Recursive::Recursive(){

}

void Recursive::run(){

}

void Recursive::generateMaze(int rows, int columns){
    int cx = (rand() % columns) * 2 + 1;
    int startx = cx;
    int lastx = cx;
    cout << "cx: " << cx << endl;
    int cy = (rand() % rows) * 2 + 1;
    int starty = cy;
    int lasty = cy;
    cout << "cy: " << cy << endl;
    vector<int[]> path;
    path.push_back({cx, cy});
    createEmpty(rows, columns);
    cout << "got to start\n";
    m_maze[cy][cx] = EMPTY_CHAR;
    while(true){ // loops for the whole maze
        cout << "a\n";
        int dir = rand() % 4;
        cout << "dir: " << dir << endl;
        bool adjacentEmpty = true;
        bool moved = false;
        if(cy > 1){ // if not at top of board
            cout << "b\n";
            if(dir == 0 && m_maze[cy - 2][cx] == WALL_CHAR){ // if looking up and the cell there is untouched
                m_maze[cy - 1][cx] = EMPTY_CHAR;
                m_maze[cy - 2][cx] = EMPTY_CHAR;
                cout << "emptied wall\n";
                cy -= 2;
                moved = true;
            }
        }
        if(cx < (columns * 2 + 1) - 2){ // if not at right of board
            cout << "c\n";
            if(dir == 1 && m_maze[cy][cx + 2] == WALL_CHAR){ // if looking right and the cell there is untouched
                m_maze[cy][cx + 1] = EMPTY_CHAR;
                m_maze[cy][cx + 2] = EMPTY_CHAR;
                cout << "emptied wall\n";
                cx += 2;
                moved = true;
            }
        }
        if(cy < (rows * 2 + 1) - 2){ // if not at bottom of board
            cout << "d\n";
            if(dir == 2 && m_maze[cy + 2][cx] == WALL_CHAR){ // if looking down and the cell there is untouched
                m_maze[cy + 1][cx] = EMPTY_CHAR;
                m_maze[cy + 2][cx] = EMPTY_CHAR;
                cout << "emptied wall\n";
                cy += 2;
                moved = true;
            }
        }
        if(cx > 1){ // if not at left of board
            cout << "e\n";
            if(dir == 3 && m_maze[cy][cx - 2] == WALL_CHAR){ // if looking left and the cell there is untouched
                m_maze[cy][cx - 1] = EMPTY_CHAR;
                m_maze[cy][cx - 2] = EMPTY_CHAR;
                cout << "emptied wall\n";
                cx -= 2;
                moved = true;
            }
        }
        if(!moved){
            cout << "f\n";
            cx = path[path.size()-1][0];
            cy = path[path.size()-1][1];
            path.erase(path.size()-1);
        }
        if(cx == startx && cy == starty){
            break;
        }
        bool hasAdjacent = false;
        if(cy > 1){
            hasAdjacent = m_maze[cy - 2][cx] == WALL_CHAR;
        }
        if(!hasAdjacent && cx > 1){
            hasAdjacent = m_maze[cy][cx - 2] == WALL_CHAR;
        }
        if(!hasAdjacent && cx < (columns * 2 + 1) - 2){
            hasAdjacent = m_maze[cy + 2][cx] == WALL_CHAR;
        }
        if(!hasAdjacent && cy < (rows * 2 + 1) - 2){
            hasAdjacent = m_maze[cy][cx + 2] == WALL_CHAR;
        }
        if(hasAdjacent){
            path.push_back({cx, cy});
        }
    }
    cout << "got to end\n";
}