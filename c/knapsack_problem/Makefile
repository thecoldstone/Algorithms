#Author Nikita

CC=gcc -std=c99
CFLAGS=-Werror -Wall -Wextra -pedantic -g

all: knapsack.c
	$(CC) $(CFLAGS) -o knapsack knapsack.c
	if [ -n "*.dSYM" ]; then rm -rf *.dSYM; fi

clean:
	rm -r knapsack

