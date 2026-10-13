#include "win.h"

/*
    Logic to validate the win (four in a row)
    A 2D array is used to store the direction vectors. A loop runs through the
   array, and within that there are another two loops for the positive and
   negative direction. The loops go three places in the vector direction, and if
   it is the same as the starting point then count is incremented. If count >= 4
   then it means that the game has been won.
*/
bool validateWin(int board[6][7], int r, int c) {
  int width = 7;
  int height = 6;

  // Guard against 0 value
  if (board[r][c] == 0) {
    return false;
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
      if (dx >= 0 && dx < height && dy >= 0 && dy < width &&
          board[dx][dy] == board[r][c]) {
        count++;
      } else {
        break;
      }
    }

    // Check negative direction
    for (int k = 1; k < 4; k++) {
      int dx = r - x * k;
      int dy = c - y * k;
      if (dx >= 0 && dx < height && dy >= 0 && dy < width &&
          board[dx][dy] == board[r][c]) {
        count++;
      } else {
        break;
      }
    }

    if (count >= 4) {
      return true;
    }
  }

  return false;
}
