#include <stdio.h>


// Define one of the operations:
#define SUBTRACTION
// #define ADDITION


#define ADD(a, b) ((a)+(b))

#define SUBTRACT(a, b) ((a)-(b))


int main() {
    int x,y;

    printf("Enter two integers : ");
    scanf("%d %d", &x,&y);

    #ifdef ADDITION
      int sum= ADD(x,y);
      printf("THE SUM OF TWO INTEGERS =%d ",sum);

    #elif defined(SUBTRACTION)
      int difference = SUBTRACT(x, y);
      printf("THE DIFFRENCE OF TWO INTEGERS =%d ",difference);

    #else
        printf("Error: Please define either ADDITION or SUBTRACTION macro.\n");
        return 1;
    #endif



    return 0;
}
