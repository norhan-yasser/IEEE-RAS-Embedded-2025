//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316106749

#include <stdio.h>

int main() {

    int N ;
    int X;

    scanf("%d" , &N);

    int array[N];

    for ( int i=0 ; i < N; i++){
        scanf ("%d", &array[i] );
    }

    scanf("%d",&X);

    for ( int i =0; i < N; i++){
        if(array[i]==X){
        printf("%d",i);
         return 0;
        }
    }


    printf("-1\n");
    return 0;
}
