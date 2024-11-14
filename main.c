#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"

#include "lib/questions.h"
#include "lib/utility.h"
#include "lib/db.h"
#include "src/game.h"

const int num_questions = 5;  // Number of questions to ask
int asked[QUESTION_COUNT] = {};  // To keep track of asked questions
int is_new_player = 0; // To check if the player is new or not
char name[100] = "";
struct Player player;

void welcome_screen() {
    show_title();

    welcome_message(num_questions);
    get_name(name);
}

void game_screen() {
    clear_screen();
    show_title();

    int score = play(num_questions, asked);
    if (score > player.best_score) {
        player.best_score = score;
    }
    printf("Quiz completed! Your score is: %d\n", score);
}

int main() {
    clear_screen();
    srand(time(NULL));

    // Customize Console
    SetConsoleCP(15);
    SetConsoleTitle("Brain Buster");


    // === welcome Screen === 
    welcome_screen();

    player = load_player_record(name);
    if (player.name[0] == '\0') {
        strcpy(player.name, name);
        player.best_score = 0;
        is_new_player = 1;
    }
    else {
        is_new_player = 0;
    }

    while (1) {
        clear_screen();
        show_title();

        if (is_new_player) {
            printf("Welcome %s!\n", name);
        }
        else {
            printf("Welcome back %s!\nYour best score is: %d\n", name, player.best_score);
        }

        int menu_choice = menu(name);
        // Play Game
        if (menu_choice == 1) {
            // === Game Screen ===
            game_screen();
            save_player_record(player);
        }
        // Exit
        else if (menu_choice == 2) {
            save_player_record(player);
            break;
        }

    };
    return 0;
}