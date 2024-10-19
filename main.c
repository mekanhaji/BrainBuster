#include "stdio.h"
#include "stdlib.h"

char* ask_question(char* question) {
    printf("%s\n> ", question);
    char* answer = malloc(100);
    scanf("%s", answer);
    return answer;
}

int main() {
    char* question = ask_question("What is your name?");
    printf("Hello %s", question);
    return 0;
}