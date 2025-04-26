#include <stdio.h>

void multiplyMatrix ( int *p1 , int *p2 , int *p3 );


int main() {

    int a[][3]={10,20,30,40,50,60,70,80,90};
    int b[][3]={1,2,3,4,5,6,7,8,9};
    int c[3][3];
    int *p1 = &a[0][0], *p2 = &b[0][0], *p3 = &c[0][0];


    for (int i = 0; i < 9; i++) {
        *(p3 + i) = 0;
    }

    multiplyMatrix(p1, p2, p3);


    printf("Product of matrices is:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", *(p3 + i));
        if ((i + 1) % 3 == 0) printf("\n");
    }
    return 0;
}


void multiplyMatrix ( int *p1 , int *p2 , int *p3 ){

  for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                *(p3 + i * 3 + j) += *(p1 + i * 3 + k) * *(p2 + k * 3 + j);
            }
        }
    }
  }


