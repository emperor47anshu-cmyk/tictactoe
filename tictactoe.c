#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

void printBoard(char board [3 ][3],int cursor_row,int cursor_col);
char checkWinner(char board[3][3]);
int isboardfull(char board[3][3]);
int minimax(char board[3][3] ,int depth , int isMaximizing ,char algo , char player);
void findbestmove (char board[3][3] , char algo , char player,int difficulty);

int main()
{
    char board [3] [3] = {
        {'1' ,'2' , '3'},
        {'4' , '5' , '6'},
        {'7' , '8' , '9'},
    };
    printf("Have Fun\n");

    int gamemode;
    int difficulty = 3;
    char player,algo;
    while(1)
    {
    printf("1.Player Vs Player\n");
    printf("2.Player vs AI\n");
    printf("choose your mode(1 or 2):");
    if(scanf("%d",&gamemode) == 1)
    {
        if(gamemode == 1 || gamemode == 2)
        {
            break;
        }
        else{
            printf("Invalid number! Please choose 1 or 2.\n");
        }
    }
    else 
    {
        printf("Invalid input! Please enter a number\n");
    }
        while(getchar() != '\n');
    }

     if(gamemode == 2)
    {
        while(1)
        {
            printf("\n");
            printf("                          \n");
            printf("   SELECT AI DIFFICULTY   \n");
            printf("                          \n");
            printf(" 1. Easy  \n");
            printf(" 2. Medium  \n");
            printf(" 3. Hard  \n");
            printf("                          \n");
            printf("Enter Your Choice (1-3)");

        if(scanf("%d",&difficulty) == 1)
        {
            if(difficulty >= 1 && difficulty <= 3)
            {
                break;
            }
            else{
                printf("Invalid number! Please choose 1 ,2 or 3.\n");
            }
        }
        else
        {
            printf("Invalid input! Please enter a number\n");
        }
         while(getchar() != '\n');
        }
    }
while(1)
{
    printf("Do U want to be X or O:");
        scanf( " %c",&player);
         while(getchar() != '\n');

        if(player == 'X' || player == 'x')
        {
            player = 'X';
            algo = 'O';
            break;
        }
        else if(player == 'O' || player == '0' || player == 'o')
        {
            player = 'O';
            algo = 'X'; 
            break;
        }
        else{
            printf("Invalid choice! please type exactly X or O.\n");
        }
    }
   
    char current_player = 'X';
    int moves = 0;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    
    int cursor_row = 0;
    int cursor_col = 0;

    while (moves < 9)
    {
        if (current_player == player || gamemode == 1)
        {
            int selected = 0;
            while (!selected)
            {
                printBoard(board,cursor_row,cursor_col);
                int input = getch();

                if (input == KEY_UP && cursor_row > 0)cursor_row--;
                if (input == KEY_DOWN && cursor_row < 2)cursor_row++;
                if (input == KEY_LEFT && cursor_col > 0)cursor_col--;
                if (input == KEY_RIGHT && cursor_col < 2)cursor_col++;

                if (input == 10)
                {
                    if(board[cursor_row][cursor_col] >= '1' &&board[cursor_row][cursor_col] <= '9' )
                    {
                        board[cursor_row][cursor_col] = current_player;
                        selected = 1;
                    }
                }

            }
        }  
            else if(gamemode == 2)
            {
                mvprintw(15,10,"AI is thinking....");
                refresh();
                findbestmove(board,algo,player,difficulty);
            }
    


    char winner = checkWinner(board);
    if(winner == 'X' || winner == 'O')
    {
        printBoard(board,cursor_row,cursor_col);
        endwin();
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

if (moves == 9)
    {
        printBoard(board,cursor_row,cursor_col);
        endwin();
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



    void printBoard(char board [3 ][3],int cursor_row,int cursor_col)
    {
        clear();
        mvprintw(2,10,"=== TIC-TAC-TOE ===");

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if (i == cursor_row && j == cursor_col)
                {
                    attron(A_REVERSE);
                }
                if (board[i][j] >= '1' && board[i][j] <= '9')
                {
                    mvprintw(5 + (i*2),15 +(j*4),".");
                }
                else
                {
                    mvprintw(5 + (i*2),15 +(j*4),"%c",board[i][j]);
                }
                if (i == cursor_row &&  j == cursor_col)
                {
                    attroff(A_REVERSE);
                }
            }
        }
        mvprintw(12,10,"Use Arrow Keys to Move.Press ENTER to select.");
        refresh();
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

    void findbestmove (char board[3][3] , char algo , char player,int difficulty)
    {
        int use_minimax = 1;

        if(difficulty == 1)
        {
            use_minimax = 0;
        }
        else if(difficulty ==2)
        {
            int chance = rand() % 100;

        if(chance < 50)
        {
            use_minimax = 0;
        }
        }

        if(use_minimax == 0)
        {
            int valid = 0;
            while (valid == 0)
            {
                int r = rand() % 3;
                int c = rand() % 3;

                if(board[r][c] > '1' && board[r][c] < '9')
                {
                    board[r][c] = algo;
                    valid = 1;
                }
            }
            return;
        }
        

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