#include <stdio.h>
#include "math.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0.0;
    }
    return (float)a / b;
}

int power(int base, int exp)
    {
      if(exp < 0)
        return -1;

        int result = 1;
        while (exp)
        {
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }

        return result;
    }

int add_pair(Pair p) {
    return add(p.a, p.b);
}

int subtract_pair(Pair p) {
    return subtract(p.a, p.b);
}

int multiply_pair(Pair p) {
    return multiply(p.a, p.b);
}

float divide_pair(Pair p) {
    return divide(p.a, p.b);
}


 int power_pair(Pair p){
        return  power(p.a, p.b);
    }
