#pragma once

#include <vector>
#include "mazegenerator.h"

class HuntAndKill : public MazeGenerator{
public:
    HuntAndKill();


    virtual void generateMaze(int rows, int columns) override;

}; 