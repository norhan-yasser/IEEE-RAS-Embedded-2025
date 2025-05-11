#include <stdio.h>

#define ASCENDING

int x, y, temp;
int n;


/*If the replacement text for a macro or symbolic constant is longer than the remainder of the line, a backslash (\) must be placed at
the end of the line, indicating that the replacement text continues on the next line.*/


#define SWAP(a, b) do { temp = *a; *a = *b; *b = temp; } while(0)


#define ASCENDING_SORT(ptr) \
    for (x = 0; x < n - 1; x++) { \
        for (y = 0; y < n - x - 1; y++) { \
            if (*(ptr + y) > *(ptr + y + 1)) { \
                SWAP((ptr + y), (ptr + y + 1)); \
            } \
        } \
    }

#define DESCENDING_SORT(ptr) \
    for (x = 0; x < n - 1; x++) { \
        for (y = 0; y < n - x - 1; y++) { \
            if (*(ptr + y) < *(ptr + y + 1)) { \
                SWAP((ptr + y), (ptr + y + 1)); \
            } \
        } \
    }

int main() {
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    #ifdef ASCENDING
    ASCENDING_SORT(arr);

      printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
     #elif defined(DESCENDING)

        DESCENDING_SORT(arr);
        printf("Sorted array in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    #else

        printf("Error: Please define either ASCENDING or DESCENDING macro.\n");
        return 1;
    #endif



    return 0;
}
