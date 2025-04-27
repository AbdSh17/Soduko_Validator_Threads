#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sudoku_validator.h"

bool validateRow(int row, int sudoku[ROWS][COLUMNS])
{
    int count = 0;
    for (int j = 0; j < COLUMNS; j++)
    {
        count += sudoku[row][j];
    }
    return count == 45;
}

bool validateColumn(int column, int sudoku[ROWS][COLUMNS])
{
    int count = 0;
    for (int i = 0; i < COLUMNS; i++)
    {
        count += sudoku[i][column];
    }
    return count == 45;
}

bool validateSubgrid(int row, int column, int sudoku[ROWS][COLUMNS])
{
    row *= SUBGRID;
    column *= SUBGRID;
    int count = 0;
    for (int i = row; i < SUBGRID + row; i++)
    {
        for (int j = column; j < SUBGRID + column; j++)
        {
            count += sudoku[i][j];
        }
    }
    return count == 45;
}

void printsudoku(int sudoku[ROWS][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {

            printf("%d ", sudoku[i][j]);
            if (!((j + 1) % SUBGRID))
            {
                printf("| ");
            }
        }
        printf("\n");
        if (!((i + 1) % SUBGRID))
        {
            printf("-------------------------\n");
        }
    }
}

void printSubgrid(int row, int column, int sudoku[ROWS][COLUMNS])
{
    row *= 3;
    column *= 3;
    for (int i = row; i < row + SUBGRID; i++)
    {
        for (int j = column; j < column + SUBGRID; j++)
        {
            printf("%d ", sudoku[i][j]);
        }
        printf("|");
        printf("\n");
    }
}
