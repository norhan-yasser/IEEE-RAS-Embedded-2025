#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){

   char word[100] ;
   bool state ;

   scanf("%s",word);

   for (int i=0 ; i<strlen(word) ; i++ ) {

    if ( word[i]== word[strlen(word)-i-1]){

        state=true;
    } else {

     state = false ;
     break;

    }

   }

   if (state){

    printf("The word '%s' is a palindrome.",word);
   }else {

    printf("The word '%s' is not a palindrome",word);
   }
return 0 ;

}
