#ifndef DB_H
#define DB_H

#define FILE_NAME "players.csv"
#define PLAYER_NAME_SIZE 100

struct Player {
    char name[PLAYER_NAME_SIZE];
    int best_score;
};

void save_player_record(const struct Player player);
struct Player load_player_record(const char name[PLAYER_NAME_SIZE]);

#endif // DB_H