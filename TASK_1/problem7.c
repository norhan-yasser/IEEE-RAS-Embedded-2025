#include <stdio.h>
#include <stdbool.h>

int main(){

   int num;
   int firstDigit;
   int secondDigit;
   int sum;
   bool isPrime = true;

   printf("Enter postive integer :");
   scanf("%d",&num);

   if ( num < 0){

    printf("invalid number");

   }else {


      firstDigit = num %10;
      num/=10;
      secondDigit =num %10;

      sum = firstDigit+secondDigit;


     for (int i = 2; i <= sum / 2; ++i) {

    if (sum % i == 0) {
      isPrime = false;
      break;
        }
       }

    }


   printf("Sum of digits:%d + %d = %d \n",secondDigit,firstDigit,sum);
    if (isPrime){
      printf("The sum of digits (%d) is a prime number.",sum);
    }else {
     printf("The sum of digits (%d) is not a prime number.",sum);
    }
}
