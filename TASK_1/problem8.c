#include <stdio.h>



int main(){

    int N ;
    int sum ;
    scanf( "%d" , &N);

    for (int i =1 ; i<N ; i++){

        if (N%i==0){
            sum+=i;
        }
    }

   if (sum == N){
     printf("%d is a perfect number",N);

   }else {

   printf("%d is not a perfect number",N);
   }


    return 0 ;

}
