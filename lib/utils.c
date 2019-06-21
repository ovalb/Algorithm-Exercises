#include <stdio.h>
#include "utils.h"

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void print_array(int *array, int len) {
    printf("Array: ");

    if (len == 0) {
        printf("is empty\n");
        return;
    }

    int i;
    for (i=0; i < len; i++) {
        if (i > 0) printf(", "); 
        printf("%d", array[i]);
    }
   printf("\n"); 
}
