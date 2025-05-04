#include <stdio.h>

 typedef unsigned char uint8_t;
 typedef signed char int8_t;
 typedef unsigned short uint16_t;
 typedef signed short int16_t;
 typedef unsigned int uint32_t;
 typedef signed int int32_t;
 typedef unsigned long long uint64_t;
 typedef signed long long int64_t;


int main() {

    printf("Size of unsigned char   (uint8_t):%lu byte\n", sizeof(uint8_t));
    printf("Size of signed char     (int8_t):%lu byte\n", sizeof(int8_t));
    printf("Size of unsigned short  (uint16_t):%lu bytes\n", sizeof(uint16_t));
    printf("Size of signed short    (int16_t):%lu bytes\n", sizeof(int16_t));
    printf("Size of unsigned int    (uint32_t):%lu bytes\n", sizeof(uint32_t));
    printf("Size of signed int      (int32_t):%lu bytes\n", sizeof(int32_t));
    printf("Size of unsigned long long   (uint64_t):%lu bytes\n", sizeof(uint64_t));
    printf("Size of signed long long     (int64_t):%lu bytes\n", sizeof(int64_t));


    return 0;



}
