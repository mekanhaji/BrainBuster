#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib/questions.h"
#include "lib/utility.h"
#include "windows.h"

int ask_question(const struct Question* q) {
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

int main() {
    srand(time(NULL));
    int max_score = 0;
    int num_questions = 5;  // Number of questions to ask

    printf("%s%sWelcome to the Quiz Game!%s\n", BOLD, GREEN, RESET);
    printf("You will be asked %d random questions.\n\n", num_questions);
    int asked[QUESTION_COUNT] = { 0 };  // To keep track of asked questions
    do
    {
        int score = 0;
        for (int i = 0; i < num_questions; i++) {
            int index;
            do {
                index = rand() % QUESTION_COUNT;
            } while (asked[index]);

            asked[index] = 1;
            printf("Current Score: %d\n", score);
            int answer = ask_question(&questions[index]);
            score += answer;
        }

        if (score > max_score) {
            max_score = score;
        }
        printf("Quiz completed! Your score is: %d\n", score);
        printf("Do you want to play again? (y/n): ");
    } while (getchar() != '\n');


    printf("Quiz completed!\n");

    return 0;
}