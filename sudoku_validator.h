#ifndef sudoku_validator
#define sudoku_validator

// ======================== Defines ========================
#define ROWS 9
#define COLUMNS 9
#define SUBGRID 3
// ======================== Defines ========================

// ======================== Functions ========================
void printsudoku(int[ROWS][COLUMNS]);
void printSubgrid(int, int, int[ROWS][COLUMNS]);
bool validateRow(int, int[ROWS][COLUMNS]);
bool validateColumn(int, int[ROWS][COLUMNS]);
bool validateSubgrid(int, int, int[ROWS][COLUMNS]);
// ======================== Functions ========================

#endif