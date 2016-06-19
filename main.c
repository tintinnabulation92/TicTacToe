#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define GRID 3
#define PLAYER 10

////////////////////// FUNCTION DECLARATIONS  ////////////////////////////////
void welcomePlayer(char *_player1Name, char *_play2Name); // choosing a player and a symbol
void drawGrid(); //drawing a grid as an 3x3 char array - at the beginning
int choosePosition(char (*gameGrid)[GRID], char *playerSign, int *who); // ACTUAL GAME IS HERE
//int choosePositionO(char (*gameGrid)[GRID]);
void refreshGrid(char (*gameGrid)[GRID]); //refreshes grid putting X or O on the location
void selectSign(char *p1Sign, char *p2Sign);
void winConditionX(char (*gameGrid)[GRID], bool *gameEnd);
void winConditionO(char (*gameGrid)[GRID], bool *gameEnd);

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
    int draw = 0; //val 9 = game is ended

    bool _gameEnd = false;
    int _whoPlays = 1;
    drawGrid();
    welcomePlayer(_playerOne, _playerTwo);
    selectSign(&_playerOneSign, &_playerTwoSign);
    printf("\n The following players are playing: %s and %s.\n", _playerOne, _playerTwo); // commented
    printf("Player 1 has chosen %c and player 2 has chosen %c \n", _playerOneSign, _playerTwoSign);
    //choosePosition(_gameGrid);

    //refreshGrid(_gameGrid);

    printf("Player 1 starts.\n"); //_whoPlays = 1

    //refreshGrid(_gameGrid);

    while(_gameEnd == false) //gra dopoki nie ma konca gry
    {
        if (_whoPlays == 1 && draw<9)
        {
            choosePosition(_gameGrid, &_playerOneSign, &_whoPlays); //ktory gracz ma teraz ture
            refreshGrid(_gameGrid);
            winConditionX(&_gameGrid, &_gameEnd);
            winConditionO(&_gameGrid, &_gameEnd);
            ++draw;

        }

        else if (_whoPlays == 2 && draw<9)
        {
            choosePosition(_gameGrid, &_playerTwoSign, &_whoPlays); //ktory gracz ma teraz ture
            refreshGrid(_gameGrid);
            winConditionX(&_gameGrid, &_gameEnd);
            winConditionO(&_gameGrid, &_gameEnd);
            ++draw;
        }

        else {
            printf("Draw! game is over");
            _gameEnd = true;
        }

    }

    return 0;
}

//////////////////////////////////////////////
//MODULES&FUNCTIONS///////////////////////////
//////////////////////////////////////////////

void winConditionX(char (*gameGrid)[GRID], bool *gameEnd) //check if a player has won the game
{



    if (gameGrid[0][0] == 'X' && gameGrid[0][1] == 'X' && gameGrid[0][2] == 'X')
    {
        printf("X has won! game has ended!");
        *gameEnd = true;
    }
        else if (gameGrid[0][0] == 'X' && gameGrid[1][0] == 'X' && gameGrid[2][0] == 'X')
    {
        printf("X has won! game has ended!");
        *gameEnd = true;
    }

    else if (gameGrid[0][1] == 'X' && gameGrid[1][1] == 'X' && gameGrid[2][1] == 'X')
    {
        printf("X has won! game has ended!");
        *gameEnd = true; //
    }
    else if (gameGrid[1][0] == 'X' && gameGrid[1][1] == 'X' && gameGrid[1][2] == 'X')
    {
        printf("X has won! game has ended!");
        *gameEnd = true; //
    }
    else if (gameGrid[2][0] == 'X' && gameGrid[2][1] == 'X' && gameGrid[2][2] == 'X')
    {
        printf("X has won! game has ended!"); // 789
        *gameEnd = true;
    }
    else if (gameGrid[0][2] == 'X' && gameGrid[1][2] == 'X' && gameGrid[2][2] == 'X')
    {
        printf("X has won! game has ended!"); //369
        *gameEnd = true;
    }
    else if (gameGrid[0][0] == 'X' && gameGrid[1][1] == 'X' && gameGrid[2][2] == 'X')
    {
        printf("X has won! game has ended!"); //159
        *gameEnd = true;
    }
    else if (gameGrid[0][2] == 'X' && gameGrid[1][1] == 'X' && gameGrid[2][0] == 'X')
    {
        printf("X has won! game has ended!"); // 357
        *gameEnd = true;
    }


}

void winConditionO(char (*gameGrid)[GRID], bool *gameEnd) //check if a player has won the game
{

    if (gameGrid[0][0] == 'O' && gameGrid[0][1] == 'O' && gameGrid[0][2] == 'O')
    {
        printf("O has won! game has ended!");
        *gameEnd = true;
    }
        else if (gameGrid[0][0] == 'O' && gameGrid[1][0] == 'O' && gameGrid[2][0] == 'O')
    {
        printf("O has won! game has ended!");
        *gameEnd = true;
    }

    else if (gameGrid[0][1] == 'O' && gameGrid[1][1] == 'O' && gameGrid[2][1] == 'O')
    {
        printf("O has won! game has ended!");
        *gameEnd = true; //
    }
    else if (gameGrid[1][0] == 'O' && gameGrid[1][1] == 'O' && gameGrid[1][2] == 'O')
    {
        printf("O has won! game has ended!");
        *gameEnd = true; //
    }
    else if (gameGrid[2][0] == 'O' && gameGrid[2][1] == 'O' && gameGrid[2][2] == 'O')
    {
        printf("O has won! game has ended!"); // 789
        *gameEnd = true;
    }
    else if (gameGrid[0][2] == 'O' && gameGrid[1][2] == 'O' && gameGrid[2][2] == 'O')
    {
        printf("O has won! game has ended!"); //369
        *gameEnd = true;
    }
    else if (gameGrid[0][0] == 'O' && gameGrid[1][1] == 'O' && gameGrid[2][2] == 'O')
    {
        printf("O has won! game has ended!"); //159
        *gameEnd = true;
    }
    else if (gameGrid[0][2] == 'O' && gameGrid[1][1] == 'X' && gameGrid[2][0] == 'O')
    {
        printf("O has won! game has ended!"); // 357
        *gameEnd = true;
    }


}





int choosePosition(char (*gameGrid)[GRID], char *playerSign, int *who)
{

    printf("\nwho is playing? player %d\n",*who);
    reset:printf("\nEnter the position of your mark 1-9");
    int choice;
    scanf("%d", &choice);

    if (choice>=1 && choice<=9)
    {


        switch(choice)
        {
        case 1:
            if (gameGrid[0][0] == 0)
            gameGrid[0][0] = *playerSign;
                else
                    goto reset;
            break;
        case 2:
            if (gameGrid[0][1] ==0)
            gameGrid[0][1] = *playerSign;
                else
                    goto reset;
            break;
        case 3:
            if (gameGrid[0][2] ==0)
            gameGrid[0][2] = *playerSign;
            else
                    goto reset;
            break;
        case 4:
            if (gameGrid[1][0] ==0)
            gameGrid[1][0] = *playerSign;
            else
                    goto reset;
            break;
        case 5:
            if (gameGrid[1][1] ==0)
            gameGrid[1][1] = *playerSign;
            else
                    goto reset;
            break;
        case 6:
            if (gameGrid[1][2] ==0)
            gameGrid[1][2] = *playerSign;
            else
                    goto reset;
            break;
        case 7:
            if (gameGrid[2][0] ==0)
            gameGrid[2][0] = *playerSign;
            else
                    goto reset;
            break;
        case 8:
            if (gameGrid[2][1] ==0)
            gameGrid[2][1] = *playerSign;
            else
                    goto reset;
            break;
        case 9:
            if (gameGrid[2][2] ==0)
            gameGrid[2][2] = *playerSign;
            else
                    goto reset;
            break;

        }
    }

    else goto reset;

    if(*who ==1)
    {
        *who = 2;
    }
    else if(*who ==2)
    {
        *who = 1;
    }
    //printf("\nwho is playing? now WILL player %d\n",*who);
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

void selectSign(char *p1Sign, char *p2Sign)

{
    poczatek:
    printf("\nPlayer 1: Select your symbol. 'X' or 'O' ? Type..");
    scanf("%c", p1Sign);

        if (*p1Sign == 'X' || *p1Sign == 'O')
        {

            reset2:printf("\nPlayer 2: Select your symbol. 'X' or 'O' ? Type.."); //reset condition
            scanf(" %c", p2Sign);

                if (*p1Sign == *p2Sign) // secure the choice - doubled sign is not allowed
                {
                    printf("You are not allowed to double this sign - %c. Try again!\n", *p1Sign);
                    goto reset2;
                }

                    else if (*p2Sign == 'X' || *p2Sign == 'O')
                    {
                         return 0; // wybor normalny
                    }

                        else
                            {
                                printf("You are not allowed to use this character. Try again!");
                                goto reset2;
                            }
        }

        else
        {

            printf("You are not allowed to use this character. Try again!\n");
            goto poczatek;
        }

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
