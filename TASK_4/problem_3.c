#include <stdio.h>


void swap (int *ptr1 ,int *ptr2);

int main() {

    int a,b;

    printf("enter two integers:");
    scanf("%d %d", &a,&b);

    printf("before swaping numbers a=%d ,b=%d\n",a,b);
    swap( &a , &b);

    printf("after swaping numbers a=%d ,b=%d\n",a,b);
    return 0;
}


void swap (int *ptr1 ,int *ptr2){

  int temp = *ptr1;
  *ptr1=*ptr2;
  *ptr2=temp;
}
