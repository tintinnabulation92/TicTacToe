#include <stdio.h>
#include <stdlib.h>

#define GRID 3
#define PLAYER 10

////////////////////// FUNCTION DECLARATIONS  ////////////////////////////////
void welcomePlayer(char *_player1Name, char *_play2Name); // choosing a player and a symbol
void drawGrid(); //drawing a grid as an 3x3 char array - at the beginning
int choosePosition(char (*gameGrid)[GRID]); // ACTUAL GAME IS HERE
void refreshGrid(char (*gameGrid)[GRID]); //refreshes grid putting X or O on the location
void selectSign(char *p1Sign, char *p2Sign);

///////////////////////////////// MAIN ///////////////////////////////////////
int main()
{
    int _scorePlayerOne, _scorePlayerTwo = 0;
    char _playerOne[PLAYER];
    char _playerTwo[PLAYER];
    char _gameGrid[GRID][GRID] = {0};
    char *p = NULL; //not used yet
    char _playerOneSign;
    char _playerTwoSign;

    //drawGrid();
    //welcomePlayer(_playerOne, _playerTwo);
    selectSign(&_playerOneSign, &_playerTwoSign);
    //printf("\n The following players are playing: %s and %s.\n", _playerOne, _playerTwo); // commented
    printf(" p1 %d  p2 %d \n", _playerOneSign, _playerTwoSign);
    //choosePosition(_gameGrid);
    //refreshGrid(_gameGrid);




    return 0;
}

//////////////////////////////////////////////
//MODULES&FUNCTIONS///////////////////////////
//////////////////////////////////////////////

int choosePosition(char (*gameGrid)[GRID])
{

    printf("\nEnter the position of your mark 1-9");
    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        gameGrid[0][0] = 'X';
        break;
    case 2:
        gameGrid[0][1] = 'X';
        break;
    case 3:
        gameGrid[0][2] = 'X';
        break;
    case 4:
        gameGrid[1][0] = 'X';
        break;
    case 5:
        gameGrid[1][1] = 'X';
        break;
    case 6:
        gameGrid[1][2] = 'X';
        break;
    case 7:
        gameGrid[2][0] = 'X';
        break;
    case 8:
        gameGrid[2][1] = 'X';
        break;
    case 9:
        gameGrid[2][2] = 'X';
        break;

    }

    return 0;

}

void refreshGrid(char (*gameGrid)[GRID])
{

    for (int x =0; x<GRID; x++)
        {
                for (int y=0; y<GRID; y++)
                {
                    printf(" %2c |", gameGrid[x][y]);
                }
            printf("\n");
            printf("\ ______________");
            printf("\n\n");
        }
}

void selectSign(char *p1Sign, char *p2Sign) // errori in this function, have to modify it

{
char tempVar1, tempVar2;
printf("Player 1: Select your symbol. 'X' or 'O' ? Type..");
scanf("%c", &tempVar1);

p1Sign = &tempVar1;
*p1Sign = tempVar1;
//p1Sign = NULL;

printf("\n Player 2: Select your symbol. 'X' or 'O' ? Type.."); //trzeba dac warunek zabezpieczajacy program
scanf(" %c", &tempVar2);
                                     // zeby gosc nie wybral sobie XX albo OO

p2Sign = &tempVar2;
*p2Sign = tempVar2;
//p2Sign = NULL;

//printf("Player 1 has chosen %c and player 2 has chosen %c \n", *p1Sign, *p2Sign); dziala
}

void welcomePlayer(char _player1Name[], char _play2Name[])
{
    printf("Welcome to TicTacToe. Please Enter P1 name:");
    scanf("%s", _player1Name);
    printf("Type P2 name:");
    scanf("%s", _play2Name);

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
