#include <stdio.h>


void divisble ( int x , int y);


int main() {

  int num1,divisor;

  printf("enter first integer :");
  scanf("%d", &num1);
  printf("enter second integer :");
  scanf("%d", &divisor);

  divisble ( num1 , divisor);


}

void divisble ( int x , int y){

   if ( x % y ==0){

    printf("%d is divisble by %d",x,y);

  }else{

  printf("%d is not divisble by %d",x,y);
  }


}
