#pragma once

#include "mazegenerator.h"

#include <unordered_map>
#include <string>

class MazeProgram{
public:
    MazeProgram();

    void run();

    void addGenerator(std::string name, MazeGenerator* gen);

private:
    std::unordered_map<std::string, MazeGenerator*> m_generators;
};