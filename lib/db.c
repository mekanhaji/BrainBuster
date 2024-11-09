#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#include "db.h"

struct Player load_player_record(const char name[PLAYER_NAME_SIZE]) {
    struct Player player = { .name = "", .best_score = 0 };
    FILE* file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return player;
    }

    while (fscanf(file, "%99[^,],%d\n", player.name, &player.best_score) == 2) {
        if (strcmp(player.name, name) == 0) {
            break;
        }
    }

    fclose(file);
    return player;
}

void save_player_record(const struct Player player) {
    if (strlen(player.name) == 0) {
        return;
    }

    FILE* file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    struct Player players[10];
    int player_count = 0;
    int player_found = false;

    char line[PLAYER_NAME_SIZE + 20];  // Extra space for score and delimiter
    while (player_count < 100 && fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%99[^,],%d\n",
            players[player_count].name,
            &players[player_count].best_score) == 2) {

            if (strcmp(players[player_count].name, player.name) == 0) {
                // Update existing player's score if new score is better
                players[player_count].best_score =
                    player.best_score > players[player_count].best_score ?
                    player.best_score : players[player_count].best_score;
                player_found = true;
            }
            player_count++;
        }
    }

    fclose(file);

    // Add new player if not found and there's space
    if (!player_found && player_count < 100) {
        strncpy(players[player_count].name, player.name, PLAYER_NAME_SIZE - 1);
        players[player_count].name[PLAYER_NAME_SIZE - 1] = '\0';  // Ensure null termination
        players[player_count].best_score = player.best_score;
        player_count++;
    }

    // Write updated records back to file
    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;  // Failed to open file for writing
    }

    for (int i = 0; i < player_count; i++) {
        if (fprintf(file, "%s,%d\n", players[i].name, players[i].best_score) < 0) {
            break;
        }
    }

    fclose(file);
}