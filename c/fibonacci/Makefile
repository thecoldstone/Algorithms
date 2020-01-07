#Author Nikita

CC=gcc -std=c99
CFLAGS=-Werror -Wall -Wextra -pedantic -g

all: fibonacci.c
	$(CC) $(CFLAGS) -o fibonacci fibonacci.c
	if [ -n "*.dSYM" ]; then rm -rf *.dSYM; fi

clean:
	rm -r fibonacci

