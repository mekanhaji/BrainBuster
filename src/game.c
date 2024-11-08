#include "game.h"

#include "stdio.h"
#include "string.h"

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

void welcome_message() {
    printf("%s%sWelcome to the Quiz Game!%s\n", BOLD, GREEN, RESET);
    printf("You will be asked 5 random questions.\n\n");
}
