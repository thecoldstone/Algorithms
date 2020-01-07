#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

/**
 * Recursive way of solving Knapsack Problem
 *
 * Not optimized version
 *
 * @param W
 * @param wt
 * @param val
 * @param n is actual amount of available items
 * @return maximum value that can be put in a knapsack of capacity W
 */
int knapsack_recursive(int W, int wt[], int val[], int n) {

    if(n == 0 || W == 0) {
        return 0;
    } else if (wt[n - 1] > W){ // Weight of items exceed the capacity of knapsack (W)
        return knapsack_recursive(W, wt, val, n - 1);
    } else { // The item could be added
        return max(val[n - 1] + knapsack_recursive(W - wt[n - 1], wt, val, n - 1),
                knapsack_recursive(W, wt, val, n - 1));
    }

}

/**
 * Optimized version of Knapsack Problem with dynamic programming
 *
 * Time complexity is O(nW)
 *
 * @param W capacity
 * @param wt
 * @param val
 * @param n
 * @param print_out flag to print out the table
 * @return maximum value that can be put in a knapsack of capacity W
 */
int knapsack(int W, int wt[], int val[], int n, bool print_out) {

    int i, w;
    int K[n + 1][W + 1];

    //Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++) {
            if(i == 0 || w == 0) // We do not have any thing (item) nor weight
                K[i][w] = 0;
            else if(wt[i - 1] <= w) // We could add the thing (item)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else // We could not add the thing (item) because of weight
                K[i][w] = K[i - 1][w];
        }
    }

    if(print_out == true) {

        printf("Table for Knapsack Problem looks like\n");

        for(i = 0; i<= n; i++) {
            for(w = 0; w <= W; w++) {
                printf("\t%i", K[i][w]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return K[n][W];

}

int main(int argc, char **argv) {
    int val[] = {1, 6, 18, 22, 28};
    int wt[]  = {1, 2, 5, 6, 7};
    int W     = 11;
    int n     = sizeof(val)/ sizeof(val[0]);

    if(argc == 2) {
        if (strcmp(argv[1], "recursive") == 0) {
            printf("Value = %d\n", knapsack_recursive(W, wt, val, n));
        } else {
            fprintf(stderr, "[ERROR] Unsupported operation\n");
            exit(1);
        }
    } else if (argc == 1){
        printf("Value = %d\n", knapsack(W, wt, val, n, true));
    } else {
        fprintf(stderr, "[ERROR] Only two arguments\n");
        exit(2);
    }

    return 0;
}
