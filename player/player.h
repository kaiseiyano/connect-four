#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    int id;
};

void init_players(struct Player *players);
struct Player get_other_player(struct Player *players, struct Player player_active);

#endif
