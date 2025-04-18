#include <stdio.h>

int main() {
    int R, C ;
    printf("enter number of rows and columns respectively:");
    scanf("%d %d", &R, &C);

    int M1[R][C];
    int M2[R][C];
    int sumMatrix[R][C];

    printf("Enter numbers of matrix1: ");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &M1[i][j]);
        }
    }

    printf("Enter numbers of matrix2: ");
     for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &M2[i][j]);
        }
    }

     for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            sumMatrix[i][j] = M1[i][j] + M2[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
           printf("%d",sumMatrix[i][j]);
        }
        printf("\n");
    }



    return 0;
}
