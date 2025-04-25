#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// ======================== Functions ========================
void printSoduko();
void printSubgrid(int, int);
bool validateRow();
bool validateColumn();
bool validateAllSubgrids();
bool validateSubgrid(int, int);
bool validateSoduko();
// ======================== Functions ========================

// ======================== Defines ========================
#define ROWS 9
#define COLUMNS 9
#define SUBGRID 3
// ======================== Defines ========================

int sudoku[9][9] = {
    {8, 2, 7, 1, 5, 4, 3, 9, 6},
    {9, 6, 5, 3, 2, 7, 1, 4, 8},
    {3, 4, 1, 6, 8, 9, 7, 5, 2},
    {5, 9, 3, 4, 6, 8, 2, 7, 1},
    {4, 7, 2, 5, 1, 3, 6, 8, 9},
    {6, 1, 8, 9, 7, 2, 4, 3, 5},
    {7, 8, 6, 2, 3, 5, 9, 1, 4},
    {1, 5, 4, 7, 9, 6, 8, 2, 3},
    {2, 3, 9, 8, 4, 1, 5, 6, 7}};

int main()
{

    printf("%d  ", validateSoduko());
    printf("\n");
    return 0;
}

bool validateSoduko()
{
    return (validateColumn() && validateRow() && validateAllSubgrids());
}

bool validateRow()
{
    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for (int j = 0; j < COLUMNS; j++)
        {
            count += sudoku[i][j];
        }
        if (count != 45)
        {
            return false;
        }
    }

    return true;
}

bool validateColumn()
{
    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for (int j = 0; j < COLUMNS; j++)
        {
            count += sudoku[j][i];
        }
        if (count != 45)
        {
            return false;
        }
    }
    return true;
}

bool validateAllSubgrids()
{
    for (int i = 0; i < SUBGRID; i++)
    {
        for (int j = 0; j < SUBGRID; j++)
        {
            if (!validateSubgrid(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

bool validateSubgrid(int row, int column)
{
    row *= 3;
    column *= 3;
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

void printSoduko()
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

void printSubgrid(int row, int column)
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
