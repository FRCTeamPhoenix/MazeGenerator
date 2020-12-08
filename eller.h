#pragma once
#include "mazegenerator.h"

class Eller : public MazeGenerator{
public: 
    Eller();

    void run()

    virtual void generateMaze(int rows, int columns) override;
       
}