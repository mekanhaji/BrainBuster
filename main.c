#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "windows.h"

#include "lib/questions.h"
#include "lib/utility.h"
#include "src/game.h"

void game() {
    clear_screen();
    srand(time(NULL));

    int max_score = 0;
    int num_questions = 5;  // Number of questions to ask

    show_title();
    welcome_message();

    int asked[QUESTION_COUNT] = { 0 };  // To keep track of asked questions
    char play_again;

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
            printf("You have answered %d out of %d\n\n", i, num_questions);
            int answer = ask_question(&questions[index]);
            score += answer;
            printf("Press any key to continue \n");
            getchar();

            clear_screen();
            show_title();
        }

        if (score > max_score) {
            max_score = score;
        }

        printf("Quiz completed! Your score is: %d\n", score);
        printf("Enter `X` to exit or any other key to play again: ");
        play_again = getchar();

        clear_screen();
        show_title();
    } while (play_again != 'x' || play_again != 'X');


    printf("Quiz completed!\n");
}

int main() {
    game();
    return 0;
}