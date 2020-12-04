#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "structures.h"

void Arguments(int argc, char *argv[], Args &args, bool &error);

Board RandomBoard(int x,int y,int numberOfBombs);

void ShowBoard(Board board);

int Random(int min,int max);

#endif FUNCTIONS_H
