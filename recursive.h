#pragma once
#include <vector>
#include "mazegenerator.h"

class Recursive : public MazeGenerator{
public:
    Recursive();

    void run();

    virtual void generateMaze(int rows, int columns) override;
};