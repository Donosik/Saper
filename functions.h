#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "structures.h"

void Arguments(int argc, char *argv[], Args &args, bool &error);

Board RandomBoard(int x,int y,int numberOfBombs);

void CountAllBombs(Board &board);

int CountBombs(Board &board,int x, int y);

void ShowBoard(Board board);

void MainGame(Board &board);

void SaveToFile(std::string name,std::string fileName);

int Random(int min,int max);

#endif FUNCTIONS_H
