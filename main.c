#include "player/player.h"
#include <stdbool.h>
#include <stdio.h>

/*
    Logic to validate the win (four in a row)
    Take in the x and y coordinates as input, as well as board as a 2D array.
    Before each check, validate that the end coordinates are within the range of
   the board Returns false if no conditions are met
*/
bool validateWin(int board[6][7], int r, int c) {
  int width = 7;
  int height = 6;

  // Check right horizontally
  int i = c;
  while (i < c + 4) {
    if (i == width || board[r][c] != board[r][i]) {
      break;
    }
    i++;
  }
  if (i == c + 4) {
    return true;
  }

  // Check left horizontally
  i = c;
  while (i > c - 4) {
    if (i < 0 || board[r][c] != board[r][i]) {
      break;
    }
    i--;
  }
  if (i == c - 4) {
    return true;
  }

  // Check vertically upwards
  i = r;
  while (i > r - 4) {
    if (i == height || board[r][c] != board[i][c]) {
      break;
    }
    i--;
  }
  if (i == r - 4) {
    return true;
  }

  // Check vertically downwards
  i = r;
  while (i < r + 4) {
    if (i == height || board[r][c] != board[i][c]) {
      break;
    }
    i++;
  }
  if (i == r + 4) {
    return true;
  }

  return false;
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
