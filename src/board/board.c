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

    for (int r = ROWS - 1; r >= 0; r--) {
        for (int c = 0; c < COLS; c++) {
            if (board->cells[r][c] == EMPTY) {
                printf("□ ");
            } else {
                printf("%c ", _get_symbol(board->cells[r][c]));
            }
        }

        printf("\n");
    }
}

int update(struct Board *board, int col, int piece) {
    if (!is_valid_col(board, col)) {
        return 0;
    }

    int row = get_open_row_from_col(board, col);

    if (row == -1) {
        return 0;
    }

    (*board).cells[row][col] = piece;

    return 1;
}

int get_open_row_from_col(struct Board *board, int col) {
    for (int r = 0; r < ROWS; r++) {
        if ((*board).cells[r][col] == EMPTY) {
            return r;
        }
    }

    return -1;
}

int is_valid_row(struct Board *board, int row) {
    return row < ROWS;
}

int is_valid_col(struct Board *board, int col) {
    return col < COLS;
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