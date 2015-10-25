#include "pre.h"

int board[SIZES],n;

void queen(int row,int n);
int place(int row,int col);
void printBoard();

int main(int argc, char const *argv[])
{
	printf("Enter n\n");
	 scanf("%d",&n);

	queen(1,n);
	return 0;
}

void queen(int row,int n)
{
	int col;
	for ( col = 1; col <= n; col++)
	{
		if(place(row,col))
		{
			board[row] = col;

			if (row == n)
			{
				printBoard();
			}

			else queen(row+1,n);
		}
	}
}

int place(int row,int col)
{
	int i;
	for (i = 1; i <= row-1 ; i++)
	{
		if(board[i] == col) return 0;

		else if(abs(board[i] - col) == abs(i - row)) return 0;
	}

	return 1;
}

void printBoard()
{
	int i,j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if(board[i] == j) printf(" Q ");

			else printf(" . ");
		}
		printf("\n");
	}

   getch();
}