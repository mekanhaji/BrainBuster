main: main.c ./lib/questions.c ./lib/questions.h
	mkdir -p build
	gcc -o build/main main.c ./lib/questions.c

build: main.c ./lib/questions.c ./lib/questions.h
	mkdir -p build
	gcc -Wall -Wextra -Werror -o build/main main.c ./lib/questions.c

run: main
	./build/main

clean:
	rm -f *.exe *.o build/*