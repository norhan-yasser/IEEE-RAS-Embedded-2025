#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2, *ptr3;
    int i;

    int size1 = 5, size2 = 5;

    // Allocate memory using malloc
    ptr1 = (int *)malloc(size1 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation with malloc failed!\n");
    } else {
        printf("Memory allocated using malloc:\n");
        for (i = 0; i < size1; i++) {
            printf("ptr1[%d] = %d\n", i, ptr1[i]);  // garbage values
        }
    }

    // Allocate memory using calloc
    ptr2 = (int *)calloc(size2, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation with calloc failed!\n");
    } else {
        printf("\nMemory allocated using calloc (initialized to 0):\n");
        for (i = 0; i < size2; i++) {

            printf("ptr2[%d] = %d\n", i, ptr2[i]); //intialized to zeros (calloc)
        }
    }

    // Allocate memory using malloc, then reallocate using realloc
    ptr3 = (int *)malloc(3 * sizeof(int));
    if (ptr3 == NULL) {
        printf("Initial malloc for ptr3 failed!\n");
    } else {
        for (i = 0; i < 3; i++) {
            ptr3[i] = 100 + i;
        }

        // Realloc to a larger size
        ptr3 = (int *)realloc(ptr3, 6 * sizeof(int));
        if (ptr3 == NULL) {
            printf("Reallocation failed!\n");
        } else {
            // Assign values to new elements
            for (i = 3; i < 6; i++) {
                ptr3[i] = 200 + i;
            }

            printf("\nMemory allocated using malloc and reallocated using realloc:\n");
            for (i = 0; i < 6; i++) {
                printf("ptr3[%d] = %d\n", i, ptr3[i]);
            }
        }
    }

    // Free all allocated memory
    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}
