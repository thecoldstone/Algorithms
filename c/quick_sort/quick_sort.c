#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../stack/stack.h" // for non recursive quick sort

void swap(int *a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int *array, int length ,bool sorted) {

    if(sorted == false) {
        printf("Unsorted array: ");
    } else {
        printf("Sorted array: ");
    }

    for(int i = 0; i < length; i++) {
        printf("%i ", array[i]);
    }

    printf("\n");

}


void partition(int *array, int left, int right, int *i, int *j) {

    int PM;
    *i = left;
    *j = right;
    PM = array[(*i + *j) / 2]; // Set the pseudo median
    printf("(%i, %i)\n", left, right);
    printf("PM = %i\n", PM);

    do {
        while(array[*i] < PM) (*i)++; // hledani prvniho zleva
        while(PM < array[*j]) (*j)--; // hledani prvniho zprava

        if(*i <= *j) {
            printf("Swapped items: %i and %i\n", array[*i], array[*j]);
            swap(&array[*i], &array[*j]);
            (*i)++;
            (*j)--;
        }

    } while(*i <= *j);

}

void quick_sort(int *array, int left, int right) {

    int i, j;
    tStack* S;

    S = (tStack*) malloc(sizeof(tStack));

    if(S == NULL) {
        fprintf(stderr, "[INTERNAL ERROR] Failed allocation\n");
        exit(-99);
    }

    stackInit(S);
    stackPush(S, left);
    stackPush(S, right);

    while(!stackEmpty(S)) {
        right = stackTop(S); stackPop(S);
        left  = stackTop(S); stackPop(S);

        while(left < right) {
            partition(array, left, right, &i, &j);
            stackPush(S, i);
            stackPush(S, right);
            right = j;
        }
    }

}

void quick_sort_recursive(int *array, int left, int right, int len) {

    int i, j;

    printf("\n");

    partition(array, left, right, &i, &j);

    if(true) {
        printf("i = %i j = %i\nleft = %i right = %i\n", i, j, left, right);
        print_array(array, len, false);
    }

    if(left < j) quick_sort_recursive(array, left, j, len); // Recursion to the left
    if(i < right) quick_sort_recursive(array, i, right, len); // Recursion to the right

}

int main(int argc, char **argv) {

    int array[] = {6, 2, 4, 10, 1, 7, 3, 5, 9, 11, 8};
    int length = sizeof(array) / sizeof(array[0]); // length = right, left = 0


    if(argc == 2) {
        if(strcmp(argv[1], "recursive") == 0) {
            print_array(array, length, false);
            quick_sort_recursive(array, 0, length - 1, length);
            print_array(array, length, true);
        } else {
            fprintf(stderr, "[ERROR] Not supported operation\n");
            exit(-2);
        }
    } else if (argc == 1) {
        print_array(array, length, false);
        quick_sort(array, 0, length);
        print_array(array, length, true);
    } else {
        fprintf(stderr, "[ERROR] Not supported operation\n");
        exit(-2);
    }

    return 0;
}
