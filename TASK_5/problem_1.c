#include <stdio.h>
#include <stdbool.h>
#include <string.h>

 bool stringComp(char *p1, char *p2);

int main() {

    char S1[100], S2[100];

    fgets( S1 ,sizeof(S1),stdin);
    fgets( S2 ,sizeof(S2),stdin);


    if (stringComp(S1, S2)) {
        printf("Strings are identical.\n");
    } else {
        printf("Strings are different.\n");
    }

    return 0;
}

 bool stringComp(char *p1, char *p2) {

    while (*p1 != '\0' && *p2 != '\0') {

        if (*p1 != *p2) {
            return false;
        }
        p1++;
        p2++;
    }

    return true ;
}
