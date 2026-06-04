#include <stdio.h>

void printBoard(char board [3 ][3]);
char checkWinner(char board[3][3]);
int isboardfull(char board[3][3]);
int minimax(char board[3][3] ,int depth , int isMaximizing ,char algo , char player);
void findbestmove (char board[3][3] , char algo , char player);



int main()
{
    char board [3] [3] = {
        {'1' ,'2' , '3'},
        {'4' , '5' , '6'},
        {'7' , '8' , '9'},
    };
    printf("Have Fun\n");


    int gamemode;
    char player,algo;


    printf("1.Player Vs Player\n");
    printf("2.Player vs AI\n");
    printf("choose your mode(1 or 2):");
    scanf("%d",&gamemode);

        printf("Do U want to be X or O:");
        scanf( " %c",&player);

        if(player == 'X' || player == 'x')
        {
            player = 'X';
            algo = 'O';
        }
        else
        {
            player = 'O';
            algo = 'X'; 
        }
   
    char current_player = 'X';
    int moves = 0;
    while (moves < 9)
    {
        printBoard(board);

        if(current_player == player)
        {
            int choice;
            printf("\nPlayer 1 (%c),enter a number(1-9):",player);
            scanf("%d",&choice);

            if (choice < 1 || choice > 9)
            {
                printf("Invalid Input!Please choose between(1-9)");
                continue;
            }
   
      int row = (choice -1) /3;
      int col = (choice -1) %3;
     if( board[row][col] < '1'||board[row][col] > '9')
     {
        printf("Spot already taken!Please Pick another.\n");
        continue;
     }
     board[row][col] = current_player;
        }  
        else
        {
            if(gamemode == 1)
            {
                int choice;
                printf("\nPlayer 2(%c),enter a number(1-9):",algo);
                scanf("%d",&choice);
                
                if(choice < 1 || choice > 9)
                {
                    printf("Invalid Input!Please choose between(1-9)");
                    continue;
                }
                 int row = (choice -1) /3;
                 int col = (choice -1) %3;
                 if( board[row][col] < '1'||board[row][col] > '9')
                    {
                        printf("Spot already taken!Please Pick another.\n");
                         continue;
                    }
                      board[row][col] = current_player;
  
            }
            else if(gamemode == 2)
    {
        printf("\nAI is thinking....\n");
        findbestmove(board,algo,player);
    }
        } 
    
    

    char winner = checkWinner(board);
    if(winner == 'X' || winner == 'O')
    {
        printBoard(board);
        if(winner == player)
        {
            printf("\nPlayer 1(%c) Wins!\n",winner);
        }
        
        else if (gamemode == 1)
        {
            printf("\nPlayer 2(%c)Wins!\n",winner);
        }
        
        else
        {
            printf("\nAI (%c) Wins! Better Luck next time.\n",winner);
            
        }
    break;    
    }

      if (current_player == player)
      {
        current_player = algo;
      }
      else 
      {
        current_player = player;
      }
       moves++;
    }

   if(moves == 9)
    {
        printBoard(board);
        printf("Draw\n");
    }
    return 0;
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



    void printBoard(char board [3 ][3])
    {

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



    int minimax(char board[3][3] ,int depth , int isMaximizing ,char algo , char player)
    {
        char winner = checkWinner(board);

        if (winner == algo)
        {
            return 10 - depth;
        }
        

    if (winner == player)
    {
        return -10 + depth;
    }
    if (isboardfull(board))
    {
        return 0;
    }

    if(isMaximizing)
    {
        int bestValue = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    char original = board[i][j];
                    board[i][j] = algo;
                    int value = minimax(board, depth + 1, 0, algo, player);
                    board[i][j] = original;
                    if (value > bestValue)
                    {
                        bestValue = value;
                    }
                }
            }
        }
        return bestValue;
    }
    else
    {
        int bestvalue = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9')
                {
                    char original = board[i][j];
                    board[i][j] = player;

                    int value = minimax(board,depth + 1,1,algo,player);
                    
                    
                    board[i][j] = original;
                    if(value < bestvalue)
                    {
                        bestvalue = value;
                    }

                }
            }
        }
        return bestvalue;
    }


    
    }

    int isboardfull(char board[3][3])
    {
        for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[i][j] >= '1' && board[i][j] <= '9')
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    void findbestmove (char board[3][3] , char algo , char player)
    {
        int bestscore = -1000;
        int best_row = -1;
        int best_col = -1;


        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9')
                {
                    char original = board[i][j];
                    board[i][j] = algo;
                    int score = minimax(board ,0 , 0,algo,player);


                    board[i][j] = original;
                    if(score > bestscore)
                    {
                        bestscore = score;
                        best_row = i;
                        best_col = j;
                    }
                }
            }
        }
        if (best_row == -1 && best_col == -1)
        {
            for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] != 'X' && board[i][j] != 'O')
                {
                    best_col =j;
                    best_row = i;
                    break;
                }
            }
            if (best_row != -1)break;
        }
        }
        board[best_row][best_col] = algo;
    }