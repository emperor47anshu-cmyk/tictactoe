#include <stdio.h>

char checkWinner(char board[3][3]);
void printBoard(char board [3 ][3]);



int main(void)
{
    char board [3] [3] = {
        {'1' ,'2' , '3'},
        {'4' , '5' , '6'},
        {'7' , '8' , '9'},
    };
    printf("Have Fun\n");


   
    char current_player = 'X';
    int moves = 0;
    while (moves < 9)
    {
        printBoard(board);

        int choice;
        printf("player %c,enter a number(1-9):",current_player);
        scanf("%i",&choice);
        if(choice > 9 || choice < 1)
        {
            printf("Invalid move!Please pick a number between (1-9)\n\n");
            continue;
        }


      int row = (choice -1) /3;
      int column = (choice -1) %3;
      board[row][column] = current_player;

      char winner = checkWinner(board);
      if(winner != 'N')
      {
        printBoard(board);
        printf("\n Player %c WINS!\n",winner);

    break;
      }
    

      if (current_player == 'X')
      {
        current_player ='O';
      }
      else 
      {
        current_player = 'X';
      }
       moves++;
    }

   if(moves == 9)
    {
        printBoard(board);
        printf("Draw\n");
    }


}


char checkWinner(char board[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }


    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i];
        }

    }


    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];

    }


    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }
    return 'N'; 

}



    void printBoard(char board [3 ][3]){

        printf("\n");
        for(int i = 0; i < 3; i++)
        {
            printf("%c | %c | %c \n" ,
                board[i][0],
                 board[i][1],
                 board[i][2]);

                 if(i < 2)
                 {
                    printf("---+---+---\n");
                 }
        }
        printf("\n");
    }
