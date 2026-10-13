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

        if (heights[col-1] >= 7) {
            printf("Column %d is full! Pick another.\n", col);
            continue;
        }
        
        printf("%d\n", col);
        return col - 1;
    }
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
