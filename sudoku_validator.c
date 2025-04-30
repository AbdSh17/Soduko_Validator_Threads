#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sudoku_validator.h"

bool validateRow(int row, int sudoku[ROWS][COLUMNS])
{
    int count = 0;
    int validation_array[ROWS]; // {1 -> ROWS}
    for (int i = 0; i < ROWS; i++)
    {
        validation_array[i] = i + 1; // (0 + 1) -> (24 + 1)
    }

    for (int j = 0; j < ROWS; j++)
    {
        int sudoku_number = sudoku[row][j];
        if (sudoku_number < 1 || sudoku_number > ROWS)
        {
            return false;
        }

        validation_array[sudoku_number - 1] = 0;
    }

    for (int i = 0; i < ROWS; i++)
    {
        if (validation_array[i] != 0)
        {
            return false;
        }
    }

    return true;
}

bool validateColumn(int column, int sudoku[ROWS][COLUMNS])
{
    int count = 0;
    int validation_array[ROWS]; // {1 -> ROWS}
    for (int i = 0; i < ROWS; i++)
    {
        validation_array[i] = i + 1; // (0 + 1) -> (24 + 1)
    }

    for (int i = 0; i < COLUMNS; i++)
    {
        int sudoku_number = sudoku[i][column];

        if (sudoku_number < 1 || sudoku_number > ROWS)
        {
            return false;
        }

        validation_array[sudoku_number - 1] = 0;
    }

    for (int i = 0; i < ROWS; i++)
    {
        if (validation_array[i] != 0)
        {
            return false;
        }
    }

    return true;
}

bool validateSubgrid(int row, int column, int sudoku[ROWS][COLUMNS])
{
    row *= SUBGRID;
    column *= SUBGRID;

    int validation_array[SUBGRID * SUBGRID]; // {1 -> ROWS}
    for (int i = 0; i < (SUBGRID * SUBGRID); i++)
    {
        validation_array[i] = i + 1; // (0 + 1) -> (24 + 1)
    }

    int count = 0;
    for (int i = row; i < SUBGRID + row; i++)
    {
        for (int j = column; j < SUBGRID + column; j++)
        {
            int sudoku_number = sudoku[i][j];
            if (sudoku_number < 1 || sudoku_number > ROWS)
            {
                return false;
            }
            validation_array[sudoku_number - 1] = 0;
        }
    }

    for (int i = 0; i < (SUBGRID * SUBGRID); i++)
    {
        if (validation_array[i] != 0)
        {
            return false;
        }
    }

    return true;
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
    row *= SUBGRID;
    column *= SUBGRID;

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
