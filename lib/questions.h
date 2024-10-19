#ifndef QUESTIONS_H
#define QUESTIONS_H

#define MAX_OPTIONS 5
#define MAX_STRING_LENGTH 200
#define QUESTION_COUNT 16

struct Question {
    char question[MAX_STRING_LENGTH];
    char answer[MAX_STRING_LENGTH];
    char options[MAX_OPTIONS][MAX_STRING_LENGTH];
    int option_count;
};

extern struct Question questions[QUESTION_COUNT];

#endif // QUESTIONS_H