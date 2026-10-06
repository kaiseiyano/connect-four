#include <stdio.h>

struct Player {
    int id;
};

void init_players(struct Player *players) {
    for (int i = 0; i < 2; i++) {
        players[i].id = i;
    }
}

struct Player get_other_player(struct Player *players, struct Player player_active) {
    return players[!player_active.id];
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