CC = clang
CFLAGS = -Wall -Werror -Wextra -pedantic -O2
LFLAGS = -lm

all: meow

meow.o: meow.c
	$(CC) $(CFLAGS) -c meow.c

meow: meow.o
	$(CC) $(LFLAGS) meow.o -o meow

clean:
	rm -f meow meow.o

format:
	clang-format -i -style=file *.[ch]

.PHONY: all clean
