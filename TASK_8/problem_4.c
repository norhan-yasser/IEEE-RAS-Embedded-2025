#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2, *ptr3, *ptr4;
    int i;

    int size1 = 5, size2 = 5;

    // Allocate memory using malloc
    ptr1 = (int *)malloc(size1 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation with malloc failed!\n");
    } else {
        printf("Memory allocated using malloc:\n");
        for (i = 0; i < size1; i++) {

            printf("ptr1[%d] = %d\n", i, ptr1[i]); //garbage values
        }
    }

    // Allocate memory using calloc
    ptr2 = (int *)calloc(size2, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation with calloc failed!\n");
    } else {
        printf("\nMemory allocated using calloc (initialized to 0):\n");
        for (i = 0; i < size2; i++) {

            printf("ptr2[%d] = %d\n", i, ptr2[i]); // intialized to zeros (calloc)
        }
    }

    // Allocate memory using malloc for ptr3
    ptr3 = (int *)malloc(3 * sizeof(int));
    if (ptr3 == NULL) {
        printf("Memory allocation for ptr3 failed!\n");
    } else {
        for (i = 0; i < 3; i++) {
            ptr3[i] = 100 + i;
        }

        printf("\nMemory allocated using malloc for ptr3:\n");
        for (i = 0; i < 3; i++) {
            printf("ptr3[%d] = %d\n", i, ptr3[i]);
        }

        // Now free ptr3
        free(ptr3);
        printf("\nMemory block ptr3 has been freed.\n");
    }

    // Allocate a new, larger memory block
    ptr4 = (int *)malloc(10 * sizeof(int));  // Bigger block
    if (ptr4 == NULL) {
        printf("Memory allocation for ptr4 (large block) failed!\n");
    } else {
        for (i = 0; i < 10; i++) {
            ptr4[i] = 1000 + i;
        }

        printf("\nMemory allocated for ptr4 (larger block after freeing ptr3):\n");
        for (i = 0; i < 10; i++) {
            printf("ptr4[%d] = %d\n", i, ptr4[i]);
        }
    }

    // Free remaining allocated memory
    free(ptr1);
    free(ptr2);
    free(ptr4);

    return 0;
}
