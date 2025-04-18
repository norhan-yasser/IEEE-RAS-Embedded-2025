//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316112944

#include <stdio.h>

int main() {

    int N ;

    scanf("%d" , &N);

    int array[N];

    for ( int i=0 ; i < N; i++){
        scanf ("%d", &array[i] );
    }

    int min_value = array[0];
    int min_index = 0;

    for (int i = 1; i < N; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
            min_index = i;
        }
    }

    // Output: value and 1-based index
    printf("%d %d\n", min_value, min_index + 1);

    return 0;
}
