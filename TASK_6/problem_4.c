
#include <stdio.h>

// Alignment requirements
// (typical 64 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
typedef struct structa_tag {
    char c;
    short int s;
} structa_t;

// structure B
typedef struct structb_tag {
    short int s; //2byte
    char c; //1 byte
    int i; //4byte
} structb_t;



int main()
{
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t)); //output:4
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t)); //output:8

    return 0;
}


/* Why does the compiler add 1 byte of padding after a char?
*The reason lies in data alignment — a rule that certain data
*1types must start at memory addresses that are multiples of their alignment requirement.
* This is done for performance: aligned memory access is faster and sometimes even required by the CPU.
*/
