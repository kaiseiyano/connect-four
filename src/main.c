#include "board/board.h"
#include "player/player.h"
#include "win/win.h"
#include <stdbool.h>
#include <stdio.h>

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

    if (heights[col - 1] >= 7) {
      printf("Column %d is full! Pick another.\n", col);
      continue;
    }

    printf("%d\n", col);
    return col - 1;
  }
}

int main(void) {
  // Initialise board, player 1 and player 2
  struct Player player_active;
  struct Player players[2];
  struct Board board;
  init_players(players);
  player_active = players[0];
  init(&board);
  display(&board);

  while (true) {
    printf("Player %d's turn\n", player_active.id);

    // TODO: Take in input
    int r;
    int c;
    scanf("%d", &r);
    scanf("%d", &c);

    // Update board and display
    update(&board, r, c, player_active.id);
    display(&board);

    // Check win logic
    bool res = validateWin(board.cells, r, c);
    if (res) {
      printf("The winner is %d! Four in a row!", player_active.id);
      break;
    }

    // Switch player
    player_active = get_other_player(players, player_active);
  }

  return 0;
}
