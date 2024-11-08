#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "windows.h"

#include "lib/questions.h"
#include "lib/utility.h"
#include "src/game.h"

int play(int num_questions, int asked[]) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        int index;
        do {
            index = rand() % QUESTION_COUNT;
        } while (asked[index]);

        asked[index] = 1;
        printf("Current Score: %d\n", score);
        printf("You have answered %d out of %d\n\n", i, num_questions);
        int answer = ask_question(&questions[index]);
        score += answer;
        printf("Press any key to continue \n");
        getchar();

        clear_screen();
        show_title();
    }

    return score;
}

int menu(int is_first) {
    int choice;

    if (is_first)
        printf("1. Play\n");
    else
        printf("1. Play Again\n");

    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void get_name(char name[100]) {
    printf("Enter your name: ");
    scanf("%s", name);
}

void game() {
    clear_screen();
    srand(time(NULL));

    int max_score = 0;
    int num_questions = 2;  // Number of questions to ask
    char name[100] = "";
    int asked[QUESTION_COUNT] = {};  // To keep track of asked questions

    while (1) {
        show_title();

        if (strlen(name) == 0) {
            welcome_message();
            get_name(name);
        }
        else {
            printf("Your highest score is: %d\n", max_score);
        }

        int menu_choice = menu(strlen(name));
        if (menu_choice == 2) {
            break;
        }
        else if (menu_choice != 1) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        else if (menu_choice == 1) {
            int score = play(num_questions, asked);
            if (score > max_score) {
                max_score = score;
            }
            printf("Quiz completed! Your score is: %d\n", score);
        }

        clear_screen();
    };

    printf("Quiz completed!\n");
}

int main() {
    game();
    return 0;
}