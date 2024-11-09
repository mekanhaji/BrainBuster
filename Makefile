APP_NAME = BranBuster
CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUILD_DIR = build
TARGET = $(BUILD_DIR)/$(APP_NAME)
HEADERS = ./lib/questions.h ./lib/utility.h ./src/game.h ./lib/db.h
SRC = ./src/game.c ./lib/questions.c ./lib/utility.c ./lib/db.c

main: main.c $(HEADERS)
	mkdir -p $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/$(APP_NAME) main.c $(SRC)
	./$(BUILD_DIR)/$(APP_NAME)

prod: main.c $(HEADERS)
	mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) -o $(BUILD_DIR)/$(APP_NAME) main.c $(SRC)

run:
	./$(BUILD_DIR)/$(APP_NAME)

clean:
	rm -f *.exe *.o $(BUILD_DIR)/*