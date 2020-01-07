#Author Nikita

CC=gcc -std=c99
CFLAGS=-Werror -Wall -Wextra -pedantic -g

all: shell_sort.c
	$(CC) $(CFLAGS) -o shell_sort shell_sort.c
	if [ -n "*.dSYM" ]; then rm -rf *.dSYM; fi

clean:
	rm -r shell_sort

