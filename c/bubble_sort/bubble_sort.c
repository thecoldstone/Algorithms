#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *array, int length) {
    
    bool go = true;

    while(length > 0 && go) {

        go = false;

        for(int i = 0; i < length; i++) {
            if(array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                go = true;
            }
        }

        length--;
    }

}

int main() {
    int array[] = {2, 9, 1, 3, 10, 8, 0, -1, -100};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Before sorting: ");
    for(int i = 0; i < length; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    printf("After sorting: ");
    bubble_sort(array, length);
    for(int i = 0; i < length; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}