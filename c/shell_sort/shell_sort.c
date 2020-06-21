#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    printf("Swapped %d and %d\n", *a, *b);
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shell_sort(int *array, int length) {

    int i, j;
    int gap = length / 2; // prvni krok - polovina delky pole

    while(gap > 0) {
        for(i = gap; i <= length; i++) {
            j = i - gap;
            while((j >= 0) && (array[j] > array[j + gap])) { // bubl. insert
                swap(&array[j], &(array[j + gap]));
                j = j - gap; // snizeni indexu o krok
//                printf("%d ", j);
            }
        }
//        printf("%d ", gap);
        gap = gap / 2; // puleni kroku
    }

    printf("\n");

}

int main() {
    int array[] = {2, 9, 1, 3, 8};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Before sorting: ");
    for(int i = 0; i < length; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    shell_sort(array, length-1);
    printf("After sorting: ");
    for(int i = 0; i < length; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}
