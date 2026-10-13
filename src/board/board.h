#ifndef BOARD_H
#define BOARD_H

#define ROWS 6
#define COLS 7
#define EMPTY 0
#define PIECE_x 1
#define PIECE_o 2

#include <stdbool.h>

struct Board {
    int cells[ROWS][COLS]; // row 0 is the bottom row
};

void init(struct Board *board);
void display(const struct Board *board);
int update(struct Board *board, int col, int piece);
int get_open_row_from_col(const struct Board *board, int col);
int is_valid_row(struct Board *board, int row);
int is_valid_col(struct Board *board, int col);
bool validateWin(const struct Board *board, int c);
char _get_symbol(int piece);

#endif