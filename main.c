#include <stdio.h>

#define ROWS 6
#define COLS 7
#define EMPTY 0
#define PIECE_x 1
#define PIECE_o 2

int board[ROWS][COLS];
int height [COLS];

char symbol (int piece){
    if (piece == PIECE_x) {
        return 'X';
    } else if (piece == PIECE_o) {
        return 'O';
    } else {
        return ' ';
    }
}

void initial(void) {
    for (int c=0; c<COLS; c++) {
        height[c] = 0;
        for (int r=0; r<ROWS; r++) {
            board[r][c] = EMPTY;
        }
    }
}

void display() {
    printf("\n");
    for (int r = ROWS-1; r>=0; r--) {
        for (int c=0; c<COLS; c++) {
            if (board[r][c] == EMPTY) {
                printf("□ "); 
            } else {
                printf("%c ", board[r][c]);
            }
        }
        printf("\n");
    }
}
int update(int x, int y, int piece) {
    if (x<0 || x>=COLS || y<0 || y>=ROWS) {
        return 0;
    }
    if (board[y][x] != EMPTY) {
        return 0;
    }
    if (y>0 && board[y-1][x] == EMPTY) {
        return 0;
    }
    board[y][x] = piece;
    return 1;
}