#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"

#include "lib/questions.h"
#include "lib/utility.h"
#include "src/game.h"

const int num_questions = 2;  // Number of questions to ask
int max_score = 0;
char name[100] = "";
int asked[QUESTION_COUNT] = {};  // To keep track of asked questions

void welcome_screen() {
    show_title();

    if (strlen(name) == 0) {
        welcome_message();
        get_name(name);
    }
    else {
        printf("Your highest score is: %d\n", max_score);
    }
}

void game_screen() {
    int score = play(num_questions, asked);
    if (score > max_score) {
        max_score = score;
    }
    printf("Quiz completed! Your score is: %d\n", score);
}

int main() {
    clear_screen();
    srand(time(NULL));

    // === welcome Screen === 
    welcome_screen();

    while (1) {
        clear_screen();
        show_title();

        int menu_choice = menu(name);

        // === Game Screen ===
        if (menu_choice == 1) {
            game_screen();
        }

    };
    return 0;
}