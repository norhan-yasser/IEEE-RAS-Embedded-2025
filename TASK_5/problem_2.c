#include <stdio.h>
#include <string.h>

 void stringCopy(char *p1, char *p2);

int main() {

    char S1[100], S2[100];

    fgets( S1 ,sizeof(S1),stdin);

    stringCopy(S1, S2);


    printf("original string : %s",S1);
    printf("copied string : %s",S2);

    return 0;
}
void stringCopy(char *p1, char *p2) {
    while (*p1 != '\0') {
        *p2 = *p1; // copy from p1 to p2
        p1++;
        p2++;
    }
    *p2 = '\0'; // don't forget to end the copied string
}
