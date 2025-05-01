#include <stdio.h>
#include <stdbool.h>
#include <string.h>

 struct Date {

   int day;
   char Month[20];
   int year ;

 };

  bool compare_dates (struct Date *date_1 , struct Date *date_2){

   return (date_1->day==date_2->day)&&
          (strcmp(date_1->Month, date_2->Month) == 0)&&
          (date_1->year==date_2->year);

  }

int main()
{

    struct Date date[2];

    for(int i =0; i<2 ; i++){
        printf("Enter the day of date%d: ",i+1);
        scanf("%d",&date[i].day);
        printf("Enter the month of date%d: ",i+1);
        scanf("%s",&date[i].Month);
        printf("Enter the year of date%d: ",i+1);
        scanf("%d",&date[i].year);
    }

    if ( compare_dates (&date[0],&date[1])){
        printf("Dates are equal");
    }else printf("Dates are not equal");

    return 0;
}
