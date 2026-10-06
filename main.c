#include <stdio.h>

#include "player/player.h"

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