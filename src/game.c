#include "game.h"

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#include "../lib/questions.h"
#include "../lib/utility.h"

int ask_question(const struct Question* q) {
    printf("Q > %s\n", q->question);
    for (int i = 0; i < q->option_count; i++) {
        printf("%d. %s\n", i + 1, q->options[i]);
    }

    int choice;
    do {
        printf("Enter your choice (1-%d): ", q->option_count);
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > q->option_count) {
            clear_input_buffer();
            printf("Invalid input. Please try again.\n");
        }
        else {
            break;
        }
    } while (1);

    clear_input_buffer();
    int is_correct = 0;
    if (strcmp(q->options[choice - 1], q->answer) == 0) {
        printf("Correct!\n");
        is_correct = 1;
    }
    else {
        printf("Incorrect. The correct answer is: %s\n", q->answer);
    }
    printf("\n");
    return is_correct;
}

void show_title() {
    printf("\n\n");
    printf("\t /$$$$$$$                     /$$                 /$$$$$$$                        /$$                        \n");
    printf("\t| $$__  $$                   |__/                | $$__  $$                      | $$                        \n");
    printf("\t| $$  \\ $$  /$$$$$$  /$$$$$$  /$$ /$$$$$$$       | $$  \\ $$ /$$   /$$  /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$ \n");
    printf("\t| $$$$$$$  /$$__  $$|____  $$| $$| $$__  $$      | $$$$$$$ | $$  | $$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$\n");
    printf("\t| $$__  $$| $$  \\__/ /$$$$$$$| $$| $$  \\ $$      | $$__  $$| $$  | $$|  $$$$$$   | $$    | $$$$$$$$| $$  \\__/\n");
    printf("\t| $$  \\ $$| $$      /$$__  $$| $$| $$  | $$      | $$  \\ $$| $$  | $$ \\____  $$  | $$ /$$| $$_____/| $$      \n");
    printf("\t| $$$$$$$/| $$     |  $$$$$$$| $$| $$  | $$      | $$$$$$$/|  $$$$$$/ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$      \n");
    printf("\t|_______/ |__/      \\_______/|__/|__/  |__/      |_______/  \\______/ |_______/    \\___/   \\_______/|__/      \n");
    printf("\n\n");
}

void welcome_message(int num_questions) {
    printf("%s%sWelcome to the Quiz Game!%s\n", BOLD, GREEN, RESET);
    printf("- You will be asked %d questions.\n\n", num_questions);
    printf("\n");
}

int play(int num_questions, int asked[]) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        int index;
        do {
            index = rand() % QUESTION_COUNT;
        } while (asked[index]);

        asked[index] = 1;
        // TODO: score should be red if zero, green if more then best score, yellow if less then best score
        printf("Current Score: %d\n", score);
        printf("You have answered %d out of %d questions.\n\n", i, num_questions);
        int answer = ask_question(&questions[index]);
        score += answer;
        printf("Press any key to continue \n");
        getchar();

        clear_screen();
        show_title();
    }

    return score;
}

int menu(char name[100]) {
    int choice;

    printf("1. Play\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void get_name(char name[100]) {
    printf("Enter your name: ");
    scanf("%s", name);
}
