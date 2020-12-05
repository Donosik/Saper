#include "functions.h"

void Arguments(int argc, char *argv[], Args &args, bool &error)
{
    if (argc < 11)
    {
        std::cout << "Poprawne uruchomienie programu wymaga ponizszych przelacznikow:" << std::endl;
        std::cout << "-x szerokosc planszy" << std::endl;
        std::cout << "-y wysokosc planszy" << std::endl;
        std::cout << "-m liczba min" << std::endl;
        std::cout << "-i imie gracza" << std::endl;
        std::cout << "-w plik z statystykami gier" << std::endl;
        error = true;
        return;
    }
    for (int i = 1; i < argc; i += 2)
    {
        if ((std::string) argv[i] == "-x")
        {
            int x = std::stoi(argv[i + 1]);
            if (x <= 0)
            {
                std::cout << "Wartosc po przelaczniku -x musi byc wieksza od zera" << std::endl;
                error = true;
                return;
            }
            args.x = x;
        }
        else if ((std::string) argv[i] == "-y")
        {
            int y = std::stoi(argv[i + 1]);
            if (y <= 0)
            {
                std::cout << "Wartosc po przelaczniku -y musi byc wieksza od zera" << std::endl;
                error = true;
                return;
            }
            args.y = y;
        }
        else if ((std::string) argv[i] == "-m")
        {
            int numberOfBombs = std::stoi(argv[i + 1]);
            if (numberOfBombs <= 0)
            {
                std::cout << "Wartosc po przelaczniku -numberOfBombs musi byc wieksza od zera" << std::endl;
                error = true;
                return;
            }
            args.numberOfBombs = numberOfBombs;
        }
        else if ((std::string) argv[i] == "-i")
        {
            args.playerName = argv[i + 1];
        }
        else if ((std::string) argv[i] == "-w")
        {
            args.dataFile = argv[i + 1];
        }
    }
    if (args.numberOfBombs > args.x * args.y)
    {
        std::cout << "Liczba bomb nie moze byc wieksza niz cale pole gry" << std::endl;
        error = true;
        return;
    }
}

Board RandomBoard(int x, int y, int numberOfBombs)
{
    Board board;
    board.x = x;
    board.y = y;

    board.board = std::vector<std::vector<Cell>>();
    for (int i = 0; i < x; i++)
    {
        Cell cell;
        std::vector<Cell> yAxis;
        for (int j = 0; j < y; j++)
        {
            yAxis.push_back(cell);
        }
        board.board.push_back(yAxis);
    }

    for (int i = 0; i < numberOfBombs; i++)
    {
        int randomX = Random(0, x - 1);
        int randomY = Random(0, y - 1);
        board.board[randomX][randomY].bomb = true;
    }
    CountAllBombs(board);
    return board;
}

void CountAllBombs(Board &board)
{
    for (int i = 0; i < board.board.size(); i++)
    {
        for (int j = 0; j < board.board[i].size(); j++)
        {
            if (!board.board[i][j].bomb)
            {
                board.board[i][j].count = CountBombs(board, i, j);
            }
        }
    }
}

int CountBombs(Board &board, int x, int y)
{
    int counter = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i < 0 || i >= board.x || j < 0 || j >= board.y)
            {
                continue;
            }
            if (board.board[i][j].bomb)
            {
                counter++;
            }
        }
    }
    return counter;
}

void ShowBoard(Board board)
{
    for (int i = 0; i < board.board.size(); i++)
    {
        for (int j = 0; j < board.board[i].size(); j++)
        {
            //TODO: Prawidłowe wyświetlanie planszy
            if (board.board[i][j].open)
            {
                if (board.board[i][j].bomb)
                {
                    std::cout << "B ";
                }
                else if (board.board[i][j].count)
                {
                    std::cout << board.board[i][j].count << " ";
                }
                else
                {
                    std::cout << "0 ";
                }
            }
            else
            {
                std::cout<<"X ";
            }
        }
        std::cout << std::endl;
    }
}

void MainGame(Board &board)
{
    int x,y;
    do
    {
        system("cls");
        std::cout<<"Nowe!"<<std::endl;
        ShowBoard(board);
        std::cout<<"Podaj x, gdzie chcesz kliknac:";
        std::cin>>x;
        std::cout<<"Podaj y, gdzie chcesz kliknac: ";
        std::cin>>y;
        board.board[x-1][y-1].open= true;
    }while (!board.board[x-1][y-1].bomb);
}

void SaveToFile(std::string name,std::string fileName)
{
    //TODO: zapisywanie do pliku
}

int Random(int min, int max)
{
    std::default_random_engine silnik;
    silnik.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> rozklad(min, max);
    return rozklad(silnik);
}
