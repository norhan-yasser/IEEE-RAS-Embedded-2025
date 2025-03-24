#include <stdio.h>

int main(){

   int num ;
   int smallest;
   int largest ;
  int first = 1;

   while(1){

     scanf ("%d",&num);

      if (num < 0) {
            if (num == -1) {
                break;
            } else {
                printf("Invalid number\n");
                continue;
            }
        }

     if (first) {
            smallest = largest = num;
            first = 0;
        }


    if (num == -1) {
            break;
        }
    if (num > largest) {
            largest = num;
        }
        if (num < smallest) {
            smallest = num;
        }

   }

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);

return 0 ;

}
