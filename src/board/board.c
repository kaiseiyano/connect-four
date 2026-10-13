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
  if (!is_valid_col(col)) {
    return 0;
  }

  int row = get_open_row_from_col(board, col);

  if (row == -1) {
    return 0;
  }

  (*board).cells[row][col] = piece;

  return 1;
}

int get_open_row_from_col(const struct Board *board, int col) {
  for (int r = 0; r < ROWS; r++) {
    if ((*board).cells[r][col] == EMPTY) {
      return r;
    }
  }

  return -1;
}

int is_valid_row(int row) { return row >=0 && row < ROWS; }

int is_valid_col(int col) { return col >= 0 && col < COLS; }

char _get_symbol(int piece) {
  if (piece == PIECE_x) {
    return 'X';
  } else if (piece == PIECE_o) {
    return 'O';
  } else {
    return ' ';
  }
}

/*
    Logic to validate the win (four in a row)
    A 2D array is used to store the direction vectors. A loop runs through the
   array, and within that there are another two loops for the positive and
   negative direction. The loops go three places in the vector direction, and if
   it is the same as the starting point then count is incremented. If count >= 4
   then it means that the game has been won.
   1: Game won
   0: Game continues
*/
int validateWin(const struct Board *board, int c) {

  // Get rows
  int open = get_open_row_from_col(board, c);
  int r;
  if (open == -1) {
    r = ROWS - 1;
  } else {
    r = open - 1;
  }

  // No piece in the cell
  if (board->cells[r][c] == EMPTY) {
    return 0;
  }

  // Direction vectors
  int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

  for (int i = 0; i < 4; i++) {
    int x = directions[i][0];
    int y = directions[i][1];
    int count = 1;

    // Check positive direction
    for (int j = 1; j < 4; j++) {
      int dx = x * j + r;
      int dy = y * j + c;
      if (dx >= 0 && dx < ROWS && dy >= 0 && dy < COLS &&
          board->cells[dx][dy] == board->cells[r][c]) {
        count++;
      } else {
        break;
      }
    }

    // Check negative direction
    for (int k = 1; k < 4; k++) {
      int dx = r - x * k;
      int dy = c - y * k;
      if (dx >= 0 && dx < ROWS && dy >= 0 && dy < COLS &&
          board->cells[dx][dy] == board->cells[r][c]) {
        count++;
      } else {
        break;
      }
    }

    if (count >= 4) {
      return 1;
    }
  }

  return 0;
}
