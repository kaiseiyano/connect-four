#include "player.h"

void init_players(struct Player *players) {
  for (int i = 0; i < 2; i++) {
    players[i].id = i;
  }
}

struct Player get_other_player(struct Player *players,
                               struct Player player_active) {
  return players[!player_active.id];
}
