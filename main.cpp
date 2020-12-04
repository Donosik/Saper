#include "functions.h"

int main(int argc, char *argv[])
{
    Args args;
    bool error = false;

    Arguments(argc, argv, args, error);
    if(error)
    {
        return 0;
    }

    Board board;
    board=RandomBoard(args.x,args.y,args.numberOfBombs);
    ShowBoard(board);
    return 0;
}
