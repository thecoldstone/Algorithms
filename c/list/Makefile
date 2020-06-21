CC=gcc -std=c99
CFLAGS=-Werror -Wall -Wextra -pedantic -g

build: sort.c
	$(CC) $(CFLAGS) -o sort sort.c list.c

clean:
	rm sort
