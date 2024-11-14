#ifndef GAME_H
#define GAME_H

#include "stdio.h"
#include "string.h"

#include "../lib/questions.h"
#include "../lib/utility.h"

int ask_question(const struct Question* q);

void show_title();

void welcome_message(int num_questions);

int play(int num_questions, int asked[]);

int menu(char name[100]);

void get_name(char name[100]);
#endif // GAME_H