#include "board/board.h"
#include "player/player.h"
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

        if (!is_valid_col(col)) {
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

  while (is_full(&board) == 0) {
    printf("Player %d's turn\n", player_active.id + 1);

    // Take in input
    int col = get_input_col(&board);

    if (col == -1) {
        printf("Input closed. Ending the game.\n");

        return 0;
    }

    // Update board and display
    update(&board, col, player_active.id + 1);
    display(&board);

    // Check win logic
    int res = validate_win(&board, col);
    if (res == 1) {
      printf("The winner is %d! Four in a row!\n", player_active.id + 1);
      return 0;
    }

    // Switch player
    player_active = get_other_player(players, player_active);
  }

  if (is_full(&board) == 1){
    printf("Draw! No more pieces to place\n");
  }

  return 0;
}
