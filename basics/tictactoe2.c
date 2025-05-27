#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[9]; // = {'1','2','3','4','5','6','7','8','9'};
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main()
{
   char winner = ' ';
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         playerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
            break;

         computerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
            break;
      }

      printBoard();
      printWinner(winner);

   printf("\nThanks for playing!");

   return -1;
}

void resetBoard()
{
   for(int i = 0; i < 9; i++)
         board[i] = ' ';     
}

void printBoard()
{
   printf(" %c | %c | %c ", board[0], board[1], board[2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[3], board[4], board[5]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[6], board[7], board[8]);
   printf("\n");
}

int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 9; i++)
   {
         if(board[i] != ' ')
            freeSpaces--;   
   }
   return freeSpaces;
}

void playerMove()
{
   int x;
   do
   {
      printf("Enter the number: ");
      scanf("%d", &x);
      x--;

      if(board[x] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[x] = PLAYER;
         break;
      }
   } while (board[x] != ' ');
   
}

void computerMove()
{
   //creates a seed based on current time
   srand(time(0));
   int x;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 9;
      } while (board[x] != ' ');
      
      board[x] = COMPUTER;
   }
   else
      printWinner(' ');
}

char checkWinner()
{
   //check rows
      if(board[0] == board[1] && board[0] == board[2])
         return board[0];

      else if(board[3] == board[4] && board[3] == board[5])
         return board[3];

      else if(board[6] == board[7] && board[6] == board[8])
         return board[6];      

   //check columns
      else if(board[0] == board[3] && board[0] == board[6])
         return board[0];

      else if(board[1] == board[4] && board[1] == board[7])
         return board[1];

      else if(board[2] == board[5] && board[2] == board[8])
         return board[2];      

   //check diagonals
      else if(board[0] == board[4] && board[0] == board[8])
         return board[0];

      else if(board[6] == board[4] && board[6] == board[2])
         return board[6];

      else
         return ' ';
}

void printWinner(char winner)
{
   if(winner == PLAYER)
      printf("\nYOU WIN! :)");
   else if(winner == COMPUTER)
      printf("\nYOU LOSE! :(");
   else
      printf("\nIT'S A TIE! -_-");
}