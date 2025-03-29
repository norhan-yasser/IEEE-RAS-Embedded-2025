//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/313046578

#include <stdio.h>
#include <stdbool.h>


int fun (int N){

   if (N==0){

    return;

   } else {

    fun(N-1);
    printf("%d\n",N);

   }

}

int main() {

   int N ;
   scanf("%d",&N);

   fun(N);
   return 0;
}
