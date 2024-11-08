APP_NAME = BranBuster
CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUILD_DIR = build
TARGET = $(BUILD_DIR)/$(APP_NAME)
HEADERS = ./lib/questions.h ./lib/utility.h ./src/game.h
SRC = ./src/game.c ./lib/questions.c ./lib/utility.c

main: main.c $(HEADERS)
	mkdir -p $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/$(APP_NAME) main.c $(SRC)

prod: main.c $(HEADERS)
	mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) -o $(BUILD_DIR)/$(APP_NAME) main.c $(SRC)

run: main
	./$(BUILD_DIR)/$(APP_NAME)

clean:
	rm -f *.exe *.o $(BUILD_DIR)/*