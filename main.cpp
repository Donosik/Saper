#include "functions.h"

int main(int argc, char *argv[])
{
    /// Wszystkie argumenty otrzymane przez program
    Args args;
    /// Zmienna odpowiadająca za to, czy funkcje się wykonały poprawnie
    bool error = false;

    Arguments(argc, argv, args, error);
    if(error)
    {
        return 0;
    }

    /// Plansza
    Board board;
    board=RandomBoard(args.x,args.y,args.numberOfBombs);
    MainGame(board);

    SaveToFile(args.playerName,args.dataFile,board,error);
    if(error)
    {
        return 0;
    }
    return 0;
}
