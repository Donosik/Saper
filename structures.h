#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

struct Args
{
    int x;
    int y;
    int numberOfBombs;
    std::string playerName;
    std::string dataFile;
};

struct Cell
{
    bool open=false;
    bool flag=false;
    bool bomb=false;
    int count=0;
};

struct Board
{
    int x;
    int y;
    std::vector<std::vector<Cell>> board;
};

#endif STRUCTURES_H
