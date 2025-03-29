#include <stdio.h>

int countDigits(int num);
int isArmstrong(int num);
void printArmstrongNumbers(int lower, int upper);


int main() {

  int lower,upper;

  printf("Enter lower limit : ");
  scanf("%d",&lower);
  printf("Enter upper limit : ");
  scanf("%d",&upper);


 printArmstrongNumbers(lower, upper);
    return 0;
}

int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}




int isArmstrong(int num) {
    int originalNum = num, sum = 0;
    int n = countDigits(num);
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, n);
        num /= 10;
    }
    return (sum == originalNum);
}




void printArmstrongNumbers(int lower, int upper) {
    printf("Armstrong numbers between %d to %d are: ", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isArmstrong(i)) {
            printf("%d, ", i);
        }
    }
    printf("\b\b.\n");
}
