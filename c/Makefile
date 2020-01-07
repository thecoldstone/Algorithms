#Author Nikita

CC=gcc -std=c99
CFLAGS=-Werror -Wall -Wextra -pedantic -g

#DATA STRUCTURES
STACK=stack/stack.c

fibonacc: fibonacci/fibonacci.c
	$(CC) $(CFLAGS) fibonacci/fibonacci.c -o fibonacci/fibonacci
	if [ -n "*.dSYM" ]; then rm -rf *.dSYM; fi

quick: quick_sort/quick_sort.c
	$(CC) $(CFLAGS) -o quick_sort quick_sort/quick_sort.c $(STACK)

clean_quick:
	rm -r quick_sort/quick_sort

clean:
	rm -rf *.o
	rm -r fibonacci
