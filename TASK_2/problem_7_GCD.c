#include <stdio.h>

int HCF(int n1,int n2){

  if (n1 ==0) return n2 ;
  if (n2 ==0) return n1 ;

  if (n1>n2) {
     return HCF (n1%n2,n2);
  }else return HCF ( n1 , n2%n1);

}

int main() {

   int num1 , num2 ;
   printf("Enter two postive integers :");
   scanf("%d%d",&num1 ,&num2);
   printf("The HCF of %d and %d is %d ",num1,num2,HCF(num1,num2));
}
