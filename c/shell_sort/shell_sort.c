#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shell_sort(int *array, int length) {

    int i, j;
    int step = length / 2;

    while(step > 0) {
        for(i = step; i <= length; i++) {
            j = i - step;
            while((j >= 0) && (array[j] > array[j + step])) {
                swap(&array[j], &(array[j + step]));
                j = j - step;
            }
        }
        step = step / 2;
    }

}

int main() {
    int array[] = {2, 9, 1, 3, 10, 8, 0, -1, -100, 10, 3, 3, -101, 11};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Before sorting: ");
    for(int i = 0; i < length; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    printf("After sorting: ");
    shell_sort(array, length);
    for(int i = 0; i < length; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}
