#include <stdio.h>
#include <stdlib.h>

int board[20][20];
int n;

int isSafe(int row, int col)
{
    int i, j;

    // Check column
    for(i = 0; i < row; i++)
        if(board[i][col])
            return 0;

    // Check upper-left diagonal
    for(i = row-1, j = col-1;
        i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return 0;

    // Check upper-right diagonal
    for(i = row-1, j = col+1;
        i >= 0 && j < n; i--, j++)
        if(board[i][j])
            return 0;

    return 1;
}

void solveNQueens(int row)
{
    int col, i, j;

    if(row == n)
    {
        printf("\nSolution:\n");

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                printf("%d ", board[i][j]);

            printf("\n");
        }
        return;
    }

    for(col = 0; col < n; col++)
    {
        if(isSafe(row, col))
        {
            board[row][col] = 1;

            solveNQueens(row + 1);

            // Backtracking
            board[row][col] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if(n < 1 || n > 20)
    {
        printf("Invalid input");
        return 0;
    }

    solveNQueens(0);

    return 0;
}