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

void display_board(const struct Board *board, char player)
{
    // board title
    printf("\n");
    printf("=================================\n");
    printf("           CONNECT 4\n");
    printf("=================================\n\n");

    // board colomn
    printf("    1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+\n");

    // board
    for (int i = ROWS - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("  | %c ", symbol(board->cells[i][j]));
        }

        printf("|\n");
        printf("  +---+---+---+---+---+---+---+\n");
    }
    // show current player turn
    printf("\nPlayer %c's turn.\n", player);
}
