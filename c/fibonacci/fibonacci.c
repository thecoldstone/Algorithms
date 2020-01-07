#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RED_COLOR "\033[0;31m"
#define COLOR_END "\033[0m"
//#define DEBUG

void usage() {
    fprintf(stdout, "[USAGE] ./fibonacci [N] [method[method]...]\n");
}

//Method: (Recursive)
//Time complexity: O(2^n)
unsigned long int fibonacci_recursive(unsigned long int n) {

    if (n == 0) {
        return 0;
    } else {
        if (n == 1) {
            return 1;
        } else {
            return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
        }
    }

}

//https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
//Method: (Dynamic Programming)
unsigned long int fibonacci_iterative(unsigned long int n) {

    unsigned long int fib_table[n + 2];
    fib_table[0] = 0;
    fib_table[1] = 1;

    for(unsigned long int i = 2; i <= n; i++) {
        fib_table[i] = fib_table[i - 1] + fib_table[i - 2];
    }

    return fib_table[n];
}

//https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
//Method: (Space Optimized)
//Store the previous two numbers
//Here we use memoization
//Time complexity: O(n)
unsigned long int fib_optimized(unsigned long int n) {
    unsigned  long int a = 0, b = 1, c, i;

    if(n == 0) {
        return a;
    }

    for(i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

//https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
//Method: (Formula)
//Fn = {[(√5 + 1)/2] ^ n} / √5
//Time complexity: O(1)
unsigned long int fib_optimized_to_1(unsigned long int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

int main(int argc, char **argv) {

    if(argc <= 1) {
        fprintf(stdout, "Not enough arguments.\n");
        usage();
        return 1;
    }

    unsigned long int result;
    int n = atoi(argv[1]);

    if(argc == 2) {
        result = fib_optimized((unsigned long int)n);
        printf("Result: %lu\n", result);
    } else if (argc == 3) {

        if(strcmp(argv[2], "recursive") == 0) {
            result = fibonacci_recursive((unsigned long int)n);
            printf("Result: %lu\n", result);
        } else if (strcmp(argv[2], "iterative") == 0) {
            result = fibonacci_iterative((unsigned long int)n);
            printf("Result: %lu\n", result);
        } else if (strcmp(argv[2], "optimized") == 0) {
            result = fib_optimized((unsigned long int)n);
            printf("Result: %lu\n", result);
        } else {
            fprintf(stderr, "%s[Error]%s \"%s\" operation does not exist\n", RED_COLOR, COLOR_END, argv[2]);
            usage();
            return 1;
        }

        /* Test */
        #ifdef DEBUG
            fprintf(stdout,"Size of table: %lu\n", sizeof(fib_table)/sizeof(fib_table[0]));
        #endif

    } else if (argc == 4) {
        if(strcmp(argv[2], "optimized") == 0) {
            if(strcmp(argv[3], "1") == 0){
                result = fib_optimized_to_1((unsigned long int)n);
                printf("Result: %lu\n", result);
            } else {
                fprintf(stderr, "%s[Error]%s \"%s\" operation does not exist\n", RED_COLOR, COLOR_END, argv[3]);
                usage();
                return 1;
            }
        } else {
        fprintf(stderr, "%s[Error]%s \"%s\" operation does not exist\n", RED_COLOR, COLOR_END, argv[2]);
        usage();
        return 1;
        }

    } else {
        usage();
        return 1;
    }

    return 0;
}
