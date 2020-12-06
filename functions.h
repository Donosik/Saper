#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include "structures.h"

/// Funkcja sprawdzająca poprawność wszystkich argumentów programu
/// @param argc Ilość argumentów otrzymanych przez głowny program
/// @param argv Tablica argumentów otrzymanych przez program
/// @param args Zmienna referencyjna zawierająca wszystkie wartości parametrów podanych do programu
/// @param error Zmienna sprawdzająca czy funkcja natrafiła na jakiś błąd w czasie wykonywania
void Arguments(int argc, char *argv[], Args &args, bool &error);

/// Funkcja losująca zawartość planszy w oparciu o rozmiar i ilość min
/// @param x Parametr wysokości planszy
/// @param y Parametr szerokości planszy
/// @param numberOfBombs Ilość bomb, które mają być rozmieszczone na planszy
/// @return Zmienna typu Board zwraca całą planszę
Board RandomBoard(int x,int y,int numberOfBombs);

/// Funkcja wyznacza na wszystkich polach, ile bomb ich otacza;
/// @param board Referencja do zmiennej board, by nie kopiować jej zawartości
void CountAllBombs(Board &board);

/// Funkcja, któa zlicza ile bomb otacza pole o podanych parametrach
/// @param board Referencja do planszy by nie kopiować zawartości
/// @param x Parametr, służacy do wyznaczenia dla którego pola ma być policzona ilośc bomb naokoło
/// @param y Parametr, służacy do wyznaczenia dla którego pola ma być policzona ilośc bomb naokoło
/// @return Ilość bomb otaczających wyznaczone pole
int CountBombs(Board &board,int x, int y);

/// Funckja rysująca tablicę
/// @param board Referencja do tablicy, która ma być wyryusowana
void ShowBoard(Board &board);

/// Funckja sterująca całą rozgrywką, pyta, które pole ma być wybrane nastepnie i aktualizuje plansze
/// @param board Referencja do planszy, na której się rozgrywa gra
void MainGame(Board &board);

/// Funkcja zapisująca wynik gracza do pliku
/// @param name Nazwa gracza podana w argumencie programu
/// @param fileName Nazwa pliku, z którego zostaną odczytane wyniki i zapisany wynik gracza
/// @param board Referencja do planszy, na podstawie rozmiaru planszy, ilości min i ilości otwartych pół jest
/// onliczany wynik
/// @param error Zmienna sprawdzająca czy funkcja natrafiła na jakiś błąd w czasie wykonywania
void SaveToFile(std::string name,std::string fileName,Board &board,bool &error);

/// Funkcja losująca
/// @param min Wartość minimalna z losowania
/// @param max Wartość maksymalna z losowania
/// @return Wartość losowa
int Random(int min,int max);

#endif FUNCTIONS_H
