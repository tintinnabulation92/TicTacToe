#include <stdio.h>
#include <stdlib.h>

#define GRID 3
#define PLAYER 10

////////////////////// FUNCTION DECLARATIONS  ////////////////////////////////
void welcomePlayer(char *_player1Name, char *_play2Name); // choosing a player and a symbol
void drawGrid(); //drawing a grid as an 3x3 char array - at the beginning
int choosePosition(); // ACTUAL GAME IS HERE
void refreshGrid(); //refreshes grid putting X or O on the location

///////////////////////////////// MAIN ///////////////////////////////////////
int main()
{
    int _scorePlayerOne, _scorePlayerTwo = 0;
    char _playerOne[PLAYER];
    char _playerTwo[PLAYER];
    char _gameGrid[GRID][GRID] = {0};

    drawGrid();
    welcomePlayer(_playerOne, _playerTwo);
    printf("\n The following players are playing: %s and %s.\n", _playerOne, _playerTwo); // commented

    int choose = choosePosition();     //(&_gameGrid[GRID][GRID]);  - tak przesyla sie tablice w funkcji
     //
    switch(choose)
    {
            case 1:
            _gameGrid[0][0] = 'X';
                break;
            case 2:
            _gameGrid[0][1] = 'X';
                break;
            case 3:
            _gameGrid[0][2] = 'X';
                break;
            case 4:
            _gameGrid[1][0] = 'X';
                break;
            case 5:
            _gameGrid[1][1] = 'X';
                break;
            case 6:
            _gameGrid[1][2] = 'X';
                break;
            case 7:
            _gameGrid[2][0] = 'X';
                break;
            case 8:
            _gameGrid[2][1] = 'X';
                break;
            case 9:
            _gameGrid[2][2] = 'X';
                break;
    }

for (int x =0; x<GRID; x++) // odswiezenie - trzeba to zrobic w funkcji
        {
                for (int y=0; y<GRID; y++)
                {
                    printf(" %2c |", _gameGrid[x][y]);
                }
            printf("\n");
            printf("\ ______________");
            printf("\n\n");
        }

    return 0;
}

//////////////////////////////////////////////
//MODULES&FUNCTIONS///////////////////////////
//////////////////////////////////////////////

int choosePosition()
{
    
    printf("Enter the position of your mark 1-9\n");
    int choose;
    scanf("%d", &choose);
    return choose;

    /*switch(choose)
    {
            case 1:
            _grid[0][0] = 'X';
            break;
            case 2:
            _grid[0][1] = 'X'; //
            break;
            case 3:
            _grid[0][2] = 'X';
            break;
    }*/

}

void refreshGrid()
{

    // 
}

void welcomePlayer(char _player1Name[], char _play2Name[])
{
    printf("Welcome to TicTacToe. Please Enter P1 name:");
    scanf("%s", _player1Name);
    printf("Type P2 name:");
    scanf("%s", _play2Name);

    printf("Auf einem quadratischen, 3×3 Felder großen Spielfeld setzen"
           "die beiden Spieler abwechselnd ihr Zeichen (ein Spieler Kreuze,"
           "der andere Kreise) in ein freies Feld. Der Spieler, "
           "der als Erster drei Zeichen in eine Zeile,"
           "Spalte oder Diagonale setzen kann, gewinnt.\n"
           "Wenn allerdings beide Spieler optimal spielen,"
           "kann keiner gewinnen, und es kommt zu einem Unentschieden.\n"
           "Das heißt, alle neun Felder sind gefüllt,"
           "ohne dass ein Spieler die erforderlichen Zeichen in"
            "einer Reihe, Spalte oder Diagonalen setzen konnte.\n\n\n\n");



    //printf("You can choose rather to play as 'X' or as 'O'. Select your symbol:");
    //input..^
}

void drawGrid()
{
    char _startingGrid[GRID][GRID] = {{49,50,51}, {52,53,54}, {55,56,57}};
    printf("\n\n\n\n\n");

        for (int x =0; x<GRID; x++)
        {

                for (int y=0; y<GRID; y++)
                {

                    printf(" %2c |", _startingGrid[x][y]);

                }

            printf("\n");
            printf("\ ______________");
            printf("\n\n");

        }
}
