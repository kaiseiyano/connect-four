#ifndef BOARD_H
#define BOARD_H

#define ROWS 6
#define COLS 7
#define EMPTY 0
#define PIECE_x 1
#define PIECE_o 2

struct Board {
    int cells[ROWS][COLS]; // row 0 is the bottom row
};

char symbol(int piece);
void init(struct Board *board);
void display(const struct Board *board);
int update(struct Board *board, int x, int y, int piece);

#endif
