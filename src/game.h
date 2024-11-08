#ifndef GAME_H
#define GAME_H

#include "stdio.h"
#include "string.h"

#include "../lib/questions.h"
#include "../lib/utility.h"

int ask_question(const struct Question* q);

void show_title();

void welcome_message();

#endif // GAME_H