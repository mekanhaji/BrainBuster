#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib/questions.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void ask_question(const struct Question* q) {
    printf("%s\n", q->question);
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

    if (strcmp(q->options[choice - 1], q->answer) == 0) {
        printf("Correct!\n");
    }
    else {
        printf("Incorrect. The correct answer is: %s\n", q->answer);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int score = 0;
    int num_questions = 5;  // Number of questions to ask

    printf("Welcome to the Quiz Game!\n");
    printf("You will be asked %d random questions.\n\n", num_questions);

    int asked[QUESTION_COUNT] = { 0 };  // To keep track of asked questions

    for (int i = 0; i < num_questions; i++) {
        int index;
        do {
            index = rand() % QUESTION_COUNT;
        } while (asked[index]);

        asked[index] = 1;
        ask_question(&questions[index]);
    }

    printf("Quiz completed!\n");

    return 0;
}