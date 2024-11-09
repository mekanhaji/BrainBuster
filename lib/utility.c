#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}