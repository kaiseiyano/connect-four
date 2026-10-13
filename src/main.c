#include "board/board.h"
#include "player/player.h"
#include "win/win.h"
#include <stdbool.h>
#include <stdio.h>

int get_input_col(struct Board *board) {
    char buffer[32];

    while (1) {
        printf("Column (1 - %d): ", COLS);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return -1;
        }

        int col;

        if (sscanf(buffer, "%d", &col) != 1) {
            printf("> Input must be an int.\n");
            continue;
        }

        col -= 1;

        if (!is_valid_col(board, col)) {
            printf("> Input int is invalid.\n");
            continue;
        }

        if (get_open_row_from_col(board, col) == -1) {
            printf("> Input column is full.\n");
            continue;
        }

        return col;
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
    int test = get_input_col(&board);
    int r;
    int c;
    scanf("%d", &r);
    scanf("%d", &c);

    // Update board and display
    update(&board, r, c, player_active.id);
    display(&board);

    // Check win logic
    bool res = validateWin(&board, r, c);
    if (res) {
      printf("The winner is %d! Four in a row!", player_active.id);
      break;
    }

    // Switch player
    player_active = get_other_player(players, player_active);
  }

  return 0;
}
