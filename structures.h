#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

/// Struktura zawierająca wszystkie argumenty, które przyjmuje program
struct Args
{
    /// Szerokość planszy jako argument programu
    int x;
    /// Wysokość planszy jako argument programu
    int y;
    /// Liczba bomb jako argument programu
    int numberOfBombs;
    /// Nazwa gracza jako argument programu
    std::string playerName;
    /// Nazwa pliku z wynikami graczy
    std::string dataFile;
};

/// Struktura opisująca pojedyncze pole na planszy
struct Cell
{
    /// Czy pole jest otwarte
    bool open=false;
    /// Czy na polu jest ustawiona flaga, że może być tam bomba
    bool flag=false;
    /// Czy na polu jest bomba
    bool bomb=false;
    /// Jaka jest ilość bomb w sąsiedztwie
    int count=0;
};

struct Board
{
    /// Szerokość planszy
    int x;
    /// Wysokość planszy
    int y;
    /// Tablica 2-wymiarowa wektorów z komórek opisujących plansze
    std::vector<std::vector<Cell>> board;
};

#endif STRUCTURES_H
