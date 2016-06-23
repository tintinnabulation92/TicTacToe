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
void winConditionX(char (*gameGrid)[GRID], bool *gameEnd, int *p1Score);
void winConditionO(char (*gameGrid)[GRID], bool *gameEnd, int *p2Score);
void restartGame(char (*gameGrid)[GRID], int *restart);

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
    int _p1Score = 0;
    int _p2Score = 0;
    int _restartCondition = 1;

    bool _gameEnd = false;
    int _whoPlays = 1; // 1 == game continues
    drawGrid();
    welcomePlayer(_playerOne, _playerTwo);
    selectSign(&_playerOneSign, &_playerTwoSign);
    printf("\n The following players are playing: %s and %s.\n\n", _playerOne, _playerTwo); // commented
    printf("Player 1 has chosen %c and player 2 has chosen %c \n\n", _playerOneSign, _playerTwoSign);
    //choosePosition(_gameGrid);

    //refreshGrid(_gameGrid);

    printf("Player 1 starts.\n\n"); //_whoPlays = 1

    //refreshGrid(_gameGrid);

    OnceAgain:_gameEnd = false;

    int u,i;
    for(u = 0; u < 3; u++)
{
    for(i = 0; i < 3; i++)
    {
        _gameGrid[u][i] = 0; //clearing out the array
    }
}


    while(_gameEnd == false) //as long as the game goest
    {
        if (_whoPlays == 1 && draw<9)
        {
            choosePosition(_gameGrid, &_playerOneSign, &_whoPlays); //players turn
            refreshGrid(_gameGrid);
            winConditionX(&_gameGrid, &_gameEnd, &_p1Score);
            winConditionO(&_gameGrid, &_gameEnd, &_p2Score);
            ++draw;

        }

        else if (_whoPlays == 2 && draw<9)
        {
            choosePosition(_gameGrid, &_playerTwoSign, &_whoPlays); //players turn
            refreshGrid(_gameGrid);
            winConditionX(&_gameGrid, &_gameEnd, &_p1Score);
            winConditionO(&_gameGrid, &_gameEnd, &_p2Score);
            ++draw;
        }

        else {
            printf("\nDraw! game is over\n");
            _gameEnd = true;
        }

    }

    if (_gameEnd == true)
    {
        //restartGame(&_gameGrid, &_restartCondition);
        memset(_gameGrid, 0, sizeof(_gameGrid[GRID][GRID]) * 3 * 3);
        printf("\nPlayer 1 - %s score is: %d. Player 2 - %s Score is %d.\n",_playerOne, _p1Score, _playerTwo, _p2Score);
        printf("\nWould you like to play again? 1 = YES. 2 = NO and Quit.");
        scanf("%d", &_restartCondition);

            printf("\n");
            if (_restartCondition == 1)
            {
                //_gameGrid[GRID][GRID] = {0};

                draw = 0;
                goto OnceAgain;


            }

    }


    return 0;
}

//////////////////////////////////////////////
//MODULES&FUNCTIONS///////////////////////////
//////////////////////////////////////////////

void winConditionX(char (*gameGrid)[GRID], bool *gameEnd, int *p1Score) //check if a player has won the game
{



    if (gameGrid[0][0] == 'X' && gameGrid[0][1] == 'X' && gameGrid[0][2] == 'X')
    {
        printf("X has won! game has ended!");
        *p1Score = *p1Score+1;
        *gameEnd = true;
    }
        else if (gameGrid[0][0] == 'X' && gameGrid[1][0] == 'X' && gameGrid[2][0] == 'X')
    {
        printf("X has won! game has ended!");
        *p1Score = *p1Score+1;
        *gameEnd = true;
    }

    else if (gameGrid[0][1] == 'X' && gameGrid[1][1] == 'X' && gameGrid[2][1] == 'X')
    {
        printf("X has won! game has ended!");
        *p1Score = *p1Score+1;
        *gameEnd = true; //
    }
    else if (gameGrid[1][0] == 'X' && gameGrid[1][1] == 'X' && gameGrid[1][2] == 'X')
    {
        printf("X has won! game has ended!");
        *p1Score = *p1Score+1;
        *gameEnd = true; //
    }
    else if (gameGrid[2][0] == 'X' && gameGrid[2][1] == 'X' && gameGrid[2][2] == 'X')
    {
        printf("X has won! game has ended!"); // 789
        *p1Score = *p1Score+1;
        *gameEnd = true;
    }
    else if (gameGrid[0][2] == 'X' && gameGrid[1][2] == 'X' && gameGrid[2][2] == 'X')
    {
        printf("X has won! game has ended!"); //369
        *p1Score = *p1Score+1;
        *gameEnd = true;
    }
    else if (gameGrid[0][0] == 'X' && gameGrid[1][1] == 'X' && gameGrid[2][2] == 'X')
    {
        printf("X has won! game has ended!"); //159
        *p1Score = *p1Score+1;
        *gameEnd = true;
    }
    else if (gameGrid[0][2] == 'X' && gameGrid[1][1] == 'X' && gameGrid[2][0] == 'X')
    {
        printf("X has won! game has ended!"); // 357
        *p1Score = *p1Score+1;
        *gameEnd = true;
    }


}

void winConditionO(char (*gameGrid)[GRID], bool *gameEnd, int *p2Score) //check if a player has won the game
{

    if (gameGrid[0][0] == 'O' && gameGrid[0][1] == 'O' && gameGrid[0][2] == 'O')
    {
        printf("O has won! game has ended!");
        *p2Score = *p2Score + 1;
        *gameEnd = true;
    }
        else if (gameGrid[0][0] == 'O' && gameGrid[1][0] == 'O' && gameGrid[2][0] == 'O')
    {
        printf("O has won! game has ended!");
        *p2Score = *p2Score + 1;
        *gameEnd = true;
    }

    else if (gameGrid[0][1] == 'O' && gameGrid[1][1] == 'O' && gameGrid[2][1] == 'O')
    {
        printf("O has won! game has ended!");
        *p2Score = *p2Score + 1;
        *gameEnd = true; //
    }
    else if (gameGrid[1][0] == 'O' && gameGrid[1][1] == 'O' && gameGrid[1][2] == 'O')
    {
        printf("O has won! game has ended!");
        *p2Score = *p2Score + 1;
        *gameEnd = true; //
    }
    else if (gameGrid[2][0] == 'O' && gameGrid[2][1] == 'O' && gameGrid[2][2] == 'O')
    {
        printf("O has won! game has ended!"); // 789
        *p2Score = *p2Score + 1;
        *gameEnd = true;
    }
    else if (gameGrid[0][2] == 'O' && gameGrid[1][2] == 'O' && gameGrid[2][2] == 'O')
    {
        printf("O has won! game has ended!"); //369
        *p2Score = *p2Score + 1;
        *gameEnd = true;
    }
    else if (gameGrid[0][0] == 'O' && gameGrid[1][1] == 'O' && gameGrid[2][2] == 'O')
    {
        printf("O has won! game has ended!"); //159
        *p2Score = *p2Score + 1;
        *gameEnd = true;
    }
    else if (gameGrid[0][2] == 'O' && gameGrid[1][1] == 'X' && gameGrid[2][0] == 'O')
    {
        printf("O has won! game has ended!"); // 357
        *p2Score = *p2Score + 1;
        *gameEnd = true;
    }


}





int choosePosition(char (*gameGrid)[GRID], char *playerSign, int *who)
{
    int choice = 0;
    printf("\nPlayer %d is playing.\n",*who);
    reset:printf("\nEnter the position of your mark (1-9)\n");


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
    *p1Sign = 'X'; *p2Sign = 'O'; //automatic assign


//    poczatek:
//        *p1Sign = 0; *p2Sign = 0;
//    printf("\nPlayer 1: Select your symbol. 'X' or 'O' ? Type..\n");
//    scanf(" %c", p1Sign);
//
//        if (*p1Sign == 'X' || *p1Sign == 'O')
//        {
//
//            reset2:printf("\nPlayer 2: Select your symbol. 'X' or 'O' ? Type.."); //reset condition
//            scanf(" %c", p2Sign);
//
//                if (*p1Sign == *p2Sign) // secure the choice - doubled sign is not allowed
//                {
//                    printf("You are not allowed to double this sign - %c. Try again!\n", *p1Sign);
//                    goto reset2;
//                }
//
//                    else if (*p2Sign == 'X' || *p2Sign == 'O')
//                    {
//                         return 0; // wybor normalny
//                    }
//
//                        else
//                            {
//                                printf("You are not allowed to use this character. Try again!");
//                                goto reset2;
//                            }
//        }
//
//        else
//        {
//
//            printf("You are not allowed to use this character. Try again!\n");
//            goto poczatek;
//        }

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

//void restartGame(char (*gameGrid)[GRID], int *restart)
//{
//
//    printf("\nWould you like to play again? 1 = YES. 2 = NO and Quit.");
//    scanf("%d", restart);
//
//    printf("\n");
//    if (restart == 1)
//    {
//        gameGrid[GRID][GRID] = {0};
//    }
//
//    else if (restart == 2)
//    {
//
//    }
//}
