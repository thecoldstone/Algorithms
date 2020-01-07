#Author Nikita

CC=gcc -std=c99
CFLAGS=-Werror -Wall -Wextra -pedantic -g

#DATA STRUCTURES
STACK=../stack/stack.c

all: quick_sort.c
	$(CC) $(CFLAGS) -o quick_sort quick_sort.c $(STACK)
	if [ -n "*.dSYM" ]; then rm -rf *.dSYM; fi

clean:
	rm -r quick_sort

