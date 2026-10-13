#include "board.h"
#include <stdio.h>

void init(struct Board *board) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            (*board).cells[r][c] = EMPTY;
        }
    }
}

void display(const struct Board *board) {
    printf("\n");
    for (int r = ROWS-1; r>=0; r--) {
        for (int c=0; c<COLS; c++) {
            if (board->cells[r][c] == EMPTY) {
                printf("□ ");
            } else {
                printf("%c ", _get_symbol(board->cells[r][c]));
            }
        }
        printf("\n");
    }
}

int update(struct Board *board, int x, int y, int piece) {
    if (x<0 || x>=COLS || y<0 || y>=ROWS) {
        return 0;
    }
    if (board->cells[y][x] != EMPTY) {
        return 0;
    }
    if (y>0 && board->cells[y-1][x] == EMPTY) {
        return 0;
    }
    board->cells[y][x] = piece;
    return 1;
}

char _get_symbol(int piece){
    if (piece == PIECE_x) {
        return 'X';
    } else if (piece == PIECE_o) {
        return 'O';
    } else {
        return ' ';
    }
}