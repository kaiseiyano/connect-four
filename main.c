#include "player/player.h"
#include "win/win.h"
#include <stdbool.h>
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

int getInput(const int heights[7]) {
    char buffer[32];
    int col;

    while (1) {
        printf("Choose a column (1-7): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return -1; 
        }

        if (sscanf(buffer, "%d", &col) != 1) {
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        if (col < 1 || col > 7) {
            printf("Out of range! Must be between 1 and 7.\n");
            continue;
        }

        if (heights[col-1] >= 7) {
            printf("Column %d is full! Pick another.\n", col);
            continue;
        }
        
        printf("%d\n", col);
        return col - 1;
    }
}

void display_board(char Board[6][7], char player)
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
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("  | %c ", Board[i][j]);
        }

        printf("|\n");
        printf("  +---+---+---+---+---+---+---+\n");
    }
    // show current player turn
    printf("\nPlayer %c's turn.\n", player);
}

int main(void) {
  struct Player player_active;
  struct Player players[2];

  init_players(players);

  player_active = players[0];

  int TEMP_i = 0;

  while (TEMP_i++ < 10) {
    printf("Player %d's turn.\n", player_active.id);

    player_active = get_other_player(players, player_active);
  }

  return 0;
}
