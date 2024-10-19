main: main.c ./lib/questions.c ./lib/questions.h ./lib/utility.c ./lib/utility.h
	mkdir -p build
	gcc -o build/BranBuster main.c ./lib/questions.c ./lib/utility.c

prod: main.c ./lib/questions.c ./lib/questions.h ./lib/utility.c ./lib/utility.h
	mkdir -p build
	gcc -Wall -Wextra -Werror -o build/BranBuster main.c ./lib/questions.c ./lib/utility.c

run: main
	./build/main

clean:
	rm -f *.exe *.o build/*