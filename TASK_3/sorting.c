//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316123706

#include <stdio.h>

int main() {

    int N ;
    int pass;
    int hold;
    scanf("%d" , &N);

    int a[N];

    for ( int i=0 ; i < N; i++){
        scanf ("%d", &a[i] );
    }


    for ( pass = 1; pass < N; pass++ ) {

     for ( int i = 0; i < N - 1; i++ ) {
   if ( a[ i ] > a[ i + 1 ] ) {
    hold = a[ i ];
    a[ i ] = a[ i + 1 ];
    a[ i + 1 ] = hold;
    }
   }
   }

   for ( int i = 0; i < N; i++ ) {
    printf( "%d ", a[ i ] );
 }
    return 0;
}
