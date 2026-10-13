#include "board.h"
#include <stdio.h>

char symbol (int piece){
    if (piece == PIECE_x) {
        return 'X';
    } else if (piece == PIECE_o) {
        return 'O';
    } else {
        return ' ';
    }
}

void initial(struct Board *board) {
    for (int c=0; c<COLS; c++) {
        board->height[c] = 0;
        for (int r=0; r<ROWS; r++) {
            board->cells[r][c] = EMPTY;
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
                printf("%c ", symbol(board->cells[r][c]));
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